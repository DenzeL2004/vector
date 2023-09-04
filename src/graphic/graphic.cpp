#include "graphic.h"
#include "graphic_config.h"



int ShowWindow()
{
    sf::RenderWindow window(sf::VideoMode(Default_window_weight, Default_window_hight), "Vectors");

    Coord_plane left_coord_plane  = {};
    Coord_plane right_coord_plane = {};

    InitCoordPlanes(&left_coord_plane, &left_coord_plane);

    

        
}

//===============================================================================

static void InitCoordPlanes(Coord_plane *left_coord_plane, Coord_plane *right_coord_plane)
{
    assert(left_coord_plane  != nullptr && "left_coord_plane is nullptr");
    assert(right_coord_plane != nullptr && "left_coord_plane is nullptr");

    CoordPlaneCtor( left_coord_plane, 
                    left_plane_origin, left_plane_hight, left_plane_weight,
                    left_axis_origin,  left_abscissa,    left_ordinate);   

    CoordPlaneCtor( right_coord_plane, 
                    right_plane_origin, right_plane_hight, right_plane_weight,
                    right_axis_origin,  right_abscissa,    right_ordinate);   


    return;
}

//===============================================================================

//===============================================================================

void CoordPlaneCtor (Coord_plane *coord_plane, 
                    const Dot plane_origin, uint32_t plane_hight, const uint32_t plane_weight, 
                    const Dot axis_origin, const Vector abscissa, const Vector ordinate)
{
    assert(coord_plane != nullptr && "coord_plane pointer is nullptr");
   
    PlaneCtor(&coord_plane->plane, 
             plane_origin, plane_hight, plane_weight, 
             axis_origin, abscissa, ordinate);

    coord_plane->coord_plane_img.create(plane_weight, plane_hight, sf::Color::White);

    return;
}

//===============================================================================

void CoordPlaneDtor (Coord_plane *coord_plane)
{
    assert(coord_plane != nullptr && "coord_plane pointer is nullptr");
   
    PlaneDtor(&coord_plane->plane);

    return;
}

//===============================================================================

void VectorsInfoCtor (Vectors_info *vector_info)
{
    assert(vector_info != nullptr && "vector_info pointer is nullptr");

    vector_info->vectors_cnt = 0;
    
    vector_info->vectors = (Vector*) calloc(Max_limit_vector_cnt, sizeof(Vector));
    assert(vector_info->vectors != nullptr && "allocate memory failed");
    
    vector_info->vectors_draw_flag = (char*) calloc(Max_limit_vector_cnt, sizeof(char));
    assert(vector_info->vectors_draw_flag != nullptr && "allocate memory failed");

    return;
}

//===============================================================================

void VectorsInfoCtor (Vectors_info *vector_info)
{
    assert(vector_info != nullptr && "vector_info pointer is nullptr");

    vector_info->vectors_cnt = 0;
    
    free(vector_info->vectors);
    free(vector_info->vectors_draw_flag);

    return;
}

//===============================================================================
