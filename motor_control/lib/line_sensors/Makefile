# /**************************************************************
#  * Class:  CSC-615-01 Fall 2022
#  * Name: Emanuel Francis
#  * Student ID: 917491268
#  * Github ID: Emanuelf-sfsu
#  * Project: Assignment 2 - Tapeless Ruler
#  *
#  * File: Francis_Emanuel_tapeless_ruler.c
#  *
#  * Description:This program is going to measure distance using 
#  * the Echo Sensor (HC-SR04) and display distance
#  * in centimeters in your terminal.
#  *
#  **************************************************************/
all: assignment4

assignment4: assignment4.c	
	gcc -o assignment4  assignment4.c -lpigpio -lrt -pthread
clean:
	rm ./assignment4

run:
	sudo ./assignment4 -pthread
