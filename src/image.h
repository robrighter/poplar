#ifndef IMAGE_H
#define IMAGE_H
#include "application.h"

class Image {
  public:
    Image();
    uint8_t seconds = 1;
    bool isActive = false;
    void reset();
    void setPixel(uint8_t x, uint8_t y, uint8_t value);
    uint8_t readPixel(uint8_t x, uint8_t y);
    void setImageFromString(String);
    
  private:
    uint8_t bitmap[8][16] = {
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    

};


#endif
