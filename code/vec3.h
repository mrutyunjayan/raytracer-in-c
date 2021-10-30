/* date = August 15th 2020 10:37 am */

#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef union Vec3f {
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
    struct{
        f32 r;
        f32 g;
        f32 b;
    };
    f32 array[3];
} Vec3f;

typedef union Vec3i {
    struct {
        i32 x;
        i32 y;
        i32 z;
    };
    struct{
        i32 r;
        i32 g;
        i32 b;
    };
    i32 array[3];
} Vec3i;

f32
vec3f_magnitude(const Vec3f* vec);

Vec3f
vec3f_cross(const Vec3f* vec1,
            const Vec3f* vec2);

f32
vec3f_dot(const Vec3f* vec1,
          const Vec3f* vec2);

Vec3f
vec3f_add(const Vec3f* vec1,
          const Vec3f* vec2);

Vec3f
vec3f_scaleUp(const Vec3f* vec,
              f32 factor);

Vec3f
vec3f_scaleDown(const Vec3f* vec,
                f32 factor);

Vec3f
vec3f_unitVector(const Vec3f* vec);


#endif //VEC3_H
//~

#if defined (VEC3_IMPLEMENTATION)

f32
vec3f_magnitude(const Vec3f* vec) {
    return (sqrtf(  vec->x * vec->x
                  + vec->y * vec->y
                  + vec->z * vec->z));
}

Vec3f
vec3f_cross(const Vec3f* vec1,
            const Vec3f* vec2) {
    return (Vec3f) {
        vec1->x * vec2->x + vec1->x * vec2->y + vec1->x * vec2->z,
        vec1->y * vec2->x + vec1->y * vec2->y + vec1->y * vec2->z,
        vec1->z * vec2->x + vec1->z * vec2->y + vec1->z * vec2->z
    };
}

f32
vec3f_dot(const Vec3f* vec1,
          const Vec3f* vec2) {
    return (  vec1->x * vec2->x
            + vec1->y + vec2->y
            + vec1->z + vec2->z);
}

Vec3f
vec3f_add(const Vec3f* vec1,
          const Vec3f* vec2) {
    return (Vec3f) {
        vec1->x + vec2->x,
        vec1->y + vec2->y,
        vec1->z + vec2->z,
    };
}

Vec3f
vec3f_scaleUp(const Vec3f* vec,
              f32 factor) {
    return (Vec3f) {
        factor * vec->x,
        factor * vec->y,
        factor * vec->z
    };
}

Vec3f
vec3f_scaleDown(const Vec3f* vec,
                f32 factor) {
    return (Vec3f) {
        vec->x /factor,
        vec->y /factor,
        vec->z /factor
    };
}

Vec3f
vec3f_unitVector(const Vec3f* vec) {
    return vec3f_scaleDown(vec,
                           vec3f_magnitude(vec));
}

#undef VEC3_IMPLEMENTATION
#endif // IMPLEMENTATION

