#include "stm32f10x.h"                  // Device header
#include "Delay.h"


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;// 推挽输出：高低电平均有输入能力
	// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;// 开漏输出：高电平没有输入能力 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	while(1)
	{
		// 亮
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		
		// 灭
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);

		// 亮
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);

		// 灭
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);

	}
}
