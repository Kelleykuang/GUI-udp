#include "udpsender.h"
#include <QTime>
#include <QFile>
#include <QThread>
#include <QDataStream>
#include <QIODevice>
#define PT_SIZE 512
//#define OUTPUT2FILE
const quint16 PORT = 2333;
UdpSender::UdpSender(QWidget *parent) : QWidget(parent)
{
    QByteArray msg;
    QVector<int> vec(PT_SIZE);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

#ifdef OUTPUT2FILE
    QFile file("C:/Users/kelle/Desktop/sender.txt");
    if(!file.open(QIODevice::WriteOnly)){
        qDebug() << "can't open file";
        exit(0);
    }
    QTextStream stream(&file);
#endif

    t.start();
    times = 0;
    qDebug() << QTime::currentTime();
    timerID = startTimer(1);
    //create messages and send
    /*for(int j=0; j<3000; j++){
        for(i=0; i<PT_SIZE; i++){
            vec[i] = rand();
            //qDebug() << vec[i];
        }
        QDataStream stream(&msg, QIODevice::ReadWrite);
        stream << vec;
        //qDebug() << msg;
        //for(i=0; i<PT_SIZE; i++){
            //msg.setNum(vec[i]);
            qus.writeDatagram(msg, QHostAddress::LocalHost, PORT);
        //}
    }*/

    //record t to calculate sending frequency
    //record time to compare with receiver's completion time, in order to prove real-time ability
#ifdef OUTPUT2FILE
    stream << t.elapsed() << "ms" <<endl;
    stream << QTime::currentTime().toString("hh:mm:ss.zzz") << endl;
#else
    //if(t.elapsed()==1000) killTimer(timerID);
    //qDebug() << t.elapsed() << "ms";
    //qDebug() << QTime::currentTime();
#endif
}
UdpSender::~UdpSender(){
    double f = times*1000/t.elapsed();
    qDebug() << "frequency:" << f;
    qDebug() << times;
    qDebug() << QTime::currentTime();
}
void UdpSender::timerEvent(QTimerEvent *event){
    QByteArray msg;
    QVector<int> vec(PT_SIZE);
    int i;
    times+=3;
    for(int j=0; j<3; j++){
        for(i=0; i<PT_SIZE; i++){
            vec[i] = rand();
            //qDebug() << vec[i];
        }
        QDataStream stream(&msg, QIODevice::ReadWrite);
        stream << vec;
        //qDebug() << msg;
        //for(i=0; i<PT_SIZE; i++){
            //msg.setNum(vec[i]);
            qus.writeDatagram(msg, QHostAddress::LocalHost, PORT);
        //}
    }

}
