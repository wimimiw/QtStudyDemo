#include "dialog.h"
#include <QtGui>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->groupBox = new QGroupBox(tr("Group1"));
    this->groupBox2 = new QGroupBox(tr("Group1"));

    pushButton = new QPushButton(tr("pushbutton1"));
    pushButton2 = new QPushButton(tr("pushbutton1"));
    lineEdit = new QLineEdit(tr("Lineedit"));
    lineEdit2 = new QLineEdit(tr("Lineedit"));
    probar = new QProgressBar();
    lable = new QLabel(tr("abc"));
    //probar->setValue(probar->maximum()/2);

    //信号和槽的形参要一致，可以通过pushButton->clicked找到该类的信号方法
    connect(pushButton,SIGNAL(clicked(bool)),
            this,SLOT(setValueABC(bool)));

    connect(pushButton2,SIGNAL(clicked(bool)),
            this,SLOT(from2Open(bool)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pushButton);
    layout->addWidget(lineEdit);    
    layout->addWidget(probar,Qt::AlignJustify);
    groupBox->setLayout(layout);
    groupBox->setTitle("123");

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(lable);
    hlayout->addWidget(lineEdit2);
    hlayout->addWidget(pushButton2);
    hlayout->setStretch(1,2);
    groupBox2->setLayout(hlayout);
    groupBox2->setTitle("456");

    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->addWidget(groupBox,0,0);
    mainlayout->addWidget(groupBox2,1,0);
    setLayout(mainlayout);
    resize(300,200);

    tmr = new QTimer();
    tmr->setInterval(200);
    connect(tmr,SIGNAL(timeout()),this,SLOT(timeTongzhi()));
    tmr->start();
}

void Dialog::timeTongzhi()
{
    static int i = 0;
    probar->setValue(i++);
}

void Dialog::from2Open(bool result)
{
    result = result;

    static bool flag = true;

    if(flag)
    {
        flag = false;
        form2 *frm = new form2(this);
        frm->show();
    }
    else
    {
        flag = true;
        DialogUI *dgui = new DialogUI(this);
        dgui->show();
    }
}

void Dialog::setValueABC(bool result)
{
    result = result;

    static bool flag = false;

    flag = !flag;

    if(flag)
    {
        lineEdit2->setText(tr("123445679"));
        pushButton->setText(tr("fuck"));
        pushButton2->setEnabled(false);
        tmr->stop();
    }
    else
    {
        lineEdit2->setText(QTextCodec::codecForName("UTF8")->toUnicode("信息已发送"));
        pushButton->setText(tr("memarry"));
        pushButton2->setEnabled(true);
        tmr->start();
    }
}

Dialog::~Dialog()
{
    
}
