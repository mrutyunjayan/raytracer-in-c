/* date = August 17th 2020 2:05 pm */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef Vec3f Point3f;

typedef struct Ray {
    Point3f origin;
    Vec3f direction;
} Ray;

Point3f
RayAtT(Ray* ray,
       f32 t);

#endif //RAY_H

//~

#if defined (RAY_IMPLEMENTATION)

Point3f
RayAtT(Ray* ray,
       f32 t) {
    Vec3f scaledVec = vec3f_scaleUp((const Vec3f*)(&ray->direction),
                                    t);
    return vec3f_add((const Vec3f*)(&ray->origin),
                     (const Vec3f*)&scaledVec);
}

#undef RAY_IMPLEMENTATION
#endif // IMPLEMENTATION
