/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void main_task(__unused void *params) {
    uint16_t LED_pin = 10;
    gpio_init(LED_pin);
    gpio_set_dir(LED_pin, GPIO_OUT);
    
    while (1) {
        gpio_put(LED_pin, !gpio_get(LED_pin));
        sleep_ms(500);
    }
}

//Blink an LED, using FreeRTOS with a thread.
int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";

    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}

// //Blink an LED, using sleep_ms to delay iterations.
// int main( void )
// {
//     stdio_init_all();
//     const char *rtos_name;
//     rtos_name = "FreeRTOS";
//     uint16_t LED_pin = 10;
//     gpio_init(LED_pin);
//     gpio_set_dir(LED_pin, GPIO_OUT);

//     while (1) {
//         gpio_put(LED_pin, !gpio_get(LED_pin));
//         sleep_ms(500);
//     }
    
//     return 0;
// }