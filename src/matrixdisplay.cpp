#include "matrixdisplay.h"

MatrixDisplay::MatrixDisplay(){}

const boolean MatrixDisplay::bitchar0[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,1,1}};

const boolean MatrixDisplay::bitchar1[5][3] = {{0,1,0},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0}};

const boolean MatrixDisplay::bitchar2[5][3] = {{1,1,1},
                          {0,0,1},
                          {1,1,1},
                          {1,0,0},
                          {1,1,1}};

const boolean MatrixDisplay::bitchar3[5][3] = {{1,1,1},
                          {0,0,1},
                          {1,1,1},
                          {0,0,1},
                          {1,1,1}};


const boolean MatrixDisplay::bitchar4[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,1,1},
                          {0,0,1},
                          {0,0,1}};

const boolean MatrixDisplay::bitchar5[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,1},
                          {0,0,1},
                          {1,1,1}};

const boolean MatrixDisplay::bitchar6[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,1},
                          {1,0,1},
                          {1,1,1}};

const boolean MatrixDisplay::bitchar7[5][3] = {{1,1,1},
                          {0,0,1},
                          {0,0,1},
                          {0,0,1},
                          {0,0,1}};

const boolean MatrixDisplay::bitchar8[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,1,1},
                          {1,0,1},
                          {1,1,1}};

const boolean MatrixDisplay::bitchar9[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,1,1},
                          {0,0,1},
                          {0,0,1}};

const boolean MatrixDisplay::bitcharA[5][3] = {{0,1,0},
                          {1,0,1},
                          {1,1,1},
                          {1,0,1},
                          {1,0,1}};



const boolean MatrixDisplay::bitcharB[5][3] = {{1,1,0},
                          {1,0,1},
                          {1,1,1},
                          {1,0,1},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharC[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,0,0},
                          {1,0,0},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharD[5][3] = {{1,1,0},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,1,0}};



const boolean MatrixDisplay::bitcharE[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,0},
                          {1,0,0},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharF[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,1},
                          {1,0,0},
                          {1,0,0}};


const boolean MatrixDisplay::bitcharG[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,1},
                          {1,0,1},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharH[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,1,1},
                          {1,0,1},
                          {1,0,1}};



const boolean MatrixDisplay::bitcharI[5][3] = {{1,1,1},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharJ[5][3] = {{0,0,1},
                          {0,0,1},
                          {0,0,1},
                          {1,0,1},
                          {1,1,1}};



const boolean MatrixDisplay::bitcharK[5][3] = {{1,0,1},
                          {1,1,0},
                          {1,1,0},
                          {1,0,1},
                          {1,0,1}};


const boolean MatrixDisplay::bitcharL[5][3] = {{1,0,0},
                          {1,0,0},
                          {1,0,0},
                          {1,0,0},
                          {1,1,1}};



const boolean MatrixDisplay::bitcharM[5][3] = {{1,0,1},
                          {1,1,1},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1}};



const boolean MatrixDisplay::bitcharN[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,1,1},
                          {1,1,1},
                          {1,0,1}};

const boolean MatrixDisplay::bitcharO[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,1,1}};

const boolean MatrixDisplay::bitcharP[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,1,1},
                          {1,0,0},
                          {1,0,0}};

const boolean MatrixDisplay::bitcharQ[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,1,1},
                          {0,0,1},
                          {0,0,1}};


const boolean MatrixDisplay::bitcharR[5][3] = {{1,1,1},
                          {1,0,1},
                          {1,1,0},
                          {1,0,1},
                          {1,0,1}};


const boolean MatrixDisplay::bitcharS[5][3] = {{1,1,1},
                          {1,0,0},
                          {1,1,1},
                          {0,0,1},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharT[5][3] = {{1,1,1},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0}};

const boolean MatrixDisplay::bitcharU[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,1,1}};


const boolean MatrixDisplay::bitcharV[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {0,1,0}};


const boolean MatrixDisplay::bitcharW[5][3] = {{1,0,1},
                          {1,0,1},
                          {1,0,1},
                          {1,1,1},
                          {1,0,1}};

const boolean MatrixDisplay::bitcharX[5][3] = {{1,0,1},
                          {1,0,1},
                          {0,1,0},
                          {1,0,1},
                          {1,0,1}};


const boolean MatrixDisplay::bitcharY[5][3] = {{1,0,1},
                          {1,0,1},
                          {0,1,0},
                          {0,1,0},
                          {0,1,0}};


const boolean MatrixDisplay::bitcharZ[5][3] = {{1,1,1},
                          {0,0,1},
                          {0,1,0},
                          {1,0,0},
                          {1,1,1}};

const boolean MatrixDisplay::bitcharSPACE[5][3] = {{0,0,0},
                          {0,0,0},
                          {0,0,0},
                          {0,0,0},
                          {0,0,0}};




void MatrixDisplay::matrixDisplaySetup(){

  pinMode(OE_PIN, OUTPUT);
  digitalWrite(OE_PIN, HIGH);

  for(int i=0;i<NUMBER_OF_DRIVERS; i++){
    driver[i].begin();
    driver[i].setPWMFreq(60); // Analog servos run at ~60 Hz updates
    Serial.println("setting up driver index: ");
    Serial.println(i);
  }
  //yield();

}


void MatrixDisplay::getPDMLocationForCoords(uint8_t x, uint8_t y, struct PDMLocation *outvar){
  uint8_t localx = 0;
  uint8_t localy = 0;
  if(x<4){
    outvar->driverIndex = (y<4)?0:1;
    localx = x;
  }
  else if(x<8){
    outvar->driverIndex = (y<4)?3:2;
    localx = x-4;
  }
  else if(x<12){
    outvar->driverIndex = (y<4)?4:5;;//(y<4)?5:4;//not going to have the 5 hooked up for now
    localx = x-8;
  }
  else{//x<16
    outvar->driverIndex = IGNORE_DRIVER; //not going to have 5 hooked up for now
    localx = x-12;
  }
  localy = (y<4)?y:y-4;
  //translate localx and localy to a servo number 0-15
  outvar->servoIndex = ((4*(localy+1)) - (4-(localx+1)))  -1;
}

boolean MatrixDisplay::transposePixel(uint8_t x,uint8_t y){
  if( (x>=SCREEN_WIDTH) || (y>=SCREEN_HEIGHT) ){
    //pixel is off the screen so just return false
    return false;
  }
  if(futureScreenMatrix[y][x] == existingScreenMatrix[y][x]){
    return false;
  }
  else{
    existingScreenMatrix[y][x] = futureScreenMatrix[y][x];
    return true;
  }
}

void MatrixDisplay::test(){
  Serial.println("Starting Test ");
  digitalWrite(OE_PIN, LOW);
  for(int i=0; i<16; i++){
    driver[0].setPWM(i, 0, SERVOMAX);
    delay(150);
  }
  delay(2000);

  for(int i=0; i<16; i++){
    driver[0].setPWM(i, 0, SERVOMIN);
    delay(150);
  }
  delay(2000);
  digitalWrite(OE_PIN, HIGH);

}

void MatrixDisplay::updateDisplay(bool force){
  //loop through the controllers and have each one update their quadrant

  uint8_t numChanged = 0;
  for(uint8_t x=0; x<16; x++){
    for(uint8_t y=0; y<8; y++){
      bool didChange = transposePixel(x,y);
      if(didChange || force){
        struct PDMLocation outvar;
        getPDMLocationForCoords(x, y, &outvar);
        int displayValue = SERVOMIN;
        if(futureScreenMatrix[y][x] == 0){
          displayValue =  SERVOMIN;
        }
        else if(futureScreenMatrix[y][x] == 1){
          displayValue =  SERVOMID;
        }
        else if(futureScreenMatrix[y][x] > 1){
          displayValue =  SERVOMAX;
        }
        numChanged++;
        if(!force && numChanged > 15){
          //Slow things down so we dont burn out the controller (leaned this the hard way)
          delay(5);
        }
        //if( (numChanged>0) && ((numChanged % 10)== 0) ){
        //    delay(500);
        //}
        if(outvar.driverIndex != IGNORE_DRIVER){
          digitalWrite(OE_PIN, LOW);
          driver[outvar.driverIndex].setPWM(outvar.servoIndex, 0, displayValue);
        }

      }
    }
  }
  delay(70*((numChanged/5)+2));
  digitalWrite(OE_PIN, HIGH);
}

void MatrixDisplay::display(){
  updateDisplay(false);
}



void MatrixDisplay::displayChar(uint8_t x, uint8_t y, char thechar){
  const boolean (*charmap)[3];

  if( thechar == 48 ){ //0
    charmap = bitchar0;
  }
  if( thechar == 49 ){ //1
    charmap = bitchar1;
  }

  if( thechar == 50 ){ //2
    charmap = bitchar2;
  }
  if( thechar == 51 ){ //3
    charmap = bitchar3;
  }
  if( thechar == 52 ){ //4
    charmap = bitchar4;
  }
  if( thechar == 53 ){ //5
    charmap = bitchar5;
  }
  if( thechar == 54 ){ //6
    charmap = bitchar6;
  }
  if( thechar == 55 ){ //7
    charmap = bitchar7;
  }
  if( thechar == 56 ){ //8
    charmap = bitchar8;
  }
  if( thechar == 57 ){ //9
    charmap = bitchar9;
  }
  if( thechar == 65 || thechar == 97  ){
    charmap = bitcharA;
  }

  if( thechar == 66 || thechar == 98  ){
    charmap = bitcharB;
  }

  if( thechar == 67 || thechar == 99  ){
    charmap = bitcharC;
  }

  if( thechar == 68 || thechar == 100  ){
    charmap = bitcharD;
  }

  if( thechar == 69 || thechar == 101  ){
    charmap = bitcharE;
  }

  if( thechar == 70 || thechar == 102  ){
    charmap = bitcharF;
  }

  if( thechar == 71 || thechar == 103  ){
    charmap = bitcharG;
  }

  if( thechar == 72 || thechar == 104  ){
    charmap = bitcharH;
  }

  if( thechar == 73 || thechar == 105  ){
    charmap = bitcharI;
  }

  if( thechar == 74 || thechar == 106  ){
    charmap = bitcharJ;
  }

  if( thechar == 75 || thechar == 107  ){
    charmap = bitcharK;
  }

  if( thechar == 76 || thechar == 108  ){
    charmap = bitcharL;
  }


  if( thechar == 77 || thechar == 109  ){
    charmap = bitcharM;
  }


  if( thechar == 78 || thechar == 110  ){
    charmap = bitcharN;
  }


  if( thechar == 79 || thechar == 111  ){
    charmap = bitcharO;
  }


  if( thechar == 80 || thechar == 112  ){
    charmap = bitcharP;
  }


  if( thechar == 81 || thechar == 113  ){
    charmap = bitcharQ;
  }

  if( thechar == 82 || thechar == 114  ){
    charmap = bitcharR;
  }


  if( thechar == 83 || thechar == 115  ){
    charmap = bitcharS;
  }


  if( thechar == 84 || thechar == 116  ){
    charmap = bitcharT;
  }


  if( thechar == 85 || thechar == 117  ){
    charmap = bitcharU;
  }


  if( thechar == 86 || thechar == 118  ){
    charmap = bitcharV;
  }


  if( thechar == 87 || thechar == 119  ){
    charmap = bitcharW;
  }


  if( thechar == 88 || thechar == 120  ){
    charmap = bitcharX;
  }


  if( thechar == 89 || thechar == 121  ){
    charmap = bitcharY;
  }


  if( thechar == 90 || thechar == 122  ){
    charmap = bitcharZ;
  }

    if( thechar == 32 ){
    charmap = bitcharSPACE;
  }


  for(int cy=0; cy<5; cy++){
    for(int cx=0; cx<3; cx++){
      setPixel(x+cx,y+cy, charmap[cy][cx] ? 2 : 0);
    }
  }
}

void MatrixDisplay::displayString(uint8_t x, uint8_t y, String theString){
  uint8_t xOffset = 0;
  Serial.print("About to print string: "+theString);
  Serial.print("length is: ");
  Serial.print(theString.length());
  Serial.print("\n\n");
  for(uint8_t i=0; i<theString.length(); i++){
    displayChar(x+xOffset, y, theString.charAt(i));
    Serial.print(theString.charAt(i));
    Serial.print(" x=");
    Serial.print((x+xOffset));
    Serial.print(" y=");
    Serial.print(y);
    Serial.print("\n");
    xOffset+=4;
  }
}

void MatrixDisplay::setPixel(uint8_t x,uint8_t y, uint8_t value){
  if( (x<SCREEN_WIDTH) && (y<SCREEN_HEIGHT) ){
    futureScreenMatrix[y][x] = value;
  }
}

void MatrixDisplay::clearScreen(bool withDisplay){
  for(int x=0; x<SCREEN_WIDTH; x++){
    for(int y=0; y<SCREEN_HEIGHT; y++){
      setPixel(x,y,0);
    }
  }
  if(withDisplay){
    updateDisplay(true);
  }
}

void MatrixDisplay::scrollText(String toscroll){
  clearScreen(true);
  int spacing = toscroll.length()*CHAR_WIDTH;
  for (int x=(SCREEN_WIDTH); x>(0-(spacing)); x--) {
    clearScreen(false);
    displayString(x, 2, toscroll);
    display();
    delay(50);
  }
}
