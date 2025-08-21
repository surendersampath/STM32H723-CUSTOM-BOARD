#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);

static void init_led(const struct gpio_dt_spec *l) {
	if (!device_is_ready(l->port)) return;
	gpio_pin_configure_dt(l, GPIO_OUTPUT_INACTIVE); /* inactive = off (active-low) */
}

int main(void)
{
	init_led(&led0);
	init_led(&led1);

	while (1) {
		gpio_pin_toggle_dt(&led0);
		gpio_pin_toggle_dt(&led1);
		k_msleep(250);
	}
}
