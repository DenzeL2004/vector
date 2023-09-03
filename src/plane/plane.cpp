#include <SFML/Window.hpp>

#include "plane.h"



void PlaneCtor (Plane *plane, 
                const Dot plane_origin, uint32_t plane_hight, const uint32_t plane_weight, 
                const Dot axis_origin, const Vector abscissa, const Vector ordinate)
{
    assert(plane != nullptr && "plane pointer is nullptr");
   
    plane->plane_origin = plane_origin;
    plane->plane_hight  = plane_hight;
    plane->plane_weight = plane_weight;

    plane->axis_origin  = axis_origin;
    plane->abscissa     = abscissa;
    plane->ordinate     = ordinate;

    return;
}

void PlaneDtor (Plane *plane)
{
    assert(plane != nullptr && "plane pointer is nullptr");
   
    plane->plane_origin = Null_dot;
    plane->plane_hight  = 0;
    plane->plane_weight = 0;

    plane->axis_origin  = Null_dot;
    plane->abscissa     = Null_dot;
    plane->ordinate     = Null_dot;

    return;
}

void DrawVector()
{
    
    return;
}