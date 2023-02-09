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
    gpio_set_dir(17, GPIO_OUT);
    gpio_set_dir(18, GPIO_OUT);
    gpio_put(17, 1);

    adc_gpio_init(28);
    adc_select_input(2);

    uint slice_num = pwm_gpio_to_slice_num(16);
    pwm_set_wrap(slice_num, 60000);
    pwm_set_enabled(slice_num, true);
    // pwm_set_chan_level(slice_num, PWM_CHAN_A, 10000);
    while (true)
    {
        /*
        // tight_loop_contents();
        //;
        // std::cout << std::to_string(pwm_get_counter(slice_num)) << "\n";
        puts("On!");
        std::cout << std::to_string(adc_read()) << "\n";
        pwm_set_counter(slice_num, 0);
        pwm_set_chan_level(slice_num, PWM_CHAN_A, 10000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
        puts("Off!");
        std::cout << std::to_string(adc_read()) << "\n";
        pwm_set_counter(slice_num, 0);
        pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(3000);
        */
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
    }

    return 0;
}