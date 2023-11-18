/*
 * tim.h
 *
 *  Created on: Nov 18, 2023
 *      Author: ADMIN
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern TIM_HandleTypeDef htim2;

void MX_TIM2_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_TIM_H_ */
