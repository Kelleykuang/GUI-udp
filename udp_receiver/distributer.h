#ifndef DISTRIBUTER_H
#define DISTRIBUTER_H

#include <QObject>
#include <common.h>
#include <QVector>
class distribute : public QObject
{
    Q_OBJECT
public:
    explicit distribute(QObject *parent = nullptr);

signals:

public slots:
    void distrbuting();
};

#endif // DISTRIBUTER_H
