#include "main.h"

int
main(int argc, char** argv) {
    PPM image = ppm_create(PPM_TYPE,
                           IMAGE_WIDTH,
                           IMAGE_HEIGHT,
                           IMAGE_MAX_VALUE);
    
    for (i32 j = IMAGE_HEIGHT; j >= 0; j--) {
        for (i32 i = 0; i < IMAGE_WIDTH; i++) {
            f32 rf32 = (f32)(i) / (IMAGE_WIDTH - 1);
            f32 gf32 = (f32)(j) / (IMAGE_WIDTH - 1);
            f32 bf32 = 0.25f;
            
            Col32 pixelColour = {0};
            pixelColour.r = (u8)(255.999f * rf32);
            pixelColour.g = (u8)(255.999f * gf32);
            pixelColour.b = (u8)(255.999f * bf32);
            
            ppm_write(&image, pixelColour);
        }
    }
    
    
    FILE* file = fopen("image.ppm","w");
    fprintf(file,"%s", (char*)image.data);
    
    //FREE
    ppm_free(&image);
    fclose(file);
    
    return (0);
}
