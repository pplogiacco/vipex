/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

/*
 *
#include "vrms.h"

enum { DomElementRole = Qt::UserRole + 1 };

Q_DECLARE_METATYPE(QDomElement)

static inline QString titleElement() { return QStringLiteral("title"); }
static inline QString deviceElement() { return QStringLiteral("device"); }

static inline QString moduleLocElement() { return QStringLiteral("loc"); }
static inline QString moduleSemElement() { return QStringLiteral("sem"); }
static inline QString moduleLcnElement() { return QStringLiteral("lcn"); }

static inline QString idxAttribute() { return QStringLiteral("idx"); }
static inline QString ioAttribute() { return QStringLiteral("io"); }
static inline QString addrAttribute() { return QStringLiteral("addr"); }
static inline QString versionAttribute() { return QStringLiteral("version"); }
static inline QString foldedAttribute() { return QStringLiteral("folded"); }



VrmsTree::VrmsTree(QWidget *parent)
    : QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Device") << tr("Module")<< tr("Port");

    header()->setSectionResizeMode(QHeaderView::Stretch);

    setHeaderLabels(labels);

    deviceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
                         QIcon::Normal, QIcon::Off);

    moduleLocIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                         QIcon::Normal, QIcon::On);
    moduleSemIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                         QIcon::Normal, QIcon::On);
    moduleLcnIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                         QIcon::Normal, QIcon::On);
    portIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
}

#if !defined(QT_NO_CONTEXTMENU) && !defined(QT_NO_CLIPBOARD)
void VrmsTree::contextMenuEvent(QContextMenuEvent *event)
{
    const QTreeWidgetItem *item = itemAt(event->pos());
    if (!item)
        return;
    const QString url = item->text(1);

    QMenu contextMenu;
    QAction *copyAction = contextMenu.addAction(tr("Copy Link to Clipboard"));
    QAction *openAction = contextMenu.addAction(tr("Open"));
    QAction *action = contextMenu.exec(event->globalPos());
    if (action == copyAction)
        QGuiApplication::clipboard()->setText(url);
    else if (action == openAction)
        QDesktopServices::openUrl(QUrl(url));
}
#endif // !QT_NO_CONTEXTMENU && !QT_NO_CLIPBOARD





bool VrmsTree::read(QIODevice *device)
{
    QString errorStr;

    int errorLine;
    int errorColumn;

    if (!domDocument.setContent(device, true, &errorStr, &errorLine, &errorColumn))
    {
        QMessageBox::information( window(), tr("VRMS File"), tr("Parse error at line %1, column %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr));
        return false;
    }

    QDomElement root = domDocument.documentElement();

    if (root.tagName() != "vrms") {
        QMessageBox::information(window(), tr("VRMS File"),
                                 tr("The file is not an VRMS file."));
        return false;

    } else if (root.hasAttribute(versionAttribute())
               && root.attribute(versionAttribute()) != QLatin1String("1.0")) {
        QMessageBox::information(window(),
                                 tr("VRMS File"),
                                 tr("The file is not an VRMS version 1.0 file."));
        return false;
    }


    clear();

    disconnect(this, &QTreeWidget::itemChanged, this, &VrmsTree::updateTreeElement);

    QDomElement child = root.firstChildElement(deviceElement()); // Apre i tag /folder
    while (!child.isNull()) {
        parseDeviceElement(child);
        child = child.nextSiblingElement(deviceElement());
    }

    connect(this, &QTreeWidget::itemChanged, this, &VrmsTree::updateTreeElement);

    return true;
}




bool VrmsTree::write(QIODevice *device) const
{
    const int IndentSize = 4;

    QTextStream out(device);
    domDocument.save(out, IndentSize);
    return true;
}

void VrmsTree::updateTreeElement(const QTreeWidgetItem *item, int column)
{
    QDomElement element = item->data(0, DomElementRole).value<QDomElement>();
    if (!element.isNull()) {
        if (column == 0) {
            QDomElement oldTitleElement = element.firstChildElement(titleElement());
            QDomElement newTitleElement = domDocument.createElement(titleElement());

            QDomText newTitleText = domDocument.createTextNode(item->text(0));
            newTitleElement.appendChild(newTitleText);

            element.replaceChild(newTitleElement, oldTitleElement);
        } else {
           // if (element.tagName() == bookmarkElement())
           //     element.setAttribute(hrefAttribute(), item->text(1));
        }
    }
}




void VrmsTree::parseDeviceElement(const QDomElement &element, QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item = createItem(element, parentItem);

    QString alias = element.firstChildElement(titleElement()).text();

    if (title.isEmpty())
        title = QObject::tr("Device");

    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setIcon(0, deviceIcon);
    item->setText(0, title);

    bool folded = (element.attribute(foldedAttribute()) != QLatin1String("no"));
    item->setExpanded(!folded);


    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {


        if (child.tagName() == moduleElement()
        {
            parseModuleElement(child, item);

        } else if (child.tagName() == portElement()) {
            QTreeWidgetItem *childItem = createItem(child, item);

            QString alias = child.firstChildElement(aliasElement()).text();
            if (alias.isEmpty())
                title = QObject::tr("Folder");

            childItem->setFlags(item->flags() | Qt::ItemIsEditable);
            childItem->setIcon(0, portIcon);
            childItem->setText(0, title);
            childItem->setText(1, child.attribute(hrefAttribute()));

        } else if (child.tagName() == QLatin1String("separator")) {
            QTreeWidgetItem *childItem = createItem(child, item);
            childItem->setFlags(item->flags() & ~(Qt::ItemIsSelectable | Qt::ItemIsEditable));
            childItem->setText(0, QString(30, 0xB7));
        }
        child = child.nextSiblingElement();
    }
}




QTreeWidgetItem *VrmsTree::createItem(const QDomElement &element,
                                      QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    item->setData(0, DomElementRole, QVariant::fromValue(element));
    return item;
}

*/



