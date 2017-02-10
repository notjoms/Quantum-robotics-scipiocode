double circOfWheelInIn = 3.25*3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854;
task auton(){
	SensorValue[ArmEnc]=SensorValue[Right]=SensorValue[Left]=0;
	motor[L1R1]=motor[FL]=motor[L2R2]=motor[BL]=motor[FR]=motor[L3R3]=motor[BR]=0;
	do{
		motor[FL]=motor[BL]=127;
		motor[FR]=motor[BR]=-127;
	}while(SensorValue[Left]>-(15/(circOfWheelInIn*2)*360)&&SensorValue[Left]<(15/(circOfWheelInIn*2)*360));
	SensorValue[ArmEnc]=SensorValue[Right]=SensorValue[Left]=0;
	motor[L1R1]=motor[FL]=motor[L2R2]=motor[BL]=motor[FR]=motor[L3R3]=motor[BR]=0;
	wait1Msec(300);
	do{
		motor[FL]=motor[BL]=127;
		motor[FR]=motor[BR]=127;
	}while();
	
}