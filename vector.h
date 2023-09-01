#include <assert.h>
#include <stdlib.h>
#include <math.h>

struct Vector 
{
    double x = 0;
    double y = 0;
};

void VectorCtor (const Vector *vec, const double x, const double y);
