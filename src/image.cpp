#include "image.h"

#define IMAGE_STRING_LENGTH 48

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

void Image::setImageFromString(String imageString){
    Particle.publish("setImageFromString", imageString);
    if(imageString.length() != IMAGE_STRING_LENGTH){
        //if the stringis not the exact length, just return
        return;
    }
    int i = 0;
    
    //parse out the bytes
    int imageBytes[16];
    for(i=0; i<16; i++){
        imageBytes[i] = imageString.substring(i*3,(i*3)+3).toInt();
    }
    
    //now translate the bytes into bit strings
    bool bitArray[128];
    int bitCount = 0;
    for(i=0; i<16; i++){
        bitArray[bitCount++] = (0b11111110 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b11111101 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b11111011 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b11110111 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b11101111 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b11011111 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b10111111 & imageBytes[i]) ? true : false;
        bitArray[bitCount++] = (0b01111111 & imageBytes[i]) ? true : false;
    }
    
    //now write out the screen
    for(i=0; i<128; i++){
        int y = i/16;
        int x = i%16;
        setPixel(x, y, bitArray[i] ? 2 : 0);
    }
    
}
