/**************************************************************
 * Class:  CSC-615-01 Fall 2022
 * Name: Emanuel Francis
 * Student ID: 917491268
 * Github ID: Emanuelf-sfsu
 * Project: Assignment 2 - Tapeless Ruler
 *
 * File: Francis_Emanuel_tapeless_ruler.c
 *
 * Description:This program is going to measure distance using 
 * the Echo Sensor (HC-SR04) and display distance
 * in centimeters in your terminal.
 * 
 * To run program use `make` to compile the program
 * Use `sudo ./assignment2` to start the program
 * The program will scan 5 times
 * 
 *
 **************************************************************/

#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>
#include <time.h>

#define TRIG_PIN 4
#define ECHO_PIN 27 
#define REPEAT 10

int main(int argc, char *argv[])
{
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initalization failed\n");
        return 1;
    }
    printf("Distance Measurement in Progress....\n");
    /*Setting up GPIO modes*/
    gpioSetMode(TRIG_PIN,1);
    gpioSetMode(ECHO_PIN,0);
    int counter = 1 ;
while(counter <= REPEAT){
    // Make sure that the Trigger is set to low
    gpioWrite(TRIG_PIN, 1);
    usleep(10);
    gpioWrite(TRIG_PIN,0);

    // WAIT FOR ECHO
    double duration,distance,start,end;
     
    while (gpioRead(ECHO_PIN) == 0)
    {
        start = time_time();
     //   printf("Start time %f\n");
    }
//printf("Start %f",start);

    while(gpioRead(ECHO_PIN) == 1){
        end = time_time();
  //      printf("End time %f\n");
    }

    duration = end - start;
//    printf("Duration %f\n",duration);
    distance = (duration * 34300)/2;
    printf("Distance %f cm\n", distance);
    time_sleep(2);
    counter++;
}
    
    gpioTerminate();
    
    return 0;
}
