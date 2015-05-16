#ifndef DIALOGUI_H
#define DIALOGUI_H

#include <QDialog>

namespace Ui {
class DialogUI;
}

class DialogUI : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogUI(QWidget *parent = 0);
    ~DialogUI();
    
private:
    Ui::DialogUI *ui;
};

#endif // DIALOGUI_H
