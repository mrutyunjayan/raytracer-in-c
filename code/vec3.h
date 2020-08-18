/* date = August 15th 2020 10:37 am */

#ifndef VEC3_H
#define VEC3_H

#define real32 float
#define real64 double

#include <math.h>

typedef union {
    struct {
        real32 x;
        real32 y;
        real32 z;
    };
    struct Colour {
        real32 r;
        real32 g;
        real32 b;
    };
    real32 array[3];
} Vec3;

inline real32 vec3Magnitude(const Vec3* vec3) {
    return (sqrt(  vec3->x * vec3->x
                 + vec3->y * vec3->y
                 + vec3->z * vec3->z));
}

inline Vec3 vec3Cross(const Vec3* vec1,
                      const Vec3* vec2) {
    return (Vec3) {
        vec1->x * vec2->x + vec1->x * vec2->y + vec1->x * vec2->z,
        vec1->y * vec2->x + vec1->y * vec2->y + vec1->y * vec2->z,
        vec1->z * vec2->x + vec1->z * vec2->y + vec1->z * vec2->z
    };
}

inline real32 vec3Dot(const Vec3* vec1,
                      const Vec3* vec2) {
    return (  vec1->x * vec2->x
            + vec1->y + vec2->y
            + vec1->z + vec2->z);
}

inline Vec3  vec3Add(const Vec3* vec1,
                     const Vec3* vec2) {
    return (Vec3) {
        vec1->x + vec2->x,
        vec1->y + vec2->y,
        vec1->z + vec2->z,
    };
}

inline Vec3 vec3ScaleUp(const Vec3* vec3,
                        real32 factor) {
    return (Vec3) {
        factor * vec3->x,
        factor * vec3->y,
        factor * vec3->z
    };
}

inline Vec3 vec3ScaleDown(const Vec3* vec3,
                          real32 factor) {
    return (Vec3) {
        vec3->x /factor,
        vec3->y /factor,
        vec3->z /factor
    };
}

inline Vec3 vec3UnitVector(const Vec3* vec3) {
    return vec3ScaleDown(vec3,
                         vec3Magnitude(vec3));
}




#endif //VEC3_H
