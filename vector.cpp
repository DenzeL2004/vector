#include "vector.h"


void VectorCtor (Vector *vec, const double x, const double y)
{
    assert(vec != nullptr && "vec pointer is nullptr");

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