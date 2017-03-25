#include "image.h"

Image::Image(){}

void Image::reset(){
    seconds = 1;
    isActive = false;
    
    for(int x=0; x < 16; x++){
        for(int y=0; y < 8; y++){
            setPixel(x,y,0);
        }
    }
}

void Image::setPixel(uint8_t x, uint8_t y, uint8_t value){
    bitmap[y][x] = value;
}

uint8_t Image::readPixel(uint8_t x, uint8_t y){
    return bitmap[y][x];
}
