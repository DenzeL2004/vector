#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#include "../plane/plane.h"

struct Coord_plane
{
    sf::Image coord_plane_img;
    Plane plane; 
};

struct Vectors_info
{
    uint32_t vectors_cnt = 0;
    Vector *vectors = nullptr;

    char *vectors_draw_flag = nullptr;
};

// enum Graphic_errors
// {

// };


void VectorsInfoCtor (Vectors_info *vector_info);

void VectorsInfoCtor (Vectors_info *vector_info);



void CoordPlaneCtor (Coord_plane *coord_plane, 
                    const Dot plane_origin, uint32_t plane_hight, const uint32_t plane_weight, 
                    const Dot axis_origin, const Vector abscissa, const Vector ordinate);

void CoordPlaneDtor (Coord_plane *coord_plane);


#endif //#endif _GRAPHIC_H_