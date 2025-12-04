
#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"
#pragma GCC optimize ("O0")


int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    uint16_t LED_pin = 10;
    gpio_init(LED_pin);
    gpio_set_dir(LED_pin, GPIO_OUT);

    while(1) {
        gpio_put(LED_pin, !gpio_get(LED_pin));
        uint32_t k;
        for (int i = 0; i < 30; i++) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
}

