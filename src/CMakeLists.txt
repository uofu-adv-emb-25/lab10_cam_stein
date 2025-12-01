# This is the main binary. List your C files here.
add_executable(hello_sleep_alarm
hello_sleep_alarm.c
    )

pico_set_program_name(hello_sleep_alarm "test")
pico_set_program_version(hello_sleep_alarm "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_sleep_alarm 0)
pico_enable_stdio_usb(hello_sleep_alarm 1)

# Add the libraries to the build
target_link_libraries(hello_sleep_alarm PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_sleep_alarm PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_sleep_alarm)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash ${PICOTOOL} load -f $<TARGET_FILE:hello_sleep_alarm> DEPENDS hello_sleep_alarm)

add_custom_target(openocd_flash ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000; program "$<TARGET_FILE:hello_sleep_alarm>" verify reset exit' DEPENDS hello_sleep_alarm)
