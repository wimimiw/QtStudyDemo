#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include <QDialog>

namespace Ui {
class SubDialog;
}

class SubDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubDialog(QWidget *parent = 0);
    ~SubDialog();
    
private:
    Ui::SubDialog *ui;
};

#endif // SUBDIALOG_H
