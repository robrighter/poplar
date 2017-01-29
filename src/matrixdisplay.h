#ifndef MATRIXDISPLAY_H
#define MATRIXDISPLAY_H
#include "application.h"


void display();
void setPixel(uint8_t x, uint8_t y, uint8_t value);
void scrollText(String toscroll);
void displayChar(uint8_t x, uint8_t y, char todisplay);
void matrixDisplaySetup();
void test();
void clearScreen(bool withDisplay);
void displayString(uint8_t x, uint8_t y, String theString);

#endif