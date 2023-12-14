/*
 * Button.c
 *
 *  Created on: Oct 19, 2023
 *      Author: mujukpopo
 */
#include "Button.h"


void Button_Init(Button *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  btn->GPIOx = GPIOx;
  btn->GPIO_Pin = GPIO_Pin;
  btn->preState = RELEASED;
}

uint8_t Button_getState(Button *btn)
{
  uint8_t curState = HAL_GPIO_ReadPin(btn->GPIOx, btn->GPIO_Pin);
  if((curState == PUSHED) && (btn->preState == RELEASED))
  {
    HAL_Delay(10);
    btn->preState = PUSHED;
    return ACT_PUSHED;
  }
  else if((curState != PUSHED) && (btn->preState == PUSHED))
  {
    HAL_Delay(10);
    btn->preState = RELEASED;
    return ACT_RELEASED;
  }
  return NO_ACT;
}






