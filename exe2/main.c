#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN_PIN7 = 7;
int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN7);
  gpio_set_dir(BTN_PIN7, GPIO_IN);
  gpio_pull_up(BTN_PIN7);

  
  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN)) {
      };
    }
    if (!gpio_get(BTN_PIN7)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN7)) {
      };
    }
  }
}
