#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    uii(new Ui::MainWindow)
{
   uii->setupUi(this);
   //connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked(bool)));
}

MainWindow::~MainWindow()
{
    delete uii;
}

void MainWindow::on_checkBox_2_clicked()
{

}

void MainWindow::on_pushButton_clicked(bool checked)
{
    uii->textBrowser->append(">1234567890");
}

void MainWindow::on_tabWidget_selected(const QString &arg1)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    SubDialog sd;
    sd.exec();
    //SubDialog *fg = new SubDialog();
    //fg->show();
}
