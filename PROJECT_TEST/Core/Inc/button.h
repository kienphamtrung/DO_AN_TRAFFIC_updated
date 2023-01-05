/*
 * button.h
 *
 *  Created on: Dec 30, 2022
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define NUM_OF_BUTTON 3
int isButtonPressed(int index);

void subKeyProcess(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */


