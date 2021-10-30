/* date = August 15th 2020 4:24 am */

#ifndef PPM_H
#define PPM_H

#include "colour.h"

#define IMAGE_WIDTH 300
#define IMAGE_HEIGHT 200
#define IMAGE_MAX_VALUE 255
#define PPM_TYPE 3
#define DEFAULT_PPM_SIZE MB(10)

global i32
testArray[] = {
    255, 0, 0,  // red
    0, 255, 0, // green
    0, 0, 255,  // blue
    255, 255, 0,  // yellow
    255, 255, 255,  // white
    0, 0, 0  // black
};

typedef struct PPM {
    u8 type;
    u16 width;
    u16 height;
    u16 maxValue;
    void* data;
    u32 allocation;
    memoryIndex allocationUsed;
} PPM;

internal PPM
ppm_create(u8 type,
           u16 width,
           u16 height,
           u16 maxValue) {
    PPM result = {
        .type = type,
        .width = width,
        .height = height,
        .maxValue = maxValue,
        .data = (char*)malloc(DEFAULT_PPM_SIZE),
        .allocation = DEFAULT_PPM_SIZE
    };
    char* charData = (char*)result.data;
    sprintf(result.data,
            "P%d\n%d %d\n%d\n",
            result.type, result.width, result.height,result.maxValue);
    memoryIndex counter = 0;
    
    while (charData[counter] != '\0') {
        counter++;
    }
    result.allocationUsed = counter;
    
    return (result);
}

internal void
ppm_free(PPM* ppm) {
    ppm->allocation = 0;
    ppm->allocationUsed = 0;
    free(ppm->data);
}

internal i32
ppm_write(PPM* ppm, Col32 pixelColour) {
    char* charData = (char*)ppm->data;
    i32 errorCode = 0;
    
    errorCode = sprintf(charData + ppm->allocationUsed,
                        "%d %d %d\n",
                        pixelColour.r, pixelColour.g, pixelColour.b);
    
    memoryIndex counter = ppm->allocationUsed;
    while (charData[counter] != '\0') {
        counter++;
    }
    ppm->allocationUsed = counter;
    
    return (errorCode);
}

#endif //PPM_H
