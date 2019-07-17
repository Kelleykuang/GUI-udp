#ifndef UDPSENDER_H
#define UDPSENDER_H
#include <QByteArray>
#include <QHostAddress>
#include <QUdpSocket>
#include <iostream>
#include <QTime>
#include <QObject>

class UdpSender : public QObject
{
    Q_OBJECT
public:
    explicit UdpSender(QObject *parent = nullptr);

private:
    QUdpSocket qus;
};

#endif // UDPSENDER_H
