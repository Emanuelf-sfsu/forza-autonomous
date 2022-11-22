/*
 *Class:CSC-615-01 Fall 2022
 *Name: Emanuel Francis
 *Student ID: 917491268
 *Github: Emanuelf-sfsu
 *Project: Assignment 3 - Start your motor
 *
 *File: motor_contr.c
 *
 *Description:This file contains all of the methods needed 
 *to control the motor on the motor hat.
 *
 *
 */

#include "../PCA9685/PCA9685.h"
#include  "motor_contr.h"


/*
 *The Raspberry pi need to know the address of the Motor hat 
 *in order to communicate with it.
 */
void motor_init(){
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

void motor_run(int motor,int speed,int dir){

	/*
	 * g = Ground
	 * p = Positive
	 */

	int g = 0;
	int p = 1;
	
	// Check the direction 
	if(dir == 1){
		g +=1;
		p -=1;
	}
	
	switch(motor)
	{
		// Motor A
		case 0 :

			PCA9685_SetPwmDutyCycle(MA, speed);
		        PCA9685_SetLevel(MA1, g);
			PCA9685_SetLevel(MA2, p);
			break;
		// Motor B
		case 1:
			PCA9685_SetPwmDutyCycle(MB, speed);
		        PCA9685_SetLevel(MB1, g);
			PCA9685_SetLevel(MB2, p);
			break;
	}
}



void motor_stop(){
	PCA9685_SetPwmDutyCycle(MB, 0);

	printf("Stop\n");
}

