#include "vec.h"

vec cross_product(vec a, vec b)
{
    vec prod;

    prod.x = a.y * b.z - b.y * a.z;
    prod.y = a.z * b.x - b.z * a.x;
    prod.z = a.x * b.y - b.x * a.y;

    return prod;
}

double dot_product(vec a, vec b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
