#ifndef MATRIXDISPLAY_H
#define MATRIXDISPLAY_H
#include "application.h"
#include <Adafruit_PWMServoDriver.h>
#include "image.h"

#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 8

#define CHAR_WIDTH 14

#define FONT_HEIGHT 6
#define FONT_WIDTH 3

#define SERVOMIN  172// this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 410 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMID 291
#define NUMBER_OF_DRIVERS 8
#define NUMBER_OF_IMAGE_FRAMES 20

#define OE_PIN 4
#define IGNORE_DRIVER 55
#define BATCH_DELAY_MILLIS 700

typedef struct PWMLocation PWMLocation;
struct PDMLocation {
  uint8_t driverIndex;
  uint8_t servoIndex;
};

class MatrixDisplay {
  public:
    MatrixDisplay();
    void display();
    void display(bool flutter);
    void setPixel(uint8_t x, uint8_t y, uint8_t value);
    void scrollText(String toscroll);
    void displayChar(uint8_t x, uint8_t y, char todisplay);
    void matrixDisplaySetup();
    void test();
    void clearScreen(bool withDisplay);
    void displayString(uint8_t x, uint8_t y, String theString);
    void centerString(String theString);
    void renderFrame(uint8_t frameIndex);
    Image imageFrames[NUMBER_OF_IMAGE_FRAMES];
    

  private:
    uint8_t calculatePixelWidth(String theString);
    void getPDMLocationForCoords(uint8_t x, uint8_t y, struct PDMLocation *outvar);
    boolean transposePixel(uint8_t x,uint8_t y);
    void updateDisplay(bool force);
    void updateDisplay(bool force, bool flutter);

    Adafruit_PWMServoDriver driver[NUMBER_OF_DRIVERS];

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
    static const boolean bitchar0[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar1[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar2[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar3[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar4[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar5[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar6[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar7[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar8[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitchar9[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharA[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharB[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharC[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharD[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharE[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharF[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharG[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharH[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharI[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharJ[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharK[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharL[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharM[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharN[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharO[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharP[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharQ[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharR[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharS[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharT[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharU[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharV[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharW[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharX[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharY[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharZ[FONT_HEIGHT][FONT_WIDTH];
    static const boolean bitcharSPACE[FONT_HEIGHT][FONT_WIDTH];


};


#endif
