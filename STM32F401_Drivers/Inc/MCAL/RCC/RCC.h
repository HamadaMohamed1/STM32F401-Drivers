/*
 * RCC.h
 *
 *  Created on: Mar 14, 2024
 *      Author: hamada
 */

#ifndef MCAL_RCC_RCC_H_
#define MCAL_RCC_RCC_H_

/******************* Includes *******************/
#include "../../LIBRARY/Common_Macros.h"
#include "../../LIBRARY/Stm32f401xx.h"
/******************* Macro Declarations *******************/
/******************* AHB Clock Source*********************/
#define RCC_SYSCLK_AHB_DIV1	  		RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_AHB_DIV2	  		RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_AHB_DIV4	  		RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_AHB_DIV8	  		RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_AHB_DIV16	  	RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_AHB_DIV64  		RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_AHB_DIV128  		RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_AHB_DIV256 		RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_AHB_DIV512 		RCC_CFGR_HPRE_DIV512
/******************* APB2 Clock Source*********************/
#define RCC_HCLK_APB2_DIV1			RCC_CFGR_PPRE2_DIV1
#define RCC_HCLK_APB2_DIV2			RCC_CFGR_PPRE2_DIV2
#define RCC_HCLK_APB2_DIV4			RCC_CFGR_PPRE2_DIV4
#define RCC_HCLK_APB2_DIV8			RCC_CFGR_PPRE2_DIV8
#define RCC_HCLK_APB2_DIV16			RCC_CFGR_PPRE2_DIV16
/******************* APB1 Clock Source*********************/
#define RCC_HCLK_APB1_DIV1			RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_APB1_DIV2			RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_APB1_DIV4			RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_APB1_DIV8			RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_APB1_DIV16			RCC_CFGR_PPRE1_DIV16

/******************* Macro Function Declarations *******************/
#define RCC_GPIOA_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOA_POS))
#define RCC_GPIOB_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOB_POS))
#define RCC_GPIOC_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOC_POS))
#define RCC_GPIOD_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOD_POS))
#define RCC_GPIOE_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOE_POS))
#define RCC_GPIOH_CLK_ENABLE()	(SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOH_POS))


#define RCC_GPIOA_CLK_DISABLE()	(CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOA_POS))
#define RCC_GPIOB_CLK_DISABLE()	(CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOB_POS))
#define RCC_GPIOC_CLK_DISABLE()	(CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOC_POS))
#define RCC_GPIOD_CLK_DISABLE()	(CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOD_POS))
#define RCC_GPIOE_CLK_DISABLE()	(CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOE_POS))
#define RCC_GPIOH_CLK_DISABLE() (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOH_POS))



/******************** APB1 Peripherals ******************************/
#define RCC_USART2_CLK_ENABLE()		(SET_BIT(RCC->APB1ENR , RCC_APB1ENR_USART2_POS))
#define RCC_USART2_CLK_DISABLE()	(CLEAR_BIT(RCC->APB1ENR , RCC_APB1ENR_USART2_POS))

/******************** APB2 Peripherals ******************************/
#define RCC_SYSCFG_CLK_ENABLE()		(SET_BIT(RCC->APB2ENR , RCC_APB2ENR_SYSCFG_POS))

#define RCC_SYSCFG_CLK_DISABLE()	(CLEAR_BIT(RCC->APB2ENR , RCC_APB2ENR_SYSCFG_POS))


/******************* Data Type Declarations *******************/
typedef struct{
	uint32_t OscillatorType; 	/*@ref RCC_OSCILLATORTYPE*/
	uint32_t HSE_State;			/*@ref RCC_HSE_*/
	uint32_t HSI_State;			/*@ref RCC_HSI_*/
	uint32_t LSE_State;			/*@ref RCC_LSE_*/
	uint32_t LSI_State;			/*@ref RCC_LSI_*/
}RCC_OscInitTypedef;


typedef struct
{
	uint32_t AHBClkDivider;
	uint32_t APB1ClkDivider;
	uint32_t APB2ClkDivider;
}RCC_ClkInitTypedef;

/******************* Interface Declarations *******************/
Std_RetType_t HALL_RCC_OscConfig(RCC_OscInitTypedef *RCC_OscInitStruct);
Std_RetType_t HALL_RCC_ClockConfig(RCC_ClkInitTypedef *RCC_ClockInitStruct);



#endif /* MCAL_RCC_RCC_H_ */
