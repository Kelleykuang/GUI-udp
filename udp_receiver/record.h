#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <common.h>
class record : public QObject
{
    Q_OBJECT
public:
    explicit record(QObject *parent = nullptr);

signals:

public slots:
    void recording();
private:
    int maxSize;
    int data;
};

#endif // RECORD_H
