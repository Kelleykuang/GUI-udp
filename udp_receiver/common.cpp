#include "common.h"
QList<int> paint_list;
QList<int> record_list;
QMutex paint_lock;
QMutex record_lock;
