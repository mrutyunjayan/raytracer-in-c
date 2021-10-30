/* date = October 26th 2021 11:11 pm */

#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"

typedef Vec3f Col3f;

typedef union Col32 {
    struct {
        u8 r, g, b, a;
    };
    u32 colour;
} Col32;

#endif //COLOUR_H

//~

#if defined (COLOUR_IMPLEMENTATION)

#if 0
internal void
colour_writeToPPMBuffer(PPM image, Col32 pixelColour) {
    if ((image.allocationUsed + sizeof(Col32) < image.allocation)) {
        u32* outData = (u32*)image.data;
        *outData = pixelColour.colour;
        image.allocationUsed += sizeof(Col32);
    }
}
#endif

#undef COLOUR_IMPLEMENTATION
#endif // IMPLEMENTATION

