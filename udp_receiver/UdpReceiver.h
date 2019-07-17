#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H
#include <QObject>
#include <QUdpSocket>
#include <QtNetwork>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <common.h>
class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    explicit UdpReceiver(QObject *p = 0);
    ~UdpReceiver();

public slots:
    void receiving();
    void real_receive();
private:
    int count;
    QUdpSocket *uSocket;
};
#endif
