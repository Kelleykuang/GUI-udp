#include "paint.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QDebug>
#include <QThread>
RealTimeCurveQChartWidget::RealTimeCurveQChartWidget(QWidget *parent) : QWidget(parent) {
    //create and start a receiver thread and a recorder thread
    receiver = new UdpReceiver;
    receiver->moveToThread(&receiveThread);
    recorder = new record;
    recorder->moveToThread(&recordThread);
    distributer = new distribute;
    distributer->moveToThread(&distributeThread);
    connect(this,SIGNAL(startrunning()),receiver,SLOT(receiving()));
    connect(this,SIGNAL(startrunning()),recorder,SLOT(recording()));
    connect(this,SIGNAL(startrunning()),distributer,SLOT(distrbuting()));
    receiveThread.start();
    recordThread.start();
    distributeThread.start();

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

    times = 0;
    dx = maxX/maxSize;
    //scatterSeries = new QScatterSeries();
    scatterSeries->setMarkerSize(6);

    //try to redraw the screen in every single millisecond
    timerId = startTimer(1);
}
RealTimeCurveQChartWidget::~RealTimeCurveQChartWidget(){
    qDebug() <<times;
    receiveThread.quit();
    recordThread.quit();
    distributeThread.quit();
    receiveThread.wait();
    recordThread.wait();
    distributeThread.wait();
    delete scatterSeries;
    delete chart;
    delete chartView;
}

void RealTimeCurveQChartWidget::timerEvent(QTimerEvent *event) {
    paint_lock.lock();
    if(paint_list.size() >= maxSize){
        scatterSeries->clear();
        for(int i = 0; i < maxSize; i++){
            scatterSeries->append(i*dx, paint_list.at(i));
        }
        paint_list.remove(0,512);
        paint_lock.unlock();
        times++;
    }
    else paint_lock.unlock();
}

void RealTimeCurveQChartWidget::start(){
    emit startrunning();
}
