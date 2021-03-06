// This #include statement was automatically added by the Particle IDE.
#include "matrixdisplay.h"
#include "conway.h"

#define MODE_INTRO 1
#define MODE_CLOCK 2
#define MODE_COUNTDOWN 3
#define MODE_TEST_PIXELS 4
#define MODE_BALL 5
#define MODE_DRAW 6
#define MODE_ANALOG_CLOCK 7
#define MODE_CONWAY 8

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_DAY 86400


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
Conway conway = Conway();
int countdownGoal = 0;
int currentDrawFrame = 0;


int8_t ballLocation[2] = {0,0};
int8_t ballVector[2] = {1,-1};

boolean moveTestPixelBall(){
	bool moveY = false;
	if(ballLocation[0]>15){
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
	if(ballLocation[0]>15){
		//hit the right wall
		ballLocation[0] = 14;
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
	md.setPixel(ballLocation[0],ballLocation[1],2);
}

//////////////////////////////////////////
//         Mode Render Functions        //
//////////////////////////////////////////

void renderClock(){
	String s = String(Time.format(Time.now(), "%I%M"));
	if(s.charAt(0) == '0'){
		s = s.substring(1);
	}
	md.centerString(s);
	md.display(true);
	delay(10000);
}

void renderAnalogClock(){
	uint8_t hours = Time.hourFormat12(Time.now());
	uint8_t minutes = Time.minute(Time.now());
	uint8_t hourOffset = (16-hours)/2;
	uint8_t minutesOffset = 3;
	uint8_t minutesYOffset = 2;
	uint8_t i = 0;
	//draw the hours
	for(i=0; i<hours; i++){
		md.setPixel(hourOffset+i, 0, 2);	
	}
	//draw the minutes
	for(i=0; i<=minutes; i++){
		int x = i%10;
		int y = i/10;
		md.setPixel(minutesOffset+x, minutesYOffset+y, 2);	
	}
	
	md.display(true);
	delay(10000);
}

void renderIntro(){
	for(uint8_t x=0; x<16; x++){
		for(uint8_t y=0; y<8; y++){
			md.setPixel(x, y, logo[y][x] ? 2 : 0); 
		}
	}
	md.display(true);
	delay(3000);
}

void renderCountdown(){
	int remainingSeconds = countdownGoal - Time.now();
	if(remainingSeconds < 0){
		remainingSeconds = 0;
	}
	int toPrint = remainingSeconds;
	if( (remainingSeconds / SECONDS_PER_DAY) > 0){
		toPrint = (remainingSeconds / SECONDS_PER_DAY);
	}
	else if( (remainingSeconds / SECONDS_PER_HOUR) > 0){
		toPrint = (remainingSeconds / SECONDS_PER_HOUR);
	}
	else if( (remainingSeconds / SECONDS_PER_MINUTE) > 0){
		toPrint = (remainingSeconds / SECONDS_PER_MINUTE);
	}
	md.centerString(String(toPrint, DEC));
	md.display(false); //dont flutter
	delay(250);
}

void renderTest(){
	moveTestPixelBall();
	drawTheball();
	md.display();
	delay(150);
}

void renderBall(){
	moveBall();
	drawTheball();
	md.display(false); //no flutter
	delay(10);
}

void renderDraw(){
	md.renderFrame(currentDrawFrame);
	currentDrawFrame++;
	if(currentDrawFrame >= NUMBER_OF_IMAGE_FRAMES){
		currentDrawFrame = 0;
	}
	//display and delay are build into the render frame function
}

void renderConway(){
	uint8_t x=0;
   uint8_t y=0;
	conway.processNextCycle();
	for(x=0;x<SCREEN_WIDTH;x++){
		for(y=0;y<SCREEN_HEIGHT;y++){
			md.setPixel(x,y,conway.getValueAtLocation(x,y)?2:0);
		}
	}
	md.display();
	delay(2000);
}

/////////////////////////////////////////
//          CLOUD FUNCTIONS            //
/////////////////////////////////////////

int setDisplayMode_Intro(String param){
	displayMode = MODE_INTRO;
	return 1;
}

int setDisplayMode_Clock(String type){
	if(type.compareTo(String("analog")) == 0){
		displayMode = MODE_ANALOG_CLOCK;
	}
	else{
		displayMode = MODE_CLOCK;
	}
	return 1;
}

int setDisplayMode_Countdown(String timestamp){
	countdownGoal = timestamp.toInt();
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
	displayMode = MODE_DRAW;
	return 1;
}


int setDisplayMode_Conway(String param){
	displayMode = MODE_CONWAY;
	conway.seedTheCanvas();
	return 1;
}

int setDisplayFrame(String param){
	//parse out the details of the frame:
	//for example the following sets frame 2 to be an active frame for 5 seconds
	//255255255255255255255255255255255255255255255255|2|1|5
   if(param.length() < 53){ //needs to be at least 53 characters in length
   	return 0;
   }
   
   String imageString = param.substring(0,48);
   String otherParams = param.substring(49);
   
   int endFrame = otherParams.indexOf('|');
   int endActive = otherParams.indexOf('|', endFrame+1);
   int frameNumber = otherParams.substring(0,endFrame).toInt();
   int isActive = otherParams.substring(endFrame+1,endActive).toInt();
   int numSeconds = otherParams.substring(endActive+1).toInt();
   
   md.imageFrames[frameNumber].isActive = (isActive > 0) ? true : false;
   md.imageFrames[frameNumber].seconds = numSeconds;
   md.imageFrames[frameNumber].setImageFromString(imageString);
   
	return 1;
}


void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	//register the functions
	Particle.function("intromode", setDisplayMode_Intro);
	Particle.function("clockmode", setDisplayMode_Clock);
	Particle.function("countmode", setDisplayMode_Countdown);
	Particle.function("testmode", setDisplayMode_TestPixels);
	Particle.function("ballmode", setDisplayMode_Ball);
	Particle.function("drawmode", setDisplayMode_Draw);
	Particle.function("conwaymode", setDisplayMode_Conway);
	Particle.function("setframe", setDisplayFrame);
	Particle.variable("displaymode", displayMode);
	md.matrixDisplaySetup();
	md.clearScreen(true);
	Time.zone(-4.00);
}

void loop() {
	md.clearScreen(false);
	switch(displayMode){
		case MODE_INTRO:
			renderIntro();
			break;
		case MODE_ANALOG_CLOCK:
			renderAnalogClock();
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
		case MODE_CONWAY:
			renderConway();
			break;
	}
	delay(10);
}
