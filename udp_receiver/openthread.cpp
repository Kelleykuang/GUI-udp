/*#include "openthread.h"
const quint16 PORT = 2333;
OpenThread::OpenThread(QObject *p) :
    QObject(p)
{
    uSocket = new QUdpSocket;
    connect(uSocket, SIGNAL(newConnection()),this,SLOT(openThread()));
    uSocket->bind(QHostAddress("127.0.0.1"), PORT);
}

OpenThread::~OpenThread()
{

}

void OpenThread::openThread()
{
    newreceiver=new UdpReceiver();
    newreceiver->start();

}
*/
