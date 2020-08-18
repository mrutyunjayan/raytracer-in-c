/* date = August 15th 2020 4:24 am */

#ifndef PPM_H
#define PPM_H

#include <string.h>

#define numOfElements(a)                                                       \
{ (sizeof(a) / sizeof(a[0])) }
// size of array / size of each element in the array}
//   bytes       /          bytes

global int testArray[] ={
    255, 0, 0,  // red
    0, 255, 0, // green
    0, 0, 255,  // blue
    255, 255, 0,  // yellow
    255, 255, 255,  // white
    0, 0, 0};  // black

typedef struct {
    uint8_t type;
    uint16_t width;
    uint16_t height;
    uint16_t maxValue;
} ppmInfo;

ppmInfo* ppmCreateInfo(uint8_t type,
                       uint16_t width,
                       uint16_t height,
                       uint16_t maxValue) {
    ppmInfo* newPpmInfo = (ppmInfo*)malloc(sizeof(ppmInfo));
    
    newPpmInfo->type = type;
    newPpmInfo->width = width;
    newPpmInfo->height = height;
    newPpmInfo->maxValue = maxValue;
    
    return (newPpmInfo);
}

void ppmDeleteInfo(ppmInfo* ppm) {
    free(ppm);
}

int ppmPrint(ppmInfo* ppm,
             outString* buffer) {
    uint16_t errorCode = 0;
    errorCode = sprintf(buffer->data,
                        "P%d\n%d %d\n%d\n",
                        ppm->type, ppm->width, ppm->height,ppm->maxValue);
    outStringUpdateLength(buffer);
    
    int i = 0;
    int arraySize = numOfElements(testArray);
    while (errorCode >= 0 && i < arraySize) {
        errorCode = sprintf(buffer->data + buffer->length,
                            "%d %d %d\n",
                            testArray[i], testArray[i + 1], testArray[i + 2]);
        i = i + 3;
        outStringUpdateLength(buffer);
    }
    return (errorCode);
}



#endif //PPM_H
