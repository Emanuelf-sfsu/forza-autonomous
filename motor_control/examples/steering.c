/**************************************************************
 * Class:  CSC-615-01 Fall 2022
 * Name: Emanuel Francis
 * Student ID: 917491268
 * Github ID: Emanuelf-sfsu
 * Project:CSC615-StartYourMotors
 *
 * File: steering.c
 *
 * Press the button to start your program.
 * The program will wait until the button is pressed. 
 * Once it is pressed, then it will show the motor running forward for at least 
 * 2 seconds, then slow down to 15% gradually, then stop for at least 
 * one second, then start slowly and gradually increase speed to max 
 * but in reverse (backwards).
 *
 **************************************************************/

#include "main.h"

void Handler(int signo){
	printf("End\n");
	motor_stop();
	exit(0);
}

int push_start(){
	int PIN = 4;	
	/*
	 * Wait for the button pressed.
	 * Begin by setting up the gpio pins to read
	 * the button input. Once the button is pressed then 
	 * it will exit the waiting status.
	 */
	SYSFS_GPIO_Export(PIN);
	
	SYSFS_GPIO_Write(PIN,SYSFS_GPIO_HIGH);
	
	printf("Push to start:\n");
	int on = 1;
	while(on==1)
	{
		if(SYSFS_GPIO_Read(PIN)==SYSFS_GPIO_LOW)
		{
			printf("PRESSED \n");
			on = 0;

			SYSFS_GPIO_Unexport(PIN);
		}
	}	
	return 0;
}

/*
 * Connect the motorhat to the raspberry pi so that it can
 * communicate with the motors
 */	
int main(){
	motor_init();
	
	printf("Turn Left");
	motor_run(0,100,0);
	sleep(3);

	printf("Turn Right");
	motor_run(0,100,1);
	sleep(3);

	// /*
	//  * Run for 2 Seconds
	//  */
	// printf("Start\n");
	// motor_run(1,100,0);
	// sleep(2);
	
	// /*
	//  * Slow down to 15%
	//  */
		
	// printf("Slow down\n");
	// for(int i = 100; i >= 15; i =i-15){ 
	// 	motor_run(1,i,0);
	// 	sleep(1);
	// }

	
	// /* 
	//  * Stop Motor for 2 secs >=
	//  */

	// printf("Stop\n");
	// sleep(2);


	// // Gradually increase to full speed backward
	
	// printf("Reverse\n");
	// for(int i = 0; i < 100; i =i+15){ 
	// 	motor_run(1,i,1);
	// 	sleep(1);
	// }
	
	// printf("Finish\n");
	motor_stop();
	
	signal(SIGINT, Handler);

}
	

