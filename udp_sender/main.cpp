
#include <QApplication>
#include "udpsender.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "--- sender ---" ;
    UdpSender us;
    return a.exec();
}
