#include "vector.h"


void VectorCtor (Vector *vec, const double x, const double y)
{
    assert(vec != nullptr && "vec pointer is nullptr");

    assert(!isnan(x) && "coord x is NAN");
    assert(!isnan(y) && "coord y is NAN");
   
    vec->x = x;
    vec->y = y;

    return;
}

void VectorDtor (Vector *vec)
{
    assert(vec != nullptr && "vec pointer is nullptr");

    vec->x = NAN;
    vec->y = NAN;

    return;
}

void VectorAdd (Vector *vec1, Vector *vec2)
{
    assert(vec1 != nullptr && "vec1 pointer is nullptr");
    assert(vec2 != nullptr && "vec2 pointer is nullptr");

    vec1->x += vec2->x;
    vec1->y += vec2->y;

    return;
}

void VectorSub (Vector *vec1, Vector *vec2)
{
    assert(vec1 != nullptr && "vec1 pointer is nullptr");
    assert(vec2 != nullptr && "vec2 pointer is nullptr");

    vec1->x -= vec2->x;
    vec1->y -= vec2->y;

    return;
}

void VectorMultScalar (Vector *vec1, const double num)
{
    assert(vec1 != nullptr && "vec1 pointer is nullptr");

    vec1->x *= num;
    vec1->y *= num;

    return;
}