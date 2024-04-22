#include "backGround.h"
#include "math.h"


void BackGround::Init () {

	handle[0] = LoadGraph("Data/Image/Play/sun.png");
	handle[1] = LoadGraph("Data/Image/Play/moon.png");
	sun_pos_x=0;
	sun_pos_y=0;
	moon_pos_x=0;
	moon_pos_y=0;
	radian=180*3.1415/180;
	radius = 640;
	timeFlag=1;
	red= 190;
	green= 245;
	blue= 255;

}

void BackGround::Step() {
	
	sun_pos_x =585+radius * cos(radian);
	sun_pos_y = 720 + radius * sin(radian);
	moon_pos_x = 585+ radius * cos(radian +181*3.1415/180);
	moon_pos_y = 720 + radius * sin(radian + 180 * 3.1415 / 180);
	radian += 0.002;
	if (radian * 180 / 3.1415 >= 360) {
		radian = 0;
	}


	//’©
	if (radian >= 180 * 3.1415/180) {
		timeFlag = 0;
	}
	//—[•û
	if (radian >= 320 * 3.1415 / 180 && radian > 0) {
		timeFlag = 1;
	}//–é
	if (radian >= 0&& radian <= 120*3.1415/180) {
		timeFlag = 2;
	}
	//[–é
	if (radian >= 120 * 3.1415 / 180 && radian <= 180 * 3.1415 / 180) {
		timeFlag = 3;
	}


	if (timeFlag == 0) {//’©
		red++;
		green++;
		blue++;
		if (red >= 190) {
			red = 190;
		}
		if (green >= 245) {
			green = 245;
		}
		if (blue >= 255) {
			blue = 255;
		}
	}
	if (timeFlag == 1) {//—[•û
		red++;
		green--;
		blue--;
		if (red >= 255) {
			red = 255;
		}
		if (green <= 127) {
			green = 127;
		}
		if (blue <= 55) {
			blue = 55;
		}
	}
	if (timeFlag == 2) {//–é
		red--;
		green--;
		blue++;
		if (red <= 51) {
			red = 51;
		}
		if (green <= 108) {
			green = 108;
		}
		if (blue >= 181) {
			blue = 181;
		}
	}

	if (timeFlag == 3) {//[–é
		red--;
		green--;
		blue++;
		if (red <= 28) {
			red = 28;
		}
		if (green <= 69) {
			green = 69;
		}
		if (blue >= 123) {
			blue = 123;
		}
	}
	

}

void BackGround::Draw() {

	DrawBox(0, 720, 1280, 0, GetColor(red, green, blue), true);//’©
	
	
	//DrawBox(0, 720, 1280, 0, GetColor(28, 69, 123), true);//–é
	DrawGraph(sun_pos_x, sun_pos_y, handle[0], true);
	DrawGraph(moon_pos_x, moon_pos_y, handle[1], true);
	DrawFormatString(30, 50, GetColor(255, 0, 0), "%f", radian*180/3.1415);
	DrawFormatString(30, 70, GetColor(255, 0, 0), "%d", timeFlag);
}