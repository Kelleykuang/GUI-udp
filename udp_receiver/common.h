#ifndef COMMON_H
#define COMMON_H
#include<QList>
#include<QMutex>

//shared objects between threads
extern QList<int> paint_list;
extern QList<int> record_list;
extern QMutex paint_lock;
extern QMutex record_lock;
#endif // COMMON_H
