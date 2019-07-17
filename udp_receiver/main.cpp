
#include <QCoreApplication>
#include <QApplication>
#include "paint.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RealTimeCurveQChartWidget r;
    r.start();
    return a.exec();
}
