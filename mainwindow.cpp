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
    float psi = static_cast<float>(0.007*sample-5.22);
    //float psi = ((((float)sample - MIN_COUNT) * (100 - 0)) / (MAX_COUNT - MIN_COUNT)) + 0;
    ui->label_2->setText(QString::number(psi));
}
