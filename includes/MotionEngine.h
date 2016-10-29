#ifndef __SPIDERBOT_H__
#define __SPIDERBOT_H__

//Joint1 defines
#define LEG1MOTOR1_FWD 10
#define LEG1MOTOR1_REV 11
#define LEG1MOTOR1_POS A0

//Joint2 defines
#define LEG1MOTOR2_FWD 3
#define LEG1MOTOR2_REV 5
#define LEG1MOTOR2_POS A1

//Joint3 defines
#define LEG1MOTOR3_FWD 9
#define LEG1MOTOR3_REV 6
#define LEG1MOTOR3_POS A2

//Defined Values
#define POSITION_DEADZONE	0.5
#define DT 		0.005 	// PID update time in seconds
#define DT_INV	200		// PID update in Hz

// Spider Joint Type Definitions
typedef struct jointData_t jointData_t;
struct jointData_t{
	// Pos Variables
	float target_pos;		// Position to go to in deg.
	float current_pos;		// Joint's current pos in deg.
	// Rate variables
	float target_vel;		// Rotation rate to acheive in deg/s.
	float current_vel;		// Current rotation rate in deg/s.
	// Acceleration Variables
	float acceleration;		// Acceleration to use in rate targeting in deg/s^2.
	// Control system variables
	float integral_pos;
	float integral_vel;
	uint8_t p_pos;			// Proportional term for position control system.
	uint8_t i_pos;			// Integral term for position control system.
	uint8_t d_pos;			// Derivative term for position control system.
	uint8_t p_vel			// Proportional term for velocity control system.
	uint8_t i_vel;			// Integral term for velocity control system.
	uint8_t d_vel;			// Derivative term for velocity control system.
	int16_t pwm;			// Output PWM value in cnts representing duty cycle and
							// sign represents motor direction.
};


// Prototype function declarations
int16_t moveToPos(jointData_t* joint);
int16_t moveToPosWithAccl(jointData_t* joint);
int16_t moveAtRate(jointData_t* joint);

#endif