#ifndef _PLANE_H_
#define _PLANE_H_

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#include "../vector/vector.h"

struct Plane
{
    Dot      plane_origin = Null_dot;
    uint32_t plane_hight  = 0;
    uint32_t plane_weight = 0;
    
    Dot    axis_origin  = Null_dot;
    Vector abscissa     = Unit_vector_x;
    Vector ordinate     = Unit_vector_y;
};

void PlaneCtor (Plane *plane, 
                const Dot plane_origin, uint32_t plane_hight, const uint32_t plane_weight, 
                const Dot axis_origin, const Vector abscissa, const Vector ordinate);


void PlaneDtor (Plane *plane);



#endif //#endif _PLANE_H_