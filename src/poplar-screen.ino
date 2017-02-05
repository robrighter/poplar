// This #include statement was automatically added by the Particle IDE.
#include "matrixdisplay.h"

int8_t ballLocation[2] = {0,0};
int8_t ballVector[2] = {1,-1};

boolean moveBall2(){
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
    false;
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
        setPixel(ballLocation[0]+i,ballLocation[1]+t,2);
    }
  }
}

void countDown(int top, int secondsdelay){
    if(secondsdelay<1){
        secondsdelay = 1;
    }
    char todisplay[10];

    while(top>=0){
        clearScreen(false);
        displayString(1, 1, String(top--, DEC));
        display();
        delay(secondsdelay*1000);
    }
}

void displayClock(){
    displayString(1,1,Time.format(Time.now(), "%I%M"));//"%I:%M%p"
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrixDisplaySetup();
  clearScreen(true);
  Time.zone(-5.00);

}

void loop() {


  clearScreen(false);

  //countDown(700, 1);
  moveBall2();
  drawTheball();
  //displayClock();
  display();
  delay(100);
  //scrollText("HI");
  //delay(3000);
}
