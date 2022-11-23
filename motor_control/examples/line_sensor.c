/**************************************************************
 * Class:  CSC-615-01 Fall 2022
 * Name: Emanuel Francis
 * Student ID: 917491268
 * Github ID: Emanuelf-sfsu
 * Project:CSC615-StartYourMotors
 *
 * File: assignment4.c
 *
 * Description:
 * Read (i.e. input) from the two sensors, one should be able
 * to tell you if you are over Black or over White (i.e. on the line 
 * or off the line) and the other sensor will state if there is an
 * obstruction in front of the sensor. This will be done with threads, 
 * one for each sensor and a main loop that checks the values.
 *
 *
 **************************************************************/
#include "../lib/line_sensors/header.h"
#include <signal.h>
#include <time.h>

/*
 * The line sensor and IR sensors have almost identical
 * routines ,so they will share 1 singular function but the
 * infomation will be dependent apon the structure.
 */
 void sensor_routines()
{
	int pin = LINE_SENSOR;
	int status = 0;
	//	printf("Thread %d Started\n",sensor->thread_id);

	gpioSetMode(pin, 0);
	int run_time = 1000 * 9000;
	clock_t start_time = clock();

	// Loop for a certain amount of time then return to main
	while (clock() < start_time + run_time * 2)
	{
		if (gpioRead(pin) == 0)
		{
			printf("lINE: %d\n", gpioRead(pin));
			sleep(1);
		}
	}

	return;
}

int main()
{
	if (gpioInitialise() < 0)
	{
		fprintf(stderr, "pigpio initalization failed\n");
		return 1;
	}

	sensor_routines();



	gpioTerminate();

	return 0;
}
