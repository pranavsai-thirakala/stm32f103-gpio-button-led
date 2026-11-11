#include <stdint.h>
#include"stm32f10x.h"
/*
#define GPIOA_BASE 0x40010800
#define RCC_BASE   0x40021000
*/



/* ================= RCC ================= 

typedef struct
{
    volatile uint32_t RCC_CR;        // 0x00
    volatile uint32_t RCC_CFGR;      // 0x04
    volatile uint32_t RCC_CIR;       // 0x08
    volatile uint32_t RCC_APB2RSTR;  // 0x0C
    volatile uint32_t RCC_APB1RSTR;  // 0x10
    volatile uint32_t RCC_AHBENR;    // 0x14
    volatile uint32_t RCC_APB2ENR;   // 0x18
    volatile uint32_t RCC_APB1ENR;   // 0x1C
    volatile uint32_t RCC_BDCR;      // 0x20
    volatile uint32_t RCC_CSR;       // 0x24
    volatile uint32_t RCC_AHBSTR;    // 0x28
    volatile uint32_t RCC_CFGR2;     // 0x2C
} RCC_Def;

#define RCC ((RCC_Def *)RCC_BASE)



typedef struct
{
    volatile uint32_t CRL;   // 0x00
    volatile uint32_t CRH;   // 0x04
    volatile uint32_t IDR;   // 0x08
    volatile uint32_t ODR;   // 0x0C
    volatile uint32_t BSRR;  // 0x10
    volatile uint32_t BRR;   // 0x14
    volatile uint32_t LCKR;  // 0x18
} GPIO_Def;

#define GPIOA ((GPIO_Def *)GPIOA_BASE)

================ Delay ================= 
*/

void delay(uint16_t t)
{
    volatile uint32_t i;

    for(uint16_t j = 0; j < t; j++)
    {
        for(i = 0; i < 6000; i++)
        {
        }
    }
}


/* ================= Main ================= */

int main(void)
{
    /* 1. Enable GPIOA clock */
  
RCC->APB2ENR |= (1 << 2);
	RCC->APB2ENR |=(1<<3);
	RCC->APB2ENR |=(1<<3);
	

    /* 2. Configure PA2 as output push-pull, 50 MHz */

    /*
       PA2 uses CRL bits 11:8

       CNF2 = 00  -> General purpose push-pull
       MODE2 = 11 -> Output, 50 MHz

       Therefore:
       bits 11:8 = 0011
    */

    GPIOA->CRL &= ~(0xF << 8); //Clear existing configuration
    GPIOA->CRL |=  (0x3 << 8);
	
	GPIOB->CRL &=~ (0xF<<20);
	GPIOB->CRL |=(0x4 << 20);
	
		GPIOB->CRL &=~ (0xF<<20);
	GPIOB->CRL |=(0x4 << 12);


    /* 3. Continuously toggle PA2 

    while(1)
    {
		if(GPIOD->BSRR=(1<<5) )
		{
       
        GPIOA->BSRR = (1 << 2);
		}
		else

       // delay(100);

     
        GPIOA->BRR = (1 << 2);

       // delay(100);
    }*/
		/*while(1){
			
		if(GPIOB->IDR & (1 << 5))
        {
					GPIOA->BRR = (1 << 2);
            // Turn ON PA2
           
        }
        else
        {
            // Turn OFF PA2
            GPIOA->BSRR = (1 << 2);
        }
				
				
}
*/

		}