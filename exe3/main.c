#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_VERDE = 26;
const int BTN_PIN_VERMELHO= 28;



const int LED_PIN_VERMELHO = 4; 
const int LED_PIN_VERDE = 6;
int main() {
  stdio_init_all();

  // Inicializando os Botões 

  gpio_init(BTN_PIN_VERDE);
  gpio_set_dir(BTN_PIN_VERDE, GPIO_IN);
  gpio_pull_up(BTN_PIN_VERDE);

  gpio_init(BTN_PIN_VERMELHO);
  gpio_set_dir(BTN_PIN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_PIN_VERMELHO);

  // Inicializando os Leds 

  gpio_init(LED_PIN_VERDE);
  gpio_set_dir(LED_PIN_VERDE, GPIO_OUT);

  gpio_init(LED_PIN_VERMELHO);
  gpio_set_dir(LED_PIN_VERMELHO , GPIO_OUT);

  // Estados 
  bool estado_led_verde = false;
  bool estado_led_vermelho = false;
  
  while (true) {

    if (!gpio_get(BTN_PIN_VERMELHO)) {
      estado_led_vermelho = !estado_led_vermelho;
      gpio_put(LED_PIN_VERMELHO , estado_led_vermelho);
      while (!gpio_get(BTN_PIN_VERMELHO)) {
      };
    }
   
    if (!gpio_get(BTN_PIN_VERDE)) {
      estado_led_verde = !estado_led_verde;
      gpio_put(LED_PIN_VERDE , estado_led_verde);
      while (!gpio_get(BTN_PIN_VERDE)) {
      };
    }
  }
}
