#include <QByteArray>
#include <QHBoxLayout>
#include <QDataStream>
#include <QIODevice>
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
    QByteArray ba;
    QVector<int> vec(512);
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        //qDebug() << ba;
        QDataStream stream(&ba, QIODevice::ReadWrite);
        vec.clear();
        stream >> vec;
        data_lock.lock();
        //qDebug() << vec;
        data_list.append(vec);
        data_lock.unlock();
        /*count = (count+1)%100;
        record_lock.lock();
        record_list.append(vec);
        record_lock.unlock();
        if(count == 0){
            paint_lock.lock();
            paint_list.append(vec);
            paint_lock.unlock();
            //qDebug() << cur_data;
        }*/
        //qDebug()<< cur_data ;
    }
}
