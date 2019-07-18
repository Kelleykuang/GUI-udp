#include "record.h"
#include<QFile>
#include<QDebug>
#include<QThread>
#include<QTime>
#include<stdio.h>
record::record(QObject *parent) : QObject(parent)
{

}
void record::recording(){
    maxSize = 512;
    QFile file("C:/Users/kelle/Desktop/data.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qDebug() << "can't open file";
        exit(0);
    }
    QDataStream stream(&file);
    int t = 0;
    while(1){
        record_lock.lock();
        if(!record_list.isEmpty()){
            t += record_list.size()/512;
            stream << record_list;
            record_list.clear();
            record_lock.unlock();
            qDebug() << t;
        }
        else{
            record_lock.unlock();
            QThread::usleep(1);
        }
    }
}
