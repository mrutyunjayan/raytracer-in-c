#include "main.h"
#include "outString.h"
#include "ppm.h"
#include "vec3.h"
#include "ray.h"

#define WIDTH 3
#define HEIGHT 2
#define MAX_VALUE 255
#define PPM_TYPE 3

int main(int argc, char** argv) {
    outString buffer;
    buffer.data = (char*)malloc(DEFAULT_STRING_SIZE);
    buffer.allocation = DEFAULT_STRING_SIZE;
    
    ppmInfo* image = ppmCreateInfo(PPM_TYPE,
                                   WIDTH,
                                   HEIGHT,
                                   MAX_VALUE);
    if (ppmPrint(image,
                 &buffer) < 0) {
        printf("ERROR writing to string");
        return (-1);
    }
    
    Ray test;
    
    test.origin.x = 0.0;
    test.origin.y = 0.0;
    test.origin.z = 0.0;
    test.direction.x = 1.0;
    test.direction.y = 1.0;
    test.direction.z = 1.0;
    
    printf("Memory occuppied by Ray: %d\n",
           sizeof(test));
    printf("Ray Origin: %d\nRay Direction: %d\n",
           test.origin.x,
           test.direction.x);
    
    FILE* fileHandle = fopen("image.ppm",
                             "w");
    fprintf(fileHandle,
            "%s", buffer.data);
    //FREE
    free(buffer.data);
    ppmDeleteInfo(image);
    
    return (0);
}
