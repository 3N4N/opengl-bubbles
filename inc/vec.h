#ifndef _VEC_H_
#define _VEC_H_

struct vec
{
    double x,y,z;
};

vec cross_product(vec a, vec b);
double dot_product(vec a, vec b);

#endif // _VEC_H_

