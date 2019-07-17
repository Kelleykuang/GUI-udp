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
    if(!file.open(QIODevice::WriteOnly)){
        qDebug() << "can't open file";
        exit(0);
    }
    QTextStream stream(&file);
    int t = 0;
    while(1){
        if(t==3000){
            //stream << QTime::currentTime().toString("hh:mm:ss.zzz") << endl;
            qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz");   //output the completion time to compare
            break;
         }
        if(record_list.size() >= maxSize){
            for(int i = 0; i < maxSize; i++){
                record_lock.lock();
                data = record_list.takeFirst();
                record_lock.unlock();
                stream << data <<endl;
            }
            t++;
        }
        else QThread::usleep(1);
    }
}
