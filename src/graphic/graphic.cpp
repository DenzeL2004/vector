#include "graphic.h"
#include "graphic_config.h"


static void     InitCoordPlanes (Plane *left_coord_plane, Plane *right_coord_plane);

static void     DrawEmptyPlane  (sf::RenderWindow *window, const Plane *coord_plane);


static void DrawAxis(sf::RenderWindow *window, const Plane *coord_plane, const Vector *dir);


static void     DrawLine    (sf::RenderWindow *window, const Plane *coord_plane, 
                             const Dot dot_begin, const Dot dot_end, const sf::Color color_line);

static void     DrawCircle  (sf::RenderWindow *window, const Dot dot, 
                             const float radius, const sf::Color color);



int ShowWindow()
{
    sf::RenderWindow window(sf::VideoMode(Default_window_weight, Default_window_hight), "Vectors");

    Plane left_coord_plane;
    Plane right_coord_plane ;

    InitCoordPlanes(&left_coord_plane, 
                    &right_coord_plane);

    DrawEmptyPlane(&window, &left_coord_plane);
    DrawEmptyPlane(&window, &right_coord_plane);

    char update_window_flag = TRUE;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (update_window_flag == TRUE)
        {
            window.display();
            update_window_flag = FALSE;
        }

    }


    return 0;
}

//===============================================================================

static void InitCoordPlanes(Plane *left_coord_plane, Plane *right_coord_plane)
{
    assert(left_coord_plane  != nullptr && "left_coord_plane is nullptr");
    assert(right_coord_plane != nullptr && "right_coord_plane is nullptr");

    PlaneCtor(  left_coord_plane, 
                left_plane_origin, left_plane_hight, left_plane_weight,
                left_axis_origin,  left_abscissa,    left_ordinate);   

    PlaneCtor(  right_coord_plane, 
                right_plane_origin, right_plane_hight, right_plane_weight,
                right_axis_origin,  right_abscissa,    right_ordinate);   

    return;
}

//===============================================================================

static void DrawEmptyPlane(sf::RenderWindow *window, const Plane *coord_plane)
{
    assert(window != nullptr && "window pointer is nullptr");
    assert(coord_plane != nullptr && "coord_plane pointer is nullptr");

    sf::RectangleShape rect(sf::Vector2f((float)coord_plane->plane_weight, 
                                         (float)coord_plane->plane_hight));

    rect.setPosition((float)coord_plane->plane_origin.x, 
                     (float)coord_plane->plane_origin.y);

    (*window).draw(rect);

    Vector vec_tmp = VectorSum(&Null_dot, &coord_plane->abscissa);
    DrawAxis(window, coord_plane, &vec_tmp);

    vec_tmp = VectorMultScalar(&vec_tmp, -1.f);
    DrawAxis(window, coord_plane, &vec_tmp);

    vec_tmp = VectorSum(&Null_dot, &coord_plane->ordinate);
    DrawAxis(window, coord_plane, &vec_tmp);

    vec_tmp = VectorMultScalar(&vec_tmp, -1.f);
    DrawAxis(window, coord_plane, &vec_tmp);

    return;
}


static void DrawAxis(sf::RenderWindow *window, const Plane *coord_plane, const Vector *dir)
{
    assert(window != nullptr && "window pointer is nullptr");
    assert(coord_plane != nullptr && "coord_plane pointer is nullptr");

    assert(dir != nullptr && "dir is nullptr");

    float x_start = (float)coord_plane->plane_origin.x + (float)coord_plane->axis_origin.x;
    float y_start = (float)coord_plane->plane_origin.y + (float)coord_plane->axis_origin.y;

    float left_border  = (float)coord_plane->plane_origin.x;
    float right_border = (float)coord_plane->plane_origin.x + (float)coord_plane->plane_weight;
    
    float up_border   = (float)coord_plane->plane_origin.y;
    float down_border = (float)coord_plane->plane_origin.y + (float)coord_plane->plane_hight;

    Dot dot_prev;
    VectorCtor(&dot_prev, (double)x_start, (double)y_start);

    Dot dot_next = VectorSum(&dot_prev, dir);

    Dot dot_tmp = Null_dot;

    while (dot_next.x < right_border && dot_next.x > left_border &&
           dot_next.y < down_border  && dot_next.y > up_border)
    {
        DrawLine(window, coord_plane, dot_prev, dot_next, sf::Color::Blue);
        DrawCircle(window, dot_prev, Stroke_radius, sf::Color::Blue);


        dot_prev = VectorSum(&dot_next, &Null_dot);   
        dot_next = VectorSum(&dot_next, dir);           
    }

    VectorDtor(&dot_prev);
    VectorDtor(&dot_next);
    VectorDtor(&dot_tmp);
    

    return;
}

//===============================================================================

static void DrawCircle(sf::RenderWindow *window, const Dot dot, 
                       const float radius, const sf::Color color)
{
    assert(window != nullptr && "window pointer is nullptr");

    sf::CircleShape circle(radius);
    circle.setFillColor(color);

    circle.setPosition((float)dot.x, (float)dot.y);

    (*window).draw(circle);

    return;
   
}

//===============================================================================

static void DrawLine(sf::RenderWindow *window, const Plane *coord_plane, 
                    const Dot dot_begin, const Dot dot_end, const sf::Color color_line)
{
    assert(window != nullptr && "window pointer is nullptr");
    assert(coord_plane != nullptr && "coord_plane pointer is nullptr");

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f((float)dot_begin.x, (float)dot_begin.y), color_line),
        sf::Vertex(sf::Vector2f((float)dot_end.x, (float)dot_end.y), color_line)
    };

    (*window).draw(line, 2, sf::Lines);

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

void VectorsInfoDtor (Vectors_info *vector_info)
{
    assert(vector_info != nullptr && "vector_info pointer is nullptr");

    vector_info->vectors_cnt = 0;
    
    free(vector_info->vectors);
    free(vector_info->vectors_draw_flag);

    return;
}

//===============================================================================
