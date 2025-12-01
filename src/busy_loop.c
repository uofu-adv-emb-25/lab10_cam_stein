#include <stdio.h>

#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"
#pragma GCC optimize ("O0")


int main( void )
{
    while(1) {
    uint32_t k;
    for (int i = 0; i < 30) {
        uint32_t j = 0;
        j = ((~j >> i) + 1) * 27644437;
        k = j;
    }
    }
}