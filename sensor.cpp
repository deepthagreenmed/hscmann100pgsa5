#include "sensor.h"

sensor::sensor(QObject *parent) : QObject(parent)
{
    init();
}

sensor::~sensor()
{
    close(spi_fd);
}

void sensor::init()
{
    spi_fd = open("/dev/spidev1.2", O_RDWR);

    int mode;
    int bits = 8;
    int speed = 1000000;
    //ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);
    ioctl(spi_fd, SPI_IOC_RD_MODE, &mode);
    //ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    ioctl(spi_fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    //ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    ioctl(spi_fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
}

float sensor::convert()
{
    //uint8_t tx[2] = {0xA7, 0x00};
    uint8_t rx[2] = {0x00, 0x00};

    float sample = 0;
    uint16_t delay = 0;
    uint8_t bits = 8;
    uint32_t speed = 1000000;

    struct spi_ioc_transfer tr = {
        //.tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)rx,
        .len = 2,
        .speed_hz = speed,
        .delay_usecs = delay,
        .bits_per_word = bits,
    };

    /* send the cmd to start the conversion and read the result */
    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr);

    qDebug()<<rx[0]<<rx[1];

    sample = (uint16_t)(((rx[1] & 0x3F) << 8) | (rx[0] & 0xFF));
    qDebug()<<sample;

    return sample;
}

