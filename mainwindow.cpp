#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s=new sensor;

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel);
    timer->start(100); // milliseconds
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel()
{
    float sample=s->convert();
    ui->label->setText(QString::number(sample));
    float pressure = static_cast<float>(0.01*sample-8.72);
    ui->label_2->setText(QString::number(pressure));
}
