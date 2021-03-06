#include "edititemdialog.h"
#include "ui_edititemdialog.h"

EditItemDialog::EditItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItemDialog)
{
    ui->setupUi(this);
    currentItem = 0;
}

EditItemDialog::~EditItemDialog()
{
    delete ui;
}

void EditItemDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void EditItemDialog::setPanelItem(PanelItem *it) {
    if(currentItem) {
        disconnect(currentItem, 0, this, 0);
    }
    currentItem = it;
    if(!currentItem) {
        hide();
        return;
    }
    connect(currentItem, SIGNAL(destroyed()), this, SLOT(setPanelItem()));
    ui->zSlider->setValue(it->zValue());
    ui->rotationDial->setValue(it->itemRotation());
    connect(ui->zSlider, SIGNAL(valueChanged(int)), it, SLOT(setZValue(int)));
    connect(ui->rotationDial, SIGNAL(valueChanged(int)), it, SLOT(setItemRotation(int)));

    it->createSettings(ui->itemPropertiesGrid);
}
