#ifndef UDPSENDER_H
#define UDPSENDER_H
#include <QByteArray>
#include <QHostAddress>
#include <QUdpSocket>
#include <iostream>
#include <QTime>
#include <QObject>
#include <QWidget>
class UdpSender : public QWidget
{
    Q_OBJECT
public:
    explicit UdpSender(QWidget *parent = nullptr);
    ~UdpSender();
protected:
    void timerEvent( QTimerEvent *event );
private:
    QUdpSocket qus;
    int timerID;
    int times;
    QTime t;
};

#endif // UDPSENDER_H
