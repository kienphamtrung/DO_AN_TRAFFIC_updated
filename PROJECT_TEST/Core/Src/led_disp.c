/*
 * led_disp.c
 *
 *  Created on: Jan 2, 2023
 *      Author: ADMIN
 */


/*
 * led_disp.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "led_disp.h"

void toggleREDS(){
	HAL_GPIO_TogglePin(RED_WEST_GPIO_Port, RED_WEST_Pin);
	HAL_GPIO_TogglePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin);
	HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, SET);
	HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, SET);
}
void toggleGREENs(){
	HAL_GPIO_TogglePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin);
	HAL_GPIO_TogglePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin);
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, SET);
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, SET);
}
void toggleYELLOWs(){
	HAL_GPIO_TogglePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin);
	HAL_GPIO_TogglePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin);
	HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, SET);
	HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, SET);
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, SET);
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, SET);
}
void resetREDs(){
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, SET);
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, SET);
}

void enableRED_WEST(){
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, RESET);
	HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, SET);
}
void enableYELLOW_WEST(){
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, SET);
	HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, RESET);
}
void enableGREEN_WEST(){
	HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, SET);
	HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, SET);
}

void enableRED_NORTH(){
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, RESET);
	HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, SET);
}
void enableGREEN_NORTH(){
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, SET);
	HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, SET);
}
void enableYELLOW_NORTH(){
	HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, SET);
	HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, RESET);
}

const uint8_t SEG7[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void display7SEG1(int num){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, ((SEG7[num]>>0)&0x01));
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((SEG7[num]>>1)&0x01));
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((SEG7[num]>>2)&0x01));
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((SEG7[num]>>3)&0x01));
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((SEG7[num]>>4)&0x01));
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((SEG7[num]>>5)&0x01));
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((SEG7[num]>>6)&0x01));
}

//void display7SEG2(int num){
//	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ((SEG7[num]>>0)&0x01));
//	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ((SEG7[num]>>1)&0x01));
//	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ((SEG7[num]>>2)&0x01));
//	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ((SEG7[num]>>3)&0x01));
//	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ((SEG7[num]>>4)&0x01));
//	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ((SEG7[num]>>5)&0x01));
//	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ((SEG7[num]>>6)&0x01));
//}
//
//void display_chuc(int num1, int num2){
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//	display7SEG1(num1/10);
//
//	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//	display7SEG2(num2/10);
//}
//
//void display_don_vi(int num1, int num2){
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//	display7SEG1(num1%10);
//
//	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//	display7SEG2(num2%10);
//}
