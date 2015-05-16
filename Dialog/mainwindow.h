#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <subdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_checkBox_2_clicked();

    void on_pushButton_clicked(bool checked);

    void on_tabWidget_selected(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *uii;
};

#endif // MAINWINDOW_H
