#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QList>
#include <QChart>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QChartView>
#include <QTime>
#include <QUdpSocket>
#include <QtNetwork>
#include "common.h"
using namespace QtCharts;
class RealTimeCurveQChartWidget : public QObject {
    Q_OBJECT
    public:
        explicit RealTimeCurveQChartWidget(QObject *parent = 0);
    public slots:
        void painting();

    protected:
        void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    private:
        int maxSize;
        int dx;
        int data;
        int timerId; //计数器
        int times;
};


#endif // PAINT_H
