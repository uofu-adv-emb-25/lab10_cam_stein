# Renode setup
The Raspberry Pico needs configuration files for Renode to work properly.

* On MacOS, the installation location is `/Applications/Renode.app/Contents/MacOs`
* On Linux, the location for Debian, Fedora, and Arch is `/opt/renode`
* On Windows, the location is `C://Program Files/Renode`

To add the Pico configuration files:
1. Copy `rp2040_spinlock.py` and `rp2040_divider.py` to the `scripts/pydev` directory of your Renode installation.
1. Copy `rpi_pico_rp2040_w.repl` to the `platforms/cpus` directory.


1. Blink an LED, using sleep_ms to delay iterations.
I = 31.78 mA
V = 5V
P = V * I = 31.78 * 5 = 158.9 mW

2. Blink an LED, using FreeRTOS with a thread.
I = 31.55 mA
V = 5V
P = V * I = 31.55 * 5 = 157.75 mW

3. Run a busy loop to get 100% CPU utilization
I = 31.7 mA
V = 5V
P = V * I = 31.7 * 5 = 158.5 mW

4. Interrupt to toggle a GPIO 
At 1kHz:

At 10kHz:

At 100kHz:

At 2MHz:

5. Sleep demo
First 10 seconds:
I = 18 mA
V = 5V
P = V * I = 18 * 5 = 90 mW
Next 10 second:
I = 1.52 mA
V = 5V
P = V * I = 1.52 * 5 = 7.6 mW

6. Dormant demo
First 10 seconds:
I = 17.83 mA
V = 5V
P = V * I = 17.83 * 5 = 89.15 mW
Next 10 seconds:
I = 0.72 mA
V = 5V
P = V * I = 0.72 * 5 = 3.6 mW