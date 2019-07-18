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
    int i;
    while(1){
        if(t==3000){
            //stream << QTime::currentTime().toString("hh:mm:ss.zzz") << endl;
            qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz");   //output the completion time to compare
            break;
         }
        record_lock.lock();
        if(!record_list.isEmpty()){
            //for(i=0; i<record_list.size(); i++){
                //stream << record_list.at(i);
            //}
            //stream << endl;
            stream << record_list;
            record_list.clear();
            record_lock.unlock();
        }
        else{
            record_lock.unlock();
            QThread::usleep(1);
        }
    }
}
