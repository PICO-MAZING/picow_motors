#include <iostream>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"

#define LEFT 26
#define MIDDLE 27
#define RIGHT 28

int main()
{
    stdio_init_all();

    gpio_init(LEFT);
    gpio_init(MIDDLE);
    gpio_init(RIGHT);

    gpio_set_dir(LEFT, GPIO_IN);
    gpio_set_dir(MIDDLE, GPIO_IN);
    gpio_set_dir(RIGHT, GPIO_IN);

    gpio_pull_up(LEFT);
    gpio_pull_up(MIDDLE);
    gpio_pull_up(RIGHT);

    while (true)
    {
        uint8_t left = gpio_get(sensor);
        uint8_t middle = gpio_get(sensor->left);
        uint8_t right = gpio_get(sensor->left);
        printf("%d %d %d ---  \n", gpio_get(LEFT), gpio_get(MIDDLE), gpio_get(RIGHT));
        sleep_ms(1000);
    }

    return 0;
}