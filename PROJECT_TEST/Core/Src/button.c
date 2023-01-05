/*
 * button.c
 *
 *  Created on: Dec 30, 2022
 *      Author: ADMIN
 */

#include "button.h"

int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}; //array for num of buttons
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int button_flag[NUM_OF_BUTTON] = {0, 0, 0};

int Button[NUM_OF_BUTTON] = {PA5_Pin, PA6_Pin, PA7_Pin};
int Port[NUM_OF_BUTTON] = {PA5_GPIO_Port, PA6_GPIO_Port, PA7_GPIO_Port};
int TimeOutForKeyPress =  300;

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}



void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int index = 0; index < NUM_OF_BUTTON; index++){
		KeyReg2[index] = KeyReg1[index];
		KeyReg1[index] = KeyReg0[index];
		KeyReg0[index] = HAL_GPIO_ReadPin(Port[index], Button[index]);
		if ((KeyReg1[index] == KeyReg0[index]) && (KeyReg1[index] == KeyReg2[index])){
			if (KeyReg2[index] != KeyReg3[index]){
				KeyReg3[index] = KeyReg2[index];

				if (KeyReg3[index] == PRESSED_STATE){
					TimeOutForKeyPress = 300;
					subKeyProcess(index);
				}
			}
			else{
				TimeOutForKeyPress--;
				if(TimeOutForKeyPress == 0) KeyReg3[index] = NORMAL_STATE;
			}
		}
	}
}

