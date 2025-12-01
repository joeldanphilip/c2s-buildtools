#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>

#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_SPEED 1000000

static int spi_fd;

void max7219_send(uint8_t address, uint8_t data) {
    uint8_t tx[] = { address, data };
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = 0,
        .len = 2,
        .speed_hz = SPI_SPEED,
        .bits_per_word = 8,
        .delay_usecs = 0,
    };
    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr);
}

void max7219_init() {
    max7219_send(0x0F, 0x00); // Display test off
    max7219_send(0x0C, 0x01); // Normal operation
    max7219_send(0x0B, 0x07); // Scan limit = 8
    max7219_send(0x0A, 0x08); // Brightness
    max7219_send(0x09, 0x00); // No decode
}

void max7219_clear() {
    for (uint8_t i = 1; i <= 8; i++) {
        max7219_send(i, 0x00);
    }
}

int main() {
    uint8_t mode = 0, bits = 8;
    uint32_t speed = SPI_SPEED;

    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        perror("can't open device");
        return 1;
    }

    ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);
    ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    max7219_init();
    max7219_clear();

    // Test pattern
    for (uint8_t row = 1; row <= 8; row++) {
        max7219_send(row, 0xAA); // 10101010
    }

    close(spi_fd);
    return 0;
}

