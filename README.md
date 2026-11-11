# Button-Controlled LED (STM32F103, bare-metal)

Reads a push button on PB5 and drives an LED on PA2 using direct
register access, with no HAL.

## Hardware
- STM32F103 [C6 / C8T6] board
- LED on PA2 with [resistor value]
- Push button on PB5 to GND (internal pull-up)

## How it works
1. Enable GPIOA and GPIOB clocks in RCC->APB2ENR
2. Configure PA2 as push-pull output through GPIOA->CRL
3. Configure PB5 as pull-up input through GPIOB->CRL and ODR
4. Poll PB5 in a loop and set or reset PA2

## Tools
Keil uVision, Embedded C, proteus professional.
