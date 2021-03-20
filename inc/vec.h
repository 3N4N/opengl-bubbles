#ifndef _VEC_H_
#define _VEC_H_

#include "point.h"
#include "vec.h"

struct vec2
{
    double x,y;
};


struct vec3
{
    double x,y,z;
};


double dot_product(vec2 a, vec2 b);

vec3 cross_product(vec3 a, vec3 b);
double dot_product(vec3 a, vec3 b);

#endif // _VEC_H_

