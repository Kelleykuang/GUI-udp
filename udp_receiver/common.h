#ifndef COMMON_H
#define COMMON_H
#include<QList>
#include<QMutex>

//shared objects between threads
extern QVector<int> paint_list;
extern QVector<int> record_list;
extern QVector<int> data_list;
extern QMutex paint_lock;
extern QMutex record_lock;
extern QMutex data_lock;
#endif // COMMON_H
