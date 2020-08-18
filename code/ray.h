/* date = August 17th 2020 2:05 pm */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

#define Point3 Vec3

typedef struct {
    Point3 origin;
    Vec3 direction;
} Ray;

inline Point3 RayAtT(Ray* ray,
                     real32 t) {
    Vec3 scaledVec = vec3ScaleUp ((const Vec3*)(&ray->direction),
                                  t);
    return (Point3)(vec3Add((const Vec3*)(&ray->origin),
                            (const Vec3*)&scaledVec));
}


#endif //RAY_H
