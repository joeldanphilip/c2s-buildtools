

## spidev-test(SPI)

      ./spidev_test -v
      
#### 1.connect MOSI TO MISO 
OUTPUT:

spi mode: 0x0
bits per word: 8
max speed: 500000 Hz (500 KHz)
TX | FF FF FF FF FF FF 40 00 00 00 00 95 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF F0 0D | ......@....?..................?.
RX | FF FF FF FF FF FF 40 00 00 00 00 95 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF F0 0D  | ......@....?..................?.

#### 2.the pins MOSI and MISO aren't connected.
OUTPUT:

TX | FF FF FF FF FF FF 40 00 00 00 00 95 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF F0 0D  | ......@....?..................?.
RX | 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  | ................................

## spidisplay(SPI)

     ./spi_max7219

0xAA(10101010 for 8 rows)
 ```
 11111111
 00000000
 11111111
 00000000
 11111111
 00000000
 11111111
 00000000
```

## ssd1306_linux-master(i2c)

#### init the OLED once
- resolution 128x64
```
$ ./ssd1306_bin -I 128x64
```
- resolution 128x32
```
$ ./ssd1306_bin -I 128x32
```
- resolution 64x48
```sh
$ ./ssd1306_bin -I 64x48
```
#### clear display
- clear 1st line
```sh
./ssd1306_bin -c0
```
- clear 2nd line
```sh
$ ./ssd1306_bin -c1
```
- clear 4th line
```sh
$ ./ssd1306_bin -c3
```
- clear whole screen
```sh
$ ./ssd1306_bin -c
```
#### display on/off
- turn off display
```sh
$ ./ssd1306_bin -d 0
```
- turn on display
```sh
$ ./ssd1306_bin -d 1
```
#### inverting display
- normal oled (0 is off, 1 is on)
```sh
$ ./ssd1306_bin -i 0
```
- invert oled (0 is on, 1 is off)
```sh
$ ./ssd1306_bin -i 1
```
#### print words
- write line "Hello World"
```sh
$ ./ssd1306_bin -l "Hello World"
```
- write message "alpha\nbravo\ncharlie\ndelta" (please place \n for next line)
```sh
$ ./ssd1306_bin -m "alpha\nbravo\ncharlie\ndelta"
```
#### I2C device address (default is /dev/i2c-0)
- using /dev/i2c-1
```sh
$ ./ssd1306_bin -n 1
```
#### rotate display
- normal orientation
```sh
$ ./ssd1306_bin -r 0
```
- turn 180 orientation
```sh
$ ./ssd1306_bin -r 180
```
#### set cursor location
- set XY cursor 8,1(x is column, 8 columns skipping, y is row, 2nd line)
```sh
$ ./ssd1306_bin -x 8 -y 1
```

## GPIO

Paths in Sysfs

=--------------

There are three kinds of entries in /sys/class/gpio:

   -    Control interfaces used to get userspace control over GPIOs;

   -    GPIOs themselves; and

   -    GPIO controllers ("gpio_chip" instances).

That's in addition to standard files including the "device" symlink.

The control interfaces are write-only:

    /sys/class/gpio/

        "export" ... Userspace may ask the kernel to export control of
        a GPIO to userspace by writing its number to this file.

        Example:  "echo 19 > export" will create a "gpio19" node
        for GPIO #19, if that's not requested by kernel code.

        "unexport" ... Reverses the effect of exporting to userspace.

        Example:  "echo 19 > unexport" will remove a "gpio19"
        node exported using the "export" file.

GPIO signals have paths like /sys/class/gpio/gpio42/ (for GPIO #42)
and have the following read/write attributes:

    /sys/class/gpio/gpioN/

    "direction" ... reads as either "in" or "out". This value may
        normally be written. Writing as "out" defaults to
        initializing the value as low. To ensure glitch free
        operation, values "low" and "high" may be written to
        configure the GPIO as an output with that initial value.

        Note that this attribute *will not exist* if the kernel
        doesn't support changing the direction of a GPIO, or
        it was exported by kernel code that didn't explicitly
        allow userspace to reconfigure this GPIO's direction.

    "value" ... reads as either 0 (low) or 1 (high). If the GPIO
        is configured as an output, this value may be written;
        any nonzero value is treated as high.

        If the pin can be configured as interrupt-generating interrupt
        and if it has been configured to generate interrupts (see the
        description of "edge"), you can poll(2) on that file and
        poll(2) will return whenever the interrupt was triggered. If
        you use poll(2), set the events POLLPRI and POLLERR. If you
        use select(2), set the file descriptor in exceptfds. After
        poll(2) returns, either lseek(2) to the beginning of the sysfs
        file and read the new value or close the file and re-open it
        to read the value.

    "edge" ... reads as either "none", "rising", "falling", or
        "both". Write these strings to select the signal edge(s)
        that will make poll(2) on the "value" file return.

        This file exists only if the pin can be configured as an
        interrupt generating input pin.

    "active_low" ... reads as either 0 (false) or 1 (true). Write
        any nonzero value to invert the value attribute both
        for reading and writing. Existing and subsequent
        poll(2) support configuration via the edge attribute
        for "rising" and "falling" edges will follow this
        setting.

## PWM

#### 1. Export PWM channel 0 from pwmchip0
echo 0 > /sys/class/pwm/pwmchip0/export

#### 2. Set the PWM period (in nanoseconds)
Example: 20 kHz = 50,000 ns

echo 50000 > /sys/class/pwm/pwmchip0/pwm0/period

#### 3. Set the duty cycle (in nanoseconds)
Example: 25% duty = 12,500 ns

echo 12500 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

#### 4. Enable the PWM output
echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable

========================

--- Test is running now ---

Connect a scope/logic analyzer to the configured pin

========================

#### 5. Change duty cycle while running (optional)
echo 25000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle   # 50% duty

echo 37500 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle   # 75% duty

#### 6. Disable PWM output when done
echo 0 > /sys/class/pwm/pwmchip0/pwm0/enable

#### 7. Unexport PWM channel to clean up
echo 0 > /sys/class/pwm/pwmchip0/unexport

