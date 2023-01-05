/*
 * fsm_manual.c
 *
 *  Created on: Jan 2, 2023
 *      Author: ADMIN
 */
#include "fsm_manual.h"

void fsm_manual_run(){
	if(mode == MODE2){
			switch(Stat_M2_1){
			case INIT:
				Stat_M2_1 = BLINK;
				resetREDs();
				setTimer4(10);
				break;
			case BLINK:
				if(timer4_flag == 1){
					toggleREDS();
					setTimer4(50);
				}
				break;
			default:
				break;
			}

			switch(Stat_M2_2){
			case INIT:
				Stat_M2_2 = SEG1;
				setTimer5(10);
				break;
			case SEG1:
				if(timer5_flag == 1){
					display7SEG1(AUTO_RED);
					setTimer5(50);
				}
				break;
//			case SEG2:
//				if(timer5_flag == 1){
//					display_don_vi(mode, AUTO_RED);
//					Stat_M2_2 = SEG1;
//					setTimer5(25);
//				}
//				break;
			default:
				break;
			}

			switch(Stat_M2_3){
				case INIT:
					if(isButtonPressed(BUTTON2) == 1){
						Stat_M2_3 = INCREASE;
						//temp_RED++;
						AUTO_RED++;
					}
					if(isButtonPressed(BUTTON3) == 1){
						Stat_M2_3 = DECREASE;
						AUTO_RED--;
					}
					break;
				case INCREASE:
					if(isButtonPressed(BUTTON2) == 1){
						//temp_RED++;
						AUTO_RED++;
						if(AUTO_RED >= MAX_COUNT) {
							AUTO_RED = MAX_COUNT;
						}
					}

					if(isButtonPressed(BUTTON3) == 1){
						Stat_M2_3 = DECREASE;
						AUTO_RED--;
						if(AUTO_RED <= MIN_COUNT){
							AUTO_RED = MIN_COUNT;
						}
					}
					break;
				case DECREASE:
					if(isButtonPressed(BUTTON2) == 1){
						Stat_M2_3 = INCREASE;
						//temp_RED++;
						AUTO_RED++;
						if(AUTO_RED >= MAX_COUNT) {
							AUTO_RED = MAX_COUNT;
						}
					}

					if(isButtonPressed(BUTTON3) == 1){
						AUTO_RED--;
						if(AUTO_RED <= MIN_COUNT){
							AUTO_RED = MIN_COUNT;
						}
					}

					break;
				default:
					break;
			}

			if(isButtonPressed(BUTTON1) == 1) mode = MODE3;
		}

//		if(mode == MODE3){
//			switch(Stat_M3_1){
//			case INIT:  //led blink 2Hz
//				Stat_M3_1 = BLINK;
//				setTimer6(10);
//				break;
//			case BLINK:
//				if(timer6_flag == 1){
//					toggleYELLOWs();
//					setTimer6(50);
//				}
//				break;
//			default:
//				break;
//			}
//
//			switch(Stat_M3_2){
//			case INIT:
//				Stat_M3_2 = SEG1;
//				setTimer7(10);
//				break;
//			case SEG1:
//				if(timer7_flag == 1){
//					display_chuc(mode, AUTO_YELLOW);
//					Stat_M3_2 = SEG2;
//					setTimer7(25);
//				}
//				break;
//			case SEG2:
//				if(timer7_flag == 1){
//					display_don_vi(mode, AUTO_YELLOW);
//					Stat_M3_2 = SEG1;
//					setTimer7(25);
//				}
//				break;
//			default:
//				break;
//			}
//
//			switch(Stat_M3_3){
//				case INIT:
//					if(isButtonPressed(BUTTON2) == 1){
//						Stat_M3_3 = INCREASE;
//						//temp_YELLOW++;
//						AUTO_YELLOW++;
//					}
//					break;
//				case INCREASE:
//					if(isButtonPressed(BUTTON2) == 1){
//						AUTO_YELLOW++;
//						if(AUTO_YELLOW >= MAX_COUNT) AUTO_YELLOW = MAX_COUNT;
//					}
//
//					if(isButtonPressed(BUTTON3) == 1) Stat_M3_3 = SAVE;
//					break;
//				case SAVE:
//					//AUTO_YELLOW = temp_YELLOW;
//					mode = MODE1;
//					Setup();
//					break;
//				default:
//					break;
//			}
//
//			if(isButtonPressed(BUTTON1) == 1) mode = MODE4;
//		}

		if(mode == MODE3){
			switch(Stat_M3_1){
			case INIT:  //led blink 2Hz
				Stat_M3_1 = BLINK;
				setTimer8(10);
				break;
			case BLINK:
				if(timer8_flag == 1){
					toggleGREENs();
					setTimer8(50);
				}
				break;
			default:
				break;
			}

			switch(Stat_M3_2){
			case INIT:
				Stat_M3_2 = SEG1;
				setTimer9(10);
				break;
			case SEG1:
				if(timer9_flag == 1){
					display7SEG1(AUTO_GREEN);
					setTimer9(50);
				}
				break;
//			case SEG2:
//				if(timer9_flag == 1){
//					display_don_vi(mode, AUTO_GREEN);
//					Stat_M3_2 = SEG1;
//					setTimer9(25);
//				}
//				break;
//			default:
//				break;
			}

			switch(Stat_M3_3){
				case INIT:
					if(isButtonPressed(BUTTON2) == 1){
						Stat_M3_3 = INCREASE;
						AUTO_GREEN++;
					}
					if(isButtonPressed(BUTTON3) == 1){
						Stat_M3_3 = DECREASE;
						AUTO_GREEN--;
					}
					break;
				case INCREASE:
					if(isButtonPressed(BUTTON2) == 1){
						AUTO_GREEN++;
						if(AUTO_GREEN >= AUTO_RED) AUTO_GREEN = AUTO_RED - 1;
					}

					if(isButtonPressed(BUTTON3) == 1){
						Stat_M3_3 = DECREASE;
						AUTO_GREEN--;
						if(AUTO_GREEN <= MIN_COUNT){
							AUTO_GREEN = MIN_COUNT;
						}
					}
					break;
				case DECREASE:
					if(isButtonPressed(BUTTON2) == 1){
						Stat_M3_3 = INCREASE;
						AUTO_GREEN++;
						if(AUTO_GREEN >= AUTO_RED) AUTO_GREEN = AUTO_RED - 1;
					}

					if(isButtonPressed(BUTTON3) == 1){
						AUTO_GREEN--;
						if(AUTO_GREEN <= MIN_COUNT){
							AUTO_GREEN = MIN_COUNT;
						}
					}
					break;
				default:
					break;
			}

			if(isButtonPressed(BUTTON1) == 1){
				mode = MODE1;
				Setup();
			}
		}
		AUTO_YELLOW = AUTO_RED - AUTO_GREEN;

}


