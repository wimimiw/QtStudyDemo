#include "subdialog.h"
#include "ui_subdialog.h"

SubDialog::SubDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubDialog)
{
    ui->setupUi(this);
}

SubDialog::~SubDialog()
{
    delete ui;
}
