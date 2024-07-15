#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <vector>
#include <iostream>

#include <QObject>
#include <QDebug>

class sensor : public QObject
{
    Q_OBJECT
public:
    explicit sensor(QObject *parent = nullptr);
    ~sensor();
    void init();
    float convert();

signals:
private:
    int spi_fd;

};

#endif // SENSOR_H
