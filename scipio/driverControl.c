#include "TheUltimateFile.c";
/*
    This file is part of the Quantum Robotics robot code.

    The Quantum Robotics robot code is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Quantum Robotics robot code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the Quantum Robotics robot code.  If not, see <http://www.gnu.org/licenses/>.
*/
//Please give credit if you are using this
task drivingControl(){
	bLCDBacklight = true;
	string mainBattery, backupBattery;
	int X1=0,X2=0,Y1=0,threshold=10,hookRotation = 0;
	int p1, p2, tick, count2=0;
	string exVol;
	bool td = true;
	nMotorEncoder[hook]=0;
	while (true)
	{
		//p1=SensorValue[pot1]/15.45283018867925;
		//p2=SensorValue[pot2]/15.45283018867925;
		hookRotation = nMotorEncoder[hook]/672.2;
		//Driving code
		if(vexRT[Btn7U]==1){//changing between tank and standard
			wait1Msec(300);
			if(vexRT[Btn7U]==1)
				td=!td;
		}
		if(td==true){//tank drive is true
			motor[port2] = (vexRT(Ch3)>threshold||vexRT(Ch3)<-threshold)?vexRT(Ch3):0;
			motor[port3] = (vexRT(Ch3)>threshold||vexRT(Ch3)<-threshold)?vexRT(Ch3):0;
			motor[port4] = (vexRT(Ch2)>threshold||vexRT(Ch2)<-threshold)?vexRT(Ch2):0;
			motor[port5] = (vexRT(Ch2)>threshold||vexRT(Ch2)<-threshold)?vexRT(Ch2):0;
			if(vexRT[Btn5D]==1)//move left
			{
				motor[port2] = 127;
				motor[port3] = -127;
				motor[port4] = -127;
				motor[port5] = 127;
			}

			if(vexRT[Btn6D]==1){//move right
				motor[port2] = -127;
				motor[port3] = 127;
				motor[port4] = 127;
				motor[port5] = -127;
			}
		}
		if(td==false){//standard drive
			if(abs(vexRT[Ch3]) > threshold) Y1 = vexRT[Ch3];
			else Y1 = 0;
			if(abs(vexRT[Ch4]) > threshold)	X1 = vexRT[Ch4];
			else X1 = 0;
			if(abs(vexRT[Ch1]) > threshold)	X2 = vexRT[Ch1];
			else X2 = 0;
			motor[frontRight] = Y1 + X2 - X1;
			motor[backRight] =  Y1 + X2 + X1;
			motor[frontLeft] = Y1 - X2 + X1;
			motor[backLeft] =  Y1 - X2 - X1;
		}//end driving code
		//begin LCD code
		if(count2==0){//display battery level
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0, 0, "Primary: ");
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
			displayNextLCDString(mainBattery);
			displayLCDString(1, 0, "Backup: ");
			sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
			displayNextLCDString(backupBattery);
		}else if(count2==1){//disp ports 2 and 3
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port2:");
			displayLCDNumber(0,7,motor[port2]);
			displayLCDString(1,0,"Port3:");
			displayLCDNumber(1,7,motor[port2]);
		}else if(count2==2){//disp ports 4 and 5
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port4:");
			displayLCDNumber(0,7,motor[port4]);
			displayLCDString(1,0,"Port5:");
			displayLCDNumber(1,7,motor[port5]);
		}else if(count2==3){//disp ports 6 and 7
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port6:");
			displayLCDNumber(0,7,motor[port6]);
			displayLCDString(1,0,"Port7:");
			displayLCDNumber(1,7,motor[port7]);
		}else if(count2==4){//disp ports 8 and 9
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port8:");
			displayLCDNumber(0,7,motor[port8]);
			displayLCDString(1,0,"Port9:");
			displayLCDNumber(0,7,motor[hook]);
		}else if(count2==5){//disp exp batt
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Expander batt:");
			int numVolt = expVoltage/70;
			displayLCDNumber(1,0,numVolt);
		}
		tick++;//cycling LCD Info
		if(tick>=10000){
			tick=0;
			count2++;
		}
		if(count2==6) count2=0;
		//end LCD code
		//begin arm code
		if(vexRT[Btn5U]==1){//arm full speed
			motor[arm1]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
		}if(vexRT[Btn6U]==1){//arm backwards
			motor[arm1]=127;
			motor[arm2]=127;
			motor[arm3]=127;
		}else if((vexRT[Btn5U]==0&&vexRT[Btn6U]==0)){//arm no speed
			motor[arm1]=0;
			motor[arm2]=0;
			motor[arm3]=0;
		}
		//end arm code
		//begin LED code
		if(SensorValue[limit1]==1)SensorValue[yellowLED1]=true;
		else SensorValue[yellowLED1]=false;
		if(SensorValue[limit2]==1)SensorValue[yellowLED2]=true;
		else SensorValue[yellowLED2]=false;
		//end LED code
		if(vexRT[Btn8R]==1) motor[hook]=127;
		else motor[hook]=0;//hook code
	}
}
