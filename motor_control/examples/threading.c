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
static void *sensor_routine(void *arg)
{
	struct thread_info *sensor = arg;
	int pin = sensor->gpio_pin;
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
			printf("%s: %d\n", sensor->sensor, gpioRead(pin));
			sleep(1);
		}
	}

	return sensor->sensor;
}

int main()
{
	if (gpioInitialise() < 0)
	{
		fprintf(stderr, "pigpio initalization failed\n");
		return 1;
	}

	int num_thread, s;
	struct thread_info *tinfo;
	void *res;
	pthread_t *thread;
	pthread_attr_t attr;
	num_thread = 2;

	tinfo = calloc(num_thread, sizeof(*tinfo));

	/*
	 * Important Information regarding the sensors & pins
	 */
	tinfo[0].thread_num = 0;
	tinfo[0].sensor = "IR Sensor";
	tinfo[0].gpio_pin = IR_SENSOR;

	tinfo[1].thread_num = 1;
	tinfo[1].sensor = "Line Sensor";
	tinfo[1].gpio_pin = LINE_SENSOR;

	s = pthread_attr_init(&attr);
	if (s != 0)
	{
		printf("ERROR!! pthread_attr_init");
		return -1;
	}
	/*
	 * Create the threads
	 */

	printf("Sensors On: \n");
	for (int i = 0; i < num_thread; i++)
	{
		s = pthread_create(&tinfo[i].thread_id, &attr, &sensor_routine, &tinfo[i]);
		if (s != 0)
		{
			printf("ERROR!! pthread_create");
			return -1;
		}
	}

	/*
	 * Rejoin
	 */

	for (int i = 0; i < num_thread; i++)
	{
		s = pthread_join(tinfo[i].thread_id, &res);
		if (s != 0)
		{
			printf("Error in Rejoining\n");
			return -1;
		}
		printf("%d has rejoined\n", i);
	}

	/*
	 * Clean up
	 */

	free(tinfo);
	s = pthread_attr_destroy(&attr);
	gpioTerminate();

	return 0;
}
