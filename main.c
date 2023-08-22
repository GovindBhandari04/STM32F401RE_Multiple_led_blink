#include <stm32f4xx.h>
#define LED1  (1U<<1)
#define LED2  (1U<<2)
#define LED3  (1U<<3)
#define LED4  (1U<<4)
#define GPIOAEN  (1U<<0)

int main()
{
	RCC -> AHB1ENR |= GPIOAEN;

	GPIOA -> MODER |=(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8);
	GPIOA -> MODER &= ~(1U<<3) & ~(1U<<5) & ~(1U<<7) & ~(1U<<9);

	while(1)
	{
		GPIOA -> ODR^= LED1;
		GPIOA -> ODR^= LED2;
		GPIOA -> ODR^= LED3;
		GPIOA -> ODR^= LED4;
		for(int i=0;i<1000000;i++)
		{}
	}

	return 0;
}
