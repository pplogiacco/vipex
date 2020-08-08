#include "dialog_editmodule.h"
#include "ui_dialog_editmodule.h"
#include "qpushbutton.h"
#include "myplc.h"


Dialog_EditModule::Dialog_EditModule(dmModules *myplc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_EditModule),
    l_myplc(myplc)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Nanoboard v3.0 (base)", module_t::_NBV30 );
    ui->comboBox->addItem("Sem16 - IO Expander", module_t::_SEM16);
    ui->comboBox->addItem("Loconet-IF", module_t::_LCNIF);
    ui->comboBox->update();

    ui->sem_addr->setVisible(false);
    ui->lcn_addr->setVisible(false);
    ui->lcn_opts->setVisible(false);

    // SEM16 Addr
    connect(ui->J1, SIGNAL(clicked()), this, SLOT(on_jumpers_changed()) );
    connect(ui->J2, SIGNAL(clicked()) ,this, SLOT(on_jumpers_changed()) );
    connect(ui->J3, SIGNAL(clicked()), this, SLOT(on_jumpers_changed()) );

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combo_changed(int)) );
    //connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL( clicked() ), SLOT(on_ok_clicked())  );


}


Dialog_EditModule::~Dialog_EditModule()
{
    delete ui;
}


void Dialog_EditModule::on_combo_changed(int index)
{
    index++;
    switch ((module_t)index) {

    case _NBV30:
            //myplcModule->setText(0, tr("Nanoboard_v3 (%1)").arg(module->addr));
            ui->lcn_addr->setVisible(false);
            ui->sem_addr->setVisible(false);
            ui->lcn_opts->setVisible(false);
           break;

       case _SEM16:
            //myplcModule->setText(0, tr("Sem16 - IO Expander (%1)").arg(module->addr));
            ui->lcn_addr->setVisible(false);
            ui->lcn_opts->setVisible(false);
            ui->sem_addr->setVisible(true);
           break;

       case _LCNIF:
            ui->sem_addr->setVisible(false);
            ui->lcn_addr->setVisible(true);
            ui->lcn_opts->setVisible(true);
           break;
    }  // end-switch

}

void Dialog_EditModule::on_jumpers_changed()
{
  word_t adr = 0;
  if ( ui->J1->isChecked() ) { adr+=10; }
  if ( ui->J2->isChecked() ) { adr+=100; }
  if ( ui->J3->isChecked() ) { adr+=1000; }
  ui->lbJaddr->setNum(adr);
}


void Dialog_EditModule::on_ok_clicked()
{

}

