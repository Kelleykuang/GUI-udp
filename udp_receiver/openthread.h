/*#ifndef OPENTHREAD_H
#define OPENTHREAD_H
#include <QtNetwork>
#include <QUdpSocket>
#include <QTimer>
#include <QList>
#include "udpreceiver.h"

class OpenThread : public QObject
{
    Q_OBJECT

public:
    explicit OpenThread(QObject *p = 0);
    ~OpenThread();

private slots:

    void openThread();   //开线程


private:
    UdpReceiver *newreceiver;
    QUdpSocket *uSocket;
    //void init();  // 初始化函数用于完成一些诸如信号与槽之间的联系和变量初始化工作

};

#endif // OPENTHREAD_H
*/
