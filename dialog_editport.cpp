#include "dialog_editport.h"
#include "ui_dialog_editport.h"



Dialog_EditPort::Dialog_EditPort(dmModules model, QModelIndex index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_EditPort)
{
    ui->setupUi(this);
    //connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL( clicked() ), SLOT(on_ok_clicked())  );
}





Dialog_EditPort::~Dialog_EditPort()
{
    delete ui;


}

void Dialog_EditPort::setData(vs_module_t *module, const QModelIndex &index)
{
  m_index = &index;
  m_module = module;

 /* ui->ckEnabled
 ui->lbModuleAlias->setText(module->malias);
 ui->lbModulePort->setText(QString("P%1").arg(index.row()));

 ui->ckEnabled->setCheckState((module->ports[index.row()].enabled)?Qt::Checked:Qt::Unchecked);
 ui->lbAlias->setText(module->ports[index.row()].palias);
 //ui->rbIn->click()
 */

}

void Dialog_EditPort::on_buttonBox_clicked(QAbstractButton *button)
{
  // ok
}


void Dialog_EditPort::on_buttonBox_accepted()
{
    /*
    m_module->ports[m_index->row()].enabled =  (ui->ckEnabled->isChecked())?ON:OFF;
    strcpy_s(m_module->ports[m_index->row()].palias,  ui->lbAlias->text().trimmed().toLocal8Bit());
    emit myplcChanged(*m_index);
    */
}

