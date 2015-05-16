#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "form2.h"
#include "dialogui.h"

QT_BEGIN_NAMESPACE
class QGroupBox;
class QPushButton;
class QLineEdit;
class QLabel;
class QProgressBar;
class QTimer;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void setValueABC(bool result);
    void from2Open(bool result);
    void timeTongzhi();
private:
    QGroupBox *groupBox;
    QGroupBox *groupBox2;
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QLabel *lable;
    QProgressBar *probar;
    QTimer *tmr;
};

#endif // DIALOG_H
