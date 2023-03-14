#include <iostream>
#include <string>
#include <charconv>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"

int main()
{
    stdio_init_all();

    cyw43_arch_init();

    adc_init();

    gpio_set_function(16, GPIO_FUNC_PWM);
    gpio_set_function(17, GPIO_FUNC_SIO);
    gpio_set_function(18, GPIO_FUNC_SIO);
    gpio_set_function(19, GPIO_FUNC_SIO);
    gpio_set_function(20, GPIO_FUNC_SIO);
    gpio_set_function(22, GPIO_FUNC_PWM);

    gpio_set_dir(17, GPIO_OUT);
    gpio_set_dir(18, GPIO_OUT);
    gpio_set_dir(19, GPIO_OUT);
    gpio_set_dir(20, GPIO_OUT);
    gpio_put(17, 1);
    gpio_put(19, 1);

    adc_gpio_init(27);
    adc_select_input(1);

    uint slice_b = pwm_gpio_to_slice_num(16);
    uint slice_a = pwm_gpio_to_slice_num(22);
    pwm_set_wrap(slice_b, 60000);
    pwm_set_enabled(slice_b, true);

    pwm_set_wrap(slice_a, 60000);
    pwm_set_enabled(slice_a, true);
    // pwm_set_chan_level(slice_num, PWM_CHAN_A, 10000);
    while (true)
    {
        // cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

        // tight_loop_contents();
        //;
        // std::cout << std::to_string(pwm_get_counter(slice_num)) << "\n";
        /*
        int speed = 10000;
        puts("On!");
        std::cout << std::to_string(adc_read()) << "\n";
        pwm_set_counter(slice_a, 0);
        pwm_set_chan_level(slice_a, PWM_CHAN_A, speed);
        pwm_set_counter(slice_b, 0);
        pwm_set_chan_level(slice_b, PWM_CHAN_A, speed);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        //sleep_ms(3000);
        puts("Off!");
        */
        std::cout << std::to_string(adc_read()) << "\n";
        pwm_set_counter(slice_a, 0);
        pwm_set_chan_level(slice_a, PWM_CHAN_A, 0);
        pwm_set_counter(slice_b, 0);
        pwm_set_chan_level(slice_b, PWM_CHAN_A, 0);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        //sleep_ms(1000);

        /*
        if (adc_read() < 2000)
        {
            pwm_set_counter(slice_num, 0);
            pwm_set_chan_level(slice_num, PWM_CHAN_A, 10000);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        }
        else
        {
            pwm_set_counter(slice_num, 0);
            pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        }
        */
    }

    return 0;
}