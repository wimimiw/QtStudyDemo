#include "dialogui.h"
#include "ui_dialogui.h"

DialogUI::DialogUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUI)
{
    ui->setupUi(this);
}

DialogUI::~DialogUI()
{
    delete ui;
}
