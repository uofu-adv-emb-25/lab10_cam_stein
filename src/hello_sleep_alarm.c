/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Copyright 2020 (c) 2020 Raspberry Pi (Trading) Ltd.

// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
// following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//    disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/sleep.h"

static bool awake;

static void alarm_sleep_callback(uint alarm_id) {
    printf("alarm woke us up\n");
    uart_default_tx_wait_blocking();
    awake = true;
    hardware_alarm_set_callback(alarm_id, NULL);
    hardware_alarm_unclaim(alarm_id);
}

int main() {

    stdio_init_all();
    printf("Hello Alarm Sleep!\n");

    do {
        printf("Awake for 10 seconds\n");
        sleep_ms(1000 * 10);

        printf("Switching to XOSC\n");

        // Wait for the fifo to be drained so we get reliable output
        uart_default_tx_wait_blocking();

        // Set the crystal oscillator as the dormant clock source, UART will be reconfigured from here
        // This is only really necessary before sending the pico dormant but running from xosc while asleep saves power
        sleep_run_from_xosc();
        awake = false;

        // Go to sleep until the alarm interrupt is generated after 10 seconds
        printf("Sleeping for 10 seconds\n");
        uart_default_tx_wait_blocking();

        if (sleep_goto_sleep_for(10000, &alarm_sleep_callback)) {
            // Make sure we don't wake
            while (!awake) {
                printf("Should be sleeping\n");
            }
        }

        // Re-enabling clock sources and generators.
        sleep_power_up();
    } while(true);

    return 0;
}