/**************************************************************
 * Class:  CSC-615-01 Fall 2022
 * Name: Emanuel Francis
 * Student ID: 917491268
 * Github ID: Emanuelf-sfsu
 * Project:CSC615-StartYourMotors
 *
 * File: motor_contr.h
 *
 * These functions controls how the motor moves.
 *
 **************************************************************/

/*
 * Motors A & B
 *
 */
#define	MA	0
#define MB	5
/*
 * These refer to the screw slots on the motor hat.
 * On the motor hat there are 6 different screw slots
 * the MA1, MA2 are on the left size and the MB1, MB2,
 * is on the other side.
 */
#define MA1	1
#define MA2	2
#define MB1	3
#define MB2	4
/*
 * Select a motor
 */
#define MotorA	0
#define MotorB	1

void motor_init();
void motor_run(int motor,int speed,int dir);
void motor_stop();

