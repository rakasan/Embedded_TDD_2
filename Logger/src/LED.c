#include "LED.h"

#define LED_PORT         LPC_GPIO1

#define LED_0           (18U)
#define LED_1           (20U)
#define LED_2           (21U)
#define LED_3           (23U)

#define LED_PINSEL   LPC_PINCON->PINSEL3
#define LED_PINMODE  LPC_PINCON->PINMODE3

#define LED_PIN_BIT(bit) (0x3u << ((bit & 0x0F) << 1))

void LED_Init(void)
{
    LED_PORT->FIOSET = (BIT_TO_MASK(LED_0)|BIT_TO_MASK(LED_1)|BIT_TO_MASK(LED_2)|BIT_TO_MASK(LED_3));
    LED_PORT->FIODIR =  (BIT_TO_MASK(LED_0)|BIT_TO_MASK(LED_1)|BIT_TO_MASK(LED_2)|BIT_TO_MASK(LED_3));

    //Clear pin select bits for bits we plan to use to make them GPIO pins
    LED_PINSEL = ~( LED_PIN_BIT(LED_0) | LED_PIN_BIT(LED_1) | LED_PIN_BIT(LED_2) | LED_PIN_BIT(LED_3));

    //Set the mode for the bits we plan to use to make them all use pulldown resistors
    LED_PINMODE = ~( LED_PIN_BIT(LED_0) | LED_PIN_BIT(LED_1) | LED_PIN_BIT(LED_2) | LED_PIN_BIT(LED_3));
}