#ifndef MATRIXDISPLAY_H
#define MATRIXDISPLAY_H
#include "application.h"
#include <Adafruit_PWMServoDriver.h>

#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 8

#define CHAR_WIDTH 14

#define SERVOMIN  172// this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 410 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMID 291
#define NUMBER_OF_DRIVERS 8

#define OE_PIN 4
#define IGNORE_DRIVER 55

typedef struct PWMLocation PWMLocation;
struct PDMLocation {
  uint8_t driverIndex;
  uint8_t servoIndex;
};

class MatrixDisplay {
  public:
    MatrixDisplay();
    void display();
    void setPixel(uint8_t x, uint8_t y, uint8_t value);
    void scrollText(String toscroll);
    void displayChar(uint8_t x, uint8_t y, char todisplay);
    void matrixDisplaySetup();
    void test();
    void clearScreen(bool withDisplay);
    void displayString(uint8_t x, uint8_t y, String theString);

  private:
    void getPDMLocationForCoords(uint8_t x, uint8_t y, struct PDMLocation *outvar);
    boolean transposePixel(uint8_t x,uint8_t y);
    void updateDisplay(bool force);

    Adafruit_PWMServoDriver driver[NUMBER_OF_DRIVERS] =  {
      Adafruit_PWMServoDriver(0x40),
      Adafruit_PWMServoDriver(0x41),
      Adafruit_PWMServoDriver(0x42),
      Adafruit_PWMServoDriver(0x43),
      Adafruit_PWMServoDriver(0x44),
      Adafruit_PWMServoDriver(0x45),
      Adafruit_PWMServoDriver(0x46),
      Adafruit_PWMServoDriver(0x47)
    };

    uint8_t existingScreenMatrix[8][16] = {
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };


    uint8_t futureScreenMatrix[8][16] = {
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };

    //characters
    static const boolean bitchar0[5][3];
    static const boolean bitchar1[5][3];
    static const boolean bitchar2[5][3];
    static const boolean bitchar3[5][3];
    static const boolean bitchar4[5][3];
    static const boolean bitchar5[5][3];
    static const boolean bitchar6[5][3];
    static const boolean bitchar7[5][3];
    static const boolean bitchar8[5][3];
    static const boolean bitchar9[5][3];
    static const boolean bitcharA[5][3];
    static const boolean bitcharB[5][3];
    static const boolean bitcharC[5][3];
    static const boolean bitcharD[5][3];
    static const boolean bitcharE[5][3];
    static const boolean bitcharF[5][3];
    static const boolean bitcharG[5][3];
    static const boolean bitcharH[5][3];
    static const boolean bitcharI[5][3];
    static const boolean bitcharJ[5][3];
    static const boolean bitcharK[5][3];
    static const boolean bitcharL[5][3];
    static const boolean bitcharM[5][3];
    static const boolean bitcharN[5][3];
    static const boolean bitcharO[5][3];
    static const boolean bitcharP[5][3];
    static const boolean bitcharQ[5][3];
    static const boolean bitcharR[5][3];
    static const boolean bitcharS[5][3];
    static const boolean bitcharT[5][3];
    static const boolean bitcharU[5][3];
    static const boolean bitcharV[5][3];
    static const boolean bitcharW[5][3];
    static const boolean bitcharX[5][3];
    static const boolean bitcharY[5][3];
    static const boolean bitcharZ[5][3];
    static const boolean bitcharSPACE[5][3];


};


#endif
