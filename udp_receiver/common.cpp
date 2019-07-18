#include "common.h"

//shared objects between threads
QVector<int> paint_list;
QVector<int> record_list;
QVector<int> data_list;
QMutex paint_lock;
QMutex record_lock;
QMutex data_lock;
