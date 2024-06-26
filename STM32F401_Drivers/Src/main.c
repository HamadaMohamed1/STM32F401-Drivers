/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  *  Created on: Mar 14, 2024
  *      Author: hamada
  ******************************************************************************/

#include "../Inc/main.h"

Std_RetType_t ret = RET_OK;

PinConfig_t PC13 = { .Port = PORTC ,.Pin = PIN13,.Mode = OUTPUT ,.Type=PUSH_PULL
		, .Speed = MEDUIM , .PullType =NO_PULL
};


USART_Config_t my_usart = {.baud_rate = BAUD_9600 , .hardware_control_flow = HARDWARE_FLOW_CONTROL_IS_NOT_USED ,
		.mode = RX_TX , .oversampling = OVERSAMPLING_BY_16 , .parity = WITHOUT_PARITY ,
		.source = USART_2 ,.stop_bits = ONE_STOP_BIT , .type = ASYNCHRONOUS , .word_length = EGHIT_BITS , .tx_mode = POLLING , .rx_mode = POLLING

};
PinConfig_t PA2_TX = { .Port = PORTA ,.Pin = PIN2,.Mode = ALTERNATE_FUNCTION ,.Type=PUSH_PULL
		, .Speed = MEDUIM , .PullType =PULL_UP ,.AltFunc = AF7
};

PinConfig_t PA3_RX = { .Port = PORTA ,.Pin = PIN3,.Mode = ALTERNATE_FUNCTION ,.Type=PUSH_PULL
		, .Speed = MEDUIM , .PullType =PULL_UP ,.AltFunc = AF7
};


I2C_config_t my_i2c = { .master_or_slave = SLAVE_I2C ,.source = I2C_1 ,.speed = UP_TO_100KHZ

};


int main(void)
{
	SystemClock_Config();
	Systick_init();
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOC_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	//RCC_SYSCFG_CLK_ENABLE();
	scb_set_priority_group(GROUP_PRIORITIES_4_SUB_PRIORITIES_4);	  // preemption
	//cb_set_priority_group(GROUP_PRIORITIES_1_SUB_PRIORITIES_16);   // no preemption because 1 group
	GPIO_Pin_init(&PC13);


	RCC_USART2_CLK_ENABLE();


	RCC_I2C1_CLK_ENABLE();
	RCC_I2C2_CLK_ENABLE();
	RCC_I2C3_CLK_ENABLE();


//	GPIO_Pin_init(&PA2_TX);
//	GPIO_Pin_init(&PA3_RX);
//	USART_init(&my_usart);



//		uint8_t txData[] = {0x01, 0x02, 0x03, 0x04};
//	    uint8_t rxData[4];
//
//	    // Send data
//	    //SPI_send(&my_spi, txData, sizeof(txData));
//	    // Receive data
//
//
//		uint8_t ch[] = "hamada mohamed elsayed";
//		uint8_t str[20];


		//USART_receive_string_blocking(&my_usart , str);

		//USART_send_string_blocking(&my_usart, str);

    /* Loop forever */
	while(1)
	{
		GPIO_Toggle_Pin_Value(PORTC, 13);
		delay_ms(500);
	}

}


Std_RetType_t SystemClock_Config(void)
{
	Std_RetType_t ret = RET_OK;
	RCC_OscInitTypedef RCC_OscInitStruct ={0};
	RCC_ClkInitTypedef RCC_ClkInitStruct ={0};

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSE_State = RCC_HSE_ON;
	ret = HALL_RCC_OscConfig(&RCC_OscInitStruct);

	RCC_ClkInitStruct.AHBClkDivider  =RCC_SYSCLK_AHB_DIV1;
	RCC_ClkInitStruct.APB1ClkDivider =RCC_HCLK_APB1_DIV1;
	RCC_ClkInitStruct.APB2ClkDivider =RCC_HCLK_APB2_DIV1;
	ret = HALL_RCC_ClockConfig(&RCC_ClkInitStruct);
	return ret;
}


