#include "distributer.h"

distribute::distribute(QObject *parent) : QObject(parent)
{

}
void distribute::distrbuting(){
    QVector<int> buffer;
    QVector<int> vec(512);

    int i, count = 0;
    while(1){
        data_lock.lock();
        if(!data_list.isEmpty()){
            buffer.swap(data_list);
        }
        data_lock.unlock();
        for(i = 0; i < buffer.size()/512; i++, count = (count+1)%120){
            vec = buffer.mid(i*512, 512);
            record_lock.lock();
            record_list.append(vec);
            record_lock.unlock();
            if(count == 0){
                paint_lock.lock();
                paint_list.append(vec);
                paint_lock.unlock();
            }
        }
        buffer.clear();
    }
}
