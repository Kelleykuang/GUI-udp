#include "common.h"

//shared objects between threads
QList<int> paint_list;
QList<int> record_list;
QMutex paint_lock;
QMutex record_lock;
