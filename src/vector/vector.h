#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#define USE_DUMP

struct Vector 
{
    double x = 0;
    double y = 0;
};

enum Vector_errors
{
    X_COORD_IS_NAN = 1 << 0, 
    Y_COORD_IS_NAN = 1 << 1
};


void    VectorCtor  (Vector *vec, const double x, const double y);

void    VectorDtor  (Vector *vec);


Vector  VectorSum        (const Vector *vec1, const Vector *vec2);

Vector  VectorSub        (const Vector *vec1, const Vector *vec2);

Vector  VectorMultScalar (const Vector *vec, const double num);


typedef Vector Dot;

const Dot Null_dot = {0, 0};

const Vector Unit_vector_x = {1, 0};
const Vector Unit_vector_y = {0, 1};


#endif //#endif _VECTOR_H_