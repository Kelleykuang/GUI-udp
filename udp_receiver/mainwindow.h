/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//未用
#include <QMainWindow>
#include "paint.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RealTimeCurveQChartWidget *w;
};

#endif // MAINWINDOW_H*/

