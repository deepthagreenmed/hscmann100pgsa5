#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sensor.h"

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateLabel();

private:
    Ui::MainWindow *ui;
    sensor *s;
};
#endif // MAINWINDOW_H
