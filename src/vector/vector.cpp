#include "vector.h"


uint32_t    VectorVerification  (Vector *vec);

void        VectorDump          (Vector *vec);


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

Vector VectorAdd (Vector *vec1, Vector *vec2)
{
    assert(vec1 != nullptr && "vec1 pointer is nullptr");
    assert(vec2 != nullptr && "vec2 pointer is nullptr");

    Vector res = {};
    VectorCtor(&res, vec1->x + vec2->x, vec1->y + vec2->y);

    if (VectorVerification(&res))
        VectorDump(&res);

    return res;
}

Vector VectorSub (Vector *vec1, Vector *vec2)
{
    assert(vec1 != nullptr && "vec1 pointer is nullptr");
    assert(vec2 != nullptr && "vec2 pointer is nullptr");

    Vector res = {};
    VectorCtor(&res, vec1->x - vec2->x, vec1->y - vec2->y);

    if (VectorVerification(&res))
        VectorDump(&res);

    return res;
}

Vector VectorMultScalar (Vector *vec, const double num)
{
    assert(vec != nullptr && "vec pointer is nullptr");
    
    Vector res = {};
    VectorCtor(&res, vec->x * num, vec->y * num);

    if (VectorVerification(&res))
        VectorDump(&res);

    return res;
}

uint32_t VectorVerification (Vector *vec)
{
    assert(vec != nullptr && "vec pointer is nullptr");

    uint32_t error_code = 0;

    if (isnan(vec->x)) error_code |= X_COORD_IS_NAN;

    if (isnan(vec->y)) error_code |= Y_COORD_IS_NAN;

    return error_code;
}

void VectorDump (Vector *vec)
{
    assert(vec != nullptr && "vec pointer is nullptr");

    uint32_t error_code = VectorVerification(vec);

    char *vec_ptr = (char*)vec;

    #ifdef USE_DUMP
        
            printf("vector pointer = (%p)\n\n"
                   "x_coord = %.5g\n"
                   "y_coord = %.5g\n\n", vec_ptr, vec->x, vec->y);

    #endif

    if (error_code & X_COORD_IS_NAN)
    {
        LOG_REPORT("x coord of vector(%p) is NAN value.\n", vec_ptr);
        
        #ifdef USE_DUMP
            printf("x coord of vector is NAN value.\n");
        #endif
    }

    if (error_code & Y_COORD_IS_NAN)
    {
        LOG_REPORT("y coord of vector(%p) is NAN value.\n", vec_ptr);
        
        #ifdef USE_DUMP
            printf("y coord of vector is NAN value.\n");
        #endif
    }

    return;
}