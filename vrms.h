/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
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
****************************************************************************/

#ifndef XBELTREE_H
#define XBELTREE_H
/*
#include <QDomDocument>
#include <QIcon>
#include <QTreeWidget>

class VrmsTree : public QTreeWidget
{
    Q_OBJECT

public:
    VrmsTree(QWidget *parent = 0);

    bool read(QIODevice *device);
    bool write(QIODevice *device) const;
    bool receive(QIODevice *device);    // parse rx data

protected:

#if !defined(QT_NO_CONTEXTMENU) && !defined(QT_NO_CLIPBOARD)
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif

private slots:
    void updateTreeElement(const QTreeWidgetItem *item, int column);

private:
    void parseDeviceElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0);

    void parseModuleElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0);


    QTreeWidgetItem *createItem(const QDomElement &element,
                                QTreeWidgetItem *parentItem = 0);

    QDomDocument domDocument;

    QIcon folderIcon;  // Device Icon

    QIcon deviceIcon;  // Device Icon

    QIcon moduleLocIcon; // Module Icon ( Sem16, Loconet )

    QIcon moduleSemIcon; // Module Icon ( Sem16, Loconet )

    QIcon moduleLcnIcon; // Module Icon ( Sem16, Loconet )

    QIcon portIcon; // Port/Gatte Icon (  )

};
*/

#endif
