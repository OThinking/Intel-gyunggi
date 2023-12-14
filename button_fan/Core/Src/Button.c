/*
 * Button.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC1
 */
#include "Button.h"




void Button_Init(Button *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  btn->GPIOx = GPIOx;
  btn->GPIO_Pin = GPIO_Pin;
  btn->preSrate = RELEASED;
}
uint8_t Button_getState(Button *btn)
{
  uint8_t curState = HAL_GPIO_ReadPin(btn->GPIOx, btn->GPIO_Pin);
  if((curState == PUSHED) && (btn->preSrate == RELEASED))
  {
    btn->preSrate = PUSHED;
    return ACT_PUSHED;
  }
  else if((curState != PUSHED) && (btn->preSrate == PUSHED))
  {
    btn->preSrate = RELEASED;
    return ACT_RELEASED;
  }
}

