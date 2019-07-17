#include <QByteArray>
#include <QHBoxLayout>
#include "UdpReceiver.h"
const quint16 PORT = 2333;

UdpReceiver::UdpReceiver(QObject *p):
    QObject(p)
{

}

UdpReceiver::~UdpReceiver()
{

}
void UdpReceiver::receiving()
{
    count = 0;
    uSocket = new QUdpSocket(this);
    uSocket->bind(QHostAddress::LocalHost, PORT);
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(real_receive()));
}
void UdpReceiver::real_receive()
{
    QByteArray ba("");
    int cur_data;
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        cur_data = ba.toInt();
        count = (count+1)%100;
        record_lock.lock();
        record_list.append(cur_data);
        record_lock.unlock();
        if(count == 0){
            paint_lock.lock();
            paint_list.append(cur_data);
            paint_lock.unlock();
            //qDebug() << cur_data;
        }
        //qDebug()<< cur_data ;
    }
}
