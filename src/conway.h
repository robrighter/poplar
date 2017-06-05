#ifndef CONWAY_H
#define CONWAY_H
#include "application.h"

#define CANVAS_WIDTH 16
#define CANVAS_HEIGHT 8
#define CONWAY_CHANGE_SLEEP_SECONDS 10

class Conway {
  public:
    Conway();
    bool getValueAtLocation(uint8_t x, uint8_t y);
    void processNextCycle();
    

  private:
    void setValueAtLocation(bool toset, uint8_t x, uint8_t y);
    bool calculateValueAtLocation(uint8_t x, uint8_t y);
    void seedTheCanvas();
    bool canvas[CANVAS_HEIGHT][CANVAS_WIDTH] = {
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
      {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}
    };

};


#endif
