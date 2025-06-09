
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include <stdbool.h>

typedef struct
{
	GPIO_TypeDef 	*port;
	uint16_t 			pinNumber;
	GPIO_PinState onState;
}BUTTON_CONTROL;

extern bool buttonState[7];
extern volatile uint8_t btnSet;

bool buttonGetPressed(uint8_t num);
void buttonSet();
void scanButtons();




#endif /* INC_BUTTON_H_ */
