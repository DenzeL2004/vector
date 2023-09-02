#include "generals_func/generals.h"
#include "log_info/log_errors.h"

struct Vector 
{
    double x = 0;
    double y = 0;
};

void VectorCtor (const Vector *vec, const double x, const double y);


void VectorDtor (Vector *vec);