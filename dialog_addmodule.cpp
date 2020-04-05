#include "dialog_addmodule.h"
#include "ui_dialog_addmodule.h"
#include "qpushbutton.h"
#include "myplc.h"


DialogAddModule::DialogAddModule( MyPlcModel *myplc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddModule),
    l_myplc(myplc)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Nanoboard v3.0 (base)", module_t::_NBV30 );
    ui->comboBox->addItem("Sem16 - IO Expander", module_t::_SEM16);
    ui->comboBox->addItem("Loconet-IF", module_t::_LCNIF);

    ui->gJumpers->setVisible(false);
    ui->gAddress->setVisible(false);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combo_changed(int)) );
    connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL( clicked() ), SLOT(on_ok_clicked())  );


    connect(ui->J1, SIGNAL(clicked()), this, SLOT(on_jumpers_changed()) );
    connect(ui->J2, SIGNAL(clicked()) ,this, SLOT(on_jumpers_changed()) );
    connect(ui->J3, SIGNAL(clicked()), this, SLOT(on_jumpers_changed()) );


    //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

}


DialogAddModule::~DialogAddModule()
{
    delete ui;
}

void DialogAddModule::on_ok_clicked()
{

    MyPlcItem *mod = new MyPlcItem((module_t)ui->comboBox->currentData().Int,
                                   ui->lbJaddr->text().toUInt() );
                                   // word_t opt1
                                   // word_t opt2);

   l_myplc->rootDevice()->appendChild(mod);  // appendModule(module);
                                             // appendPort();
                                             // appendRule();
}


void DialogAddModule::on_combo_changed(int index)
{
    index++;
    switch ((module_t)index) {
       case _NBV30:
            //myplcModule->setText(0, tr("Nanoboard_v3 (%1)").arg(module->addr));
            ui->gJumpers->setVisible(false);
            ui->gAddress->setVisible(false);
           break;
       case _SEM16:
            //myplcModule->setText(0, tr("Sem16 - IO Expander (%1)").arg(module->addr));
            ui->gJumpers->setVisible(true);
            ui->gAddress->setVisible(false);
           break;
       case _LCNIF:
            //myplcModule->setText(0, tr("Loconet-IF (%1)").arg(module->addr));
            ui->gJumpers->setVisible(false);
            ui->gAddress->setVisible(true);
           break;
    }  // end-switch

}


void DialogAddModule::on_jumpers_changed()
{
  word_t adr = 0;

  if ( ui->J1->isChecked() ) { adr+=10; }
  if ( ui->J2->isChecked() ) { adr+=100; }
  if ( ui->J3->isChecked() ) { adr+=1000; }

  ui->lbJaddr->setNum(adr);


}


/*
void DialogAddModule::accept()
{

}


void DialogAddModule::reject()
{

}






void DialogAddModule::on_buttonBox_clicked(QAbstractButton *button)
{
   // ui->buttonBox()    if ( button == QDialogButtonBox::Reset ) {


}

*/

void DialogAddModule::on_J1_stateChanged(int arg1)
{

}
