#include <QCoreApplication>
#include <QTcpSocket>
#include <QObject>
#include <QThread>
#include <QFile>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "counter.h"

class MyThread : public QThread
{
public:
    void run();
};

void MyThread::run()
{
    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 9999);
    QByteArray br;
    //br.append("123456");

    int index = 0;

    while(true)
    {
        br.clear();
        while (socket.bytesAvailable() == 0) {
            if (socket.waitForReadyRead(1000)) {
                br = socket.readAll();
                break;
            }
        }
        std::cout<<br.data()<<std::endl;
        socket.write(br.append(" "+QString::number(index++)+'\n'));
    }

    socket.disconnect();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //a.connect(&socket, SIGNAL(readyRead()), &a, SLOT(readFortune()));

    QByteArray br("1234.89");

    QList<int> list;
    list.append(18);
    list.append(19);

    list.insert(1,9999);

    std::cout<<list[0]
             <<" "
             <<list.at(1)
             <<" "
             <<list.size()<<std::endl;

    std::map<std::string,int> map;
    //map.insert()

    QMap<QString,int> qmap;

    qmap.insert("qmap",1);
    qmap.insert("123",1);
    qmap.insert("456",1);
    qmap.insert("789",1);

    std::cout<<qmap["qmap"]<<std::endl;

    QMapIterator<QString, int> p(qmap);
    while (p.hasNext()) {
        p.next();
        std::cout<<p.key().toStdString() << ": "<< p.value()<<std::endl;
    }

    QVector<QString> vector;
    vector << "A" << "B" << "C" << "B" << "A";

    std::cout<<"Vector"<<std::endl;
    std::cout
    <<
    vector.indexOf("B")           // returns 1
    <<
    vector.indexOf("B", 1)         // returns 1
    <<
    vector.indexOf("B", 2)        // returns 3
    <<
    vector.indexOf("X")            // returns -1
    <<
    std::endl;

    std::cout<<vector[2].toStdString()<<std::endl;

    vector.clear();
    vector << "alpha" << "beta" << "delta";
    vector.insert(2, "gamma");
    // vector: ["alpha", "beta", "gamma", "delta"]

    Counter c, b;
    QObject::connect(&c, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));

    c.setValue(12);
    b.setValue(48);

    float ft = br.toFloat();ft=ft;

    br.clear();
    br.append("-9999");

    int value = br.toInt();value = value;

    br.clear();
    br.append("1234567890-45678");

    char buf[br.length()];
    memcpy(buf,br.data(),sizeof(buf));

    int clen = sizeof(a);

    std::cout<<"File Operator"<<std::endl;
    QString name = a.applicationDirPath().append("\\readme.txt");
    QFile file(name);
    file.open(QIODevice::ReadWrite | QIODevice::Text );
    file.close();

    file.open(QIODevice::ReadWrite);
    file.write(br);
    file.close();

    br.clear();
    file.open(QIODevice::ReadOnly);
    br = file.readAll();

    std::cout << "out:" << br.data() << std::endl;

    MyThread thrd;
    thrd.run();

    return a.exec();
}
