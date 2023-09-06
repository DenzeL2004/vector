#include "graphic.h"
#include "graphic_config.h"


static void     InitCoordPlanes (Plane *left_coord_plane, Plane *right_coord_plane);

static void     DrawEmptyPlane  (sf::RenderWindow &window, const Plane &coord_plane);


static void     DrawAxis    (sf::RenderWindow &window, const Plane &coord_plane, const Vector &dir);


static void     DrawLine    (sf::RenderWindow &window, 
                             const Dot &dot_begin, const Dot &dot_end, const sf::Color color_line);

static void     DrawCircle  (sf::RenderWindow &window, const Dot &dot, 
                             const float radius, const sf::Color color);


static void     DrawVector  (sf::RenderWindow &window, const Plane &coord_plane, 
                             const Dot &dot_start, const Vector &dir);


int ShowWindow()
{
    sf::RenderWindow window(sf::VideoMode(Default_window_weight, Default_window_hight), "Vectors");

    Plane left_coord_plane;
    Plane right_coord_plane;

    InitCoordPlanes(&left_coord_plane, 
                    &right_coord_plane);

    DrawEmptyPlane(window, left_coord_plane);
    DrawEmptyPlane(window, right_coord_plane);

    char update_window_flag = TRUE;

    Vector vec = Vector(10, -10); //check maybe vector too long 
    DrawVector(window, left_coord_plane, Null_dot, vec);

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

static void DrawEmptyPlane(sf::RenderWindow &window, const Plane &coord_plane)
{
    sf::RectangleShape rect(sf::Vector2f((float)coord_plane.plane_weight, 
                                         (float)coord_plane.plane_hight));

    rect.setPosition((float)coord_plane.plane_origin.GetX(), 
                     (float)coord_plane.plane_origin.GetY());

    window.draw(rect);

    Vector vec_tmp = coord_plane.abscissa;
    DrawAxis(window, coord_plane, vec_tmp);

    vec_tmp *= -1.f;
    DrawAxis(window, coord_plane, vec_tmp);

    vec_tmp = coord_plane.ordinate;
    DrawAxis(window, coord_plane, vec_tmp);

    vec_tmp *= -1.f;
    DrawAxis(window, coord_plane, vec_tmp);

    return;
}


static void DrawAxis(sf::RenderWindow &window, const Plane &coord_plane, const Vector &dir)
{

    double left_border  = coord_plane.plane_origin.GetX();
    double right_border = coord_plane.plane_origin.GetX() + (double)coord_plane.plane_weight;
    
    double up_border   = coord_plane.plane_origin.GetY();
    double down_border = coord_plane.plane_origin.GetY() + (double)coord_plane.plane_hight;

    Dot dot_prev = coord_plane.axis_origin;
    Dot dot_next = dot_prev + dir;

    double dot_next_x = dot_next.GetX();
    double dot_next_y = dot_next.GetY();

    while (dot_next_x < right_border && dot_next_x > left_border &&
           dot_next_y < down_border  && dot_next_y > up_border)
    {
        DrawCircle(window, dot_prev, Stroke_radius, Default_axis_color);

        dot_prev  = dot_next;   
        dot_next += dir;       

        dot_next_x = dot_next.GetX();
        dot_next_y = dot_next.GetY();
    }
    
    DrawLine(window, coord_plane.axis_origin, dot_prev, Default_axis_color);

    return;
}

//===============================================================================

static void DrawCircle(sf::RenderWindow &window, const Dot &dot, 
                       const float radius, const sf::Color color)
{

    sf::CircleShape circle(radius);
    circle.setFillColor(color);

    circle.setPosition((float)dot.GetX(), (float)dot.GetY());

    window.draw(circle);

    return;
   
}

//===============================================================================

static void DrawLine(sf::RenderWindow &window, 
                    const Dot &dot_begin, const Dot &dot_end, const sf::Color color_line)
{

    //TODO MUST BE CHECK THAT LINE can be too long then plane

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f((float)dot_begin.GetX(), (float)dot_begin.GetY()), color_line),
        sf::Vertex(sf::Vector2f((float)dot_end.GetX(), (float)dot_end.GetY()), color_line)
    };

    window.draw(line, 2, sf::Lines);

    return;
   
}

static void DrawVector(sf::RenderWindow &window, const Plane &coord_plane, 
                       const Dot &dot_start, const Vector &dir)
{
    //refactory later

    Vector vec1 = coord_plane.abscissa * dot_start.GetX();
    Vector vec2 = coord_plane.ordinate * dot_start.GetY();

    Dot dot_begin = vec1 + vec2 + coord_plane.axis_origin;

    vec1 = coord_plane.abscissa * dir.GetX();
    vec2 = coord_plane.ordinate * dir.GetY();
    
    Dot dot_end = vec1 + vec2 + dot_begin;
    

   // printf ()

    DrawLine(window, dot_begin, dot_end, Default_vec_color);

    sf::CircleShape circle(Stroke_radius);
    circle.setFillColor(Default_vec_color);

    circle.setPosition((float)dot_end.GetX(), (float)dot_end.GetY());

    window.draw(circle);

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
