#include "paint.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QDebug>
#include <QThread>
RealTimeCurveQChartWidget::RealTimeCurveQChartWidget(QWidget *parent) : QWidget(parent) {
    receiver = new UdpReceiver;
    receiver->moveToThread(&receiveThread);
    recorder = new record;
    recorder->moveToThread(&recordThread);
    connect(this,SIGNAL(startrunning()),receiver,SLOT(receiving()));
    connect(this,SIGNAL(startrunning()),recorder,SLOT(recording()));

    receiveThread.start();
    recordThread.start();


    maxSize = 512;
    maxX = 512;
    maxY = 40000;

    //splineSeries = new QSplineSeries();

    scatterSeries = new QScatterSeries();
    scatterSeries->setMarkerSize(8);

    chart = new QChart();
    //chart->addSeries(splineSeries);
    chart->addSeries(scatterSeries);
    chart->legend()->hide();
    chart->setTitle("real-time display chart");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, maxX);
    chart->axisY()->setRange(0, maxY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);
    setLayout(layout);

    this->resize(1400, 800);
    this->show();

    //times = 0;
    dx = maxX/maxSize;
    //scatterSeries = new QScatterSeries();
    scatterSeries->setMarkerSize(6);
    timerId = startTimer(1);
    /*while(1){
        if(paint_list.size() >= maxSize){
            scatterSeries->clear();
            for(int i = 0; i < maxSize; i++){
                paint_lock.lock();
                data = paint_list.takeFirst();
                paint_lock.unlock();
                scatterSeries->append(i*dx, data);
            }
            times++;
            qDebug()<<times;
        }
        else QThread::msleep(1);
    }*/
}
RealTimeCurveQChartWidget::~RealTimeCurveQChartWidget(){
    receiveThread.quit();
    recordThread.quit();
    receiveThread.wait();
    recordThread.wait();
    delete scatterSeries;
    delete chart;
    delete chartView;
}

void RealTimeCurveQChartWidget::timerEvent(QTimerEvent *event) {
    if(paint_list.size() >= maxSize){
        scatterSeries->clear();
        for(int i = 0; i < maxSize; i++){
            paint_lock.lock();
            data = paint_list.takeFirst();
            paint_lock.unlock();
            scatterSeries->append(i*dx, data);
        }
        //times++;
        //qDebug()<<times;
    }
}

void RealTimeCurveQChartWidget::start(){
    emit startrunning();
}
