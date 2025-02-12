#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


const int BTN_PIN_VERMELHO = 28;

const int LED_PIN_VERMELHO = 5; 
const int LED_PIN_ROXO = 8;
const int LED_PIN_AZUL = 11;
const int LED_PIN_AMARELO = 15;


int main() {
  stdio_init_all();

  // Inicializando o Botão 

  gpio_init(BTN_PIN_VERMELHO);
  gpio_set_dir(BTN_PIN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_PIN_VERMELHO);

  //Inicializando LEDS 

  gpio_init(LED_PIN_VERMELHO);
  gpio_set_dir(LED_PIN_VERMELHO, GPIO_OUT);

  gpio_init(LED_PIN_ROXO);
  gpio_set_dir(LED_PIN_ROXO , GPIO_OUT);

  gpio_init(LED_PIN_AZUL);
  gpio_set_dir(LED_PIN_AZUL , GPIO_OUT);
  
  gpio_init(LED_PIN_AMARELO);
  gpio_set_dir(LED_PIN_AMARELO , GPIO_OUT);


  while (true) {
    if (!gpio_get(BTN_PIN_VERMELHO)) {
      gpio_put(LED_PIN_VERMELHO , 1);
      sleep_ms(300);
      gpio_put(LED_PIN_VERMELHO , 0);
      gpio_put(LED_PIN_ROXO , 1);
      sleep_ms(300);
      gpio_put(LED_PIN_ROXO , 0);
      gpio_put(LED_PIN_AZUL , 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AZUL , 0);
      gpio_put(LED_PIN_AMARELO , 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AMARELO , 0);

      while (!gpio_get(BTN_PIN_VERMELHO)) {
      };
    }
  }
}
