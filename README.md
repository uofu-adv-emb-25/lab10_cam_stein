Activity 1:  
The external power supply pin: VSYS  
Voltage: 1.8V to 5.5V  

Activity 2:  
WAKE_EN default = 0xFFFF_FFFF  
SLEEP_EN default = 0xFFFF_FFFF  
ENABLE default = 0x0000_0000  

Activity 3:  
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
    I = 28.37 mA  
    V = 5V  
    P = V * I = 28.37 * 5 = 141.85 mW  

    At 10kHz:  
    I = 28.38 mA  
    V = 5V  
    P = V * I = 28.38 * 5 = 141.9 mW  

    At 100kHz:  
    I = 28.41 mA  
    V = 5V  
    P = V * I = 28.41 * 5 = 142.05 mW  

    At 2MHz:  
    I = 26.48 mA  
    V = 5V  
    P = V * I = 26.48 * 5 = 132.4 mW  

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
