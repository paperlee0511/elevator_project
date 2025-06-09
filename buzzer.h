#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"
#include <stdbool.h>

#define  Do   383
#define  Re   340
#define  Mi   304
#define  Fa   287
#define  Sol  255
#define  Ra   227
#define  Si   203
#define  Do1  191
#define  mute 0

#define qNote  300
#define wNote  600

// 상태 정의
typedef enum {
    BUZZER_IDLE,
    BUZZER_PLAYING,
    BUZZER_REST
} BuzzerState;

extern BuzzerState buzzer_state;

void buzzer_on();
void buzzer_off();
void buzzer_update();

#endif /* INC_BUZZER_H_ */
