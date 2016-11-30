#pragma config(Sensor, in1,    pot1,           sensorPotentiometer)
#pragma config(Sensor, in2,    pot2,           sensorPotentiometer)
#pragma config(Sensor, in8,    expVoltage,     sensorAnalog)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           arm1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           arm3,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
#include "AutonomousPrograms.c";
#include "LCDprogram.c";
#include "driverControl.c";


void pre_auton()
{
	startTask(runAutonLCD);
}
task autonomous()
{
	callAutonomous(count);
}
task usercontrol()
{
  startTask(drivingControl);
}
