#include "dialog.h"
#include <QApplication>

#define swap(x,y) { x=x+y;\
                    y=x-y;\
                    x=x-y;}

int main(int argc, char *argv[])
{
    int c=1,b=2;
    swap(c,b);
    QApplication a(argc, argv);
    Dialog w;
    w.show();    
    return a.exec();
}
