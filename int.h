
#ifndef INC_INT_H_
#define INC_INT_H_

#include "main.h"
#include <stdbool.h>


extern volatile uint8_t rxData;
extern volatile bool stopDelay;
extern volatile uint8_t targetData;

void floorCheck();
void intInit();
void intOn();
void enableInterrupt(uint16_t GPIO_PIN);
void disableInterrupt(uint16_t GPIO_PIN);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



#endif /* INC_INT_H_ */
