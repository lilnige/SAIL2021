#pragma config(Motor,  port2,           RightWheel,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           ArmMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           ArmServo,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           LeftWheel,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include <arm.c>
#include <handServo.c>

//Gripper Servo,
task main() {
	while(true) {
		int leftSpeed = 0;
		int rightSpeed = 0;
		int left2Speed = 0;
		int right2Speed = 0;
		//Null Zone Left Stick
		if(vexRT[Ch3] < 20 && vexRT[Ch3] > -20) {
			//If the Left Joystick is in the Middle, set motors to Zero
			rightSpeed = 0;
			leftSpeed = 0;
			} else {
			//Set Motors speed to be Ch3
			rightSpeed = -vexRT[Ch3];
			leftSpeed = -vexRT[Ch3];
		}

		//Null Zone Left Stick
		if(vexRT[Ch4] < 20 && vexRT[Ch4] > -20) {
			//If the Left Joystick is in the Middle, set motors to Zero
			right2Speed = 0;
			left2Speed = 0;
			} else {
			//Set Motors speed to be Ch3
			right2Speed = vexRT[Ch4];
			left2Speed = vexRT[Ch4];
		}
		if(vexRT[Ch2] < 20 && vexRT[Ch2] > -20) {
			startTask(armStart);
		}

		//Set Motors to the values
		motor[RightWheel]= 0 + rightSpeed + right2Speed;
		motor[LeftWheel]= 0 + (-leftSpeed) - (-left2Speed);
	}
}
