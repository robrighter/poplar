// This #include statement was automatically added by the Particle IDE.
#include "matrixdisplay.h"

#define MODE_INTRO 1
#define MODE_CLOCK 2
#define MODE_COUNTDOWN 3
#define MODE_TEST_PIXELS 4
#define MODE_BALL 5
#define MODE_DRAW 6

const boolean logo[8][16] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1},
	{1,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0},
	{1,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int displayMode = MODE_INTRO;
MatrixDisplay md = MatrixDisplay();


int8_t ballLocation[2] = {0,0};
int8_t ballVector[2] = {1,-1};

boolean moveTestPixelBall(){
	bool moveY = false;
	if(ballLocation[0]>11){
		ballVector[0] = -1;
		moveY=true;
	}
	else if(ballLocation[0]<0){
		ballVector[0] = 1;
		moveY=true;
	}
	ballLocation[0]+=ballVector[0];

	if(ballLocation[1]>6){
		ballVector[1] = -1;
	}
	if(ballLocation[1]<1){
		ballVector[1] = 1;
	}
	if(moveY){
		ballLocation[1]+=ballVector[1];
	}
	return false;
}

boolean moveBall(){
	ballLocation[0] = ballLocation[0] + ballVector[0];
	ballLocation[1] = ballLocation[1] + ballVector[1];
	if(ballLocation[0]>11){
		//hit the right wall
		ballLocation[0] = 11;
		ballVector[0] = -1;
	}
	if(ballLocation[0]<0){
		//hit the left wall
		ballLocation[0] = 1;
		ballVector[0] = 1;
	}
	if(ballLocation[1]>7){
		//hit the bottom wall
		ballLocation[1] = 6;
		ballVector[1] = -1;
	}
	if(ballLocation[1]<0){
		//hit the top wall
		ballLocation[1] = 1;
		ballVector[1] = 1;
	}
	return false;
}

void drawTheball(){
	for(byte i=0;i<1;i++){
		for(byte t=0;t<1;t++){
			md.setPixel(ballLocation[0]+i,ballLocation[1]+t,2);
		}
	}
}

void countDown(int top, int secondsdelay){
	if(secondsdelay<1){
		secondsdelay = 1;
	}
	
	while(top>=0){
		md.clearScreen(false);
		md.displayString(1, 1, String(top--, DEC));
		md.display();
		delay(secondsdelay*1000);
	}
}

//////////////////////////////////////////
//         Mode Render Functions        //
//////////////////////////////////////////

void renderClock(){
	md.displayString(1,1,Time.format(Time.now(), "%M"));//"%I:%M%p"
	md.display();
	delay(2000);
}

void renderIntro(){
	for(uint8_t x=0; x<16; x++){
		for(uint8_t y=0; y<8; y++){
			md.setPixel(x, y, logo[y][x] ? 2 : 0); 
		}
	}
	md.display();
	delay(3000);
}

void renderCountdown(){
	//TODO: reimplement this in a way that counts down to the timestamp
	countDown(20,1);
}

void renderTest(){
	moveTestPixelBall();
	drawTheball();
	md.display();
	delay(1500);
}

void renderBall(){
	moveBall();
	drawTheball();
	md.display();
	delay(300);
}

void renderDraw(){
	//TODO parse out the hex number and convert it into set pixel calls
	md.display();
	delay(1000);
}

/////////////////////////////////////////
//          CLOUD FUNCTIONS            //
/////////////////////////////////////////

int setDisplayMode_Intro(String param){
	displayMode = MODE_INTRO;
	return 1;
}

int setDisplayMode_Clock(String timezone){
	displayMode = MODE_CLOCK;
	return 1;
}

int setDisplayMode_Countdown(String timestamp){
	displayMode = MODE_COUNTDOWN;
	return 1;
}

int setDisplayMode_TestPixels(String param){
	displayMode = MODE_TEST_PIXELS;
	return 1;
}

int setDisplayMode_Ball(String param){
	displayMode = MODE_BALL;
	return 1;
}

int setDisplayMode_Draw(String param){
	//todo parse out the hex and store it
	displayMode = MODE_DRAW;
	return 1;
}


void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	md.matrixDisplaySetup();
	md.clearScreen(true);
	Time.zone(-5.00);
	//register the functions
	Particle.variable("displaymode", displayMode);
	Particle.function("intromode", setDisplayMode_Intro);
	Particle.function("clockmode", setDisplayMode_Clock);
	Particle.function("countmode", setDisplayMode_Countdown);
	Particle.function("testmode", setDisplayMode_TestPixels);
	Particle.function("ballmode", setDisplayMode_Ball);
	Particle.function("drawmode", setDisplayMode_Draw);
}

void loop() {
	md.clearScreen(false);
	switch(displayMode){
		case MODE_INTRO:
			renderIntro();
			break;
		case MODE_CLOCK:
			renderClock();
			break;
		case MODE_COUNTDOWN:
			renderCountdown();
			break;
		case MODE_TEST_PIXELS:
			renderTest();
			break;
		case MODE_BALL:
			renderBall();
			break;
		case MODE_DRAW:
			renderDraw();
			break;
	}
	delay(10);
}
