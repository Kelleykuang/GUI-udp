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
#include "record.h"
#include "UdpReceiver.h"
#include "distributer.h"
using namespace QtCharts;
class RealTimeCurveQChartWidget : public QWidget {
    Q_OBJECT
    public:
        explicit RealTimeCurveQChartWidget(QWidget *parent = 0);
        ~RealTimeCurveQChartWidget();
        void start();
signals:
        void startrunning();
    protected:
        void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    private:
        int dx;
        int data;
        int timerId; //计数器
        int times;
        int maxSize; // data 最多存储 maxSize 个元素
        int maxX;    //x轴最大值
        int maxY;    //y轴最大值
        QChart *chart;
        QChartView *chartView;
        QScatterSeries *scatterSeries;

        QThread receiveThread;
        QThread recordThread;
        QThread distributeThread;
        UdpReceiver *receiver;
        record *recorder;
        distribute *distributer;
};


#endif // PAINT_H
