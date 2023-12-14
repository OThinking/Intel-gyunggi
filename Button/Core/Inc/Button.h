/*
 * Button.h
 *
 *  Created on: Oct 19, 2023
 *      Author: mujukpopo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"

typedef struct _button{
  GPIO_TypeDef  *GPIOx;
  uint16_t      GPIO_Pin;
  uint16_t      preState;
}Button;

enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSHED, ACT_RELEASED};

void Button_Init(Button *btn, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t Button_getState(Button *btn);




#endif /* INC_BUTTON_H_ */












