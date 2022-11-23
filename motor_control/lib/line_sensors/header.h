/**************************************************************
 * Class:  CSC-615-01 Fall 2022
 * Name: Emanuel Francisz
 * Student ID: 917491268
 * Github ID: Emanuelf-sfsu
 * Project:CSC615-StartYourMotors
 *
 * File: header.h
 *
 *
 **************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <pigpio.h>

#define IR_SENSOR 4
#define LINE_SENSOR 26

/*
 *   Contains data required for sensor to work
 */
struct thread_info
{
    pthread_t thread_id;
    int thread_num;
    char *sensor;
    int gpio_pin;
    char *message;
};

/*
 * The line sensor and IR sensors have almost identical
 * routines ,so they will share 1 singular function but the
 * infomation will be dependent apon the structure.
 */
static void *sensor_routine(void *arg);
