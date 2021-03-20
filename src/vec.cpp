#include "vec.h"


double dot_product(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

vec3 cross_product(vec3 a, vec3 b)
{
    vec3 prod;

    prod.x = a.y * b.z - b.y * a.z;
    prod.y = a.z * b.x - b.z * a.x;
    prod.z = a.x * b.y - b.x * a.y;

    return prod;
}

double dot_product(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
