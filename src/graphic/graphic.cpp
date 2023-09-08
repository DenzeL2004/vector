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


static int      CheckDotOnPlane (const Plane &coord_plane, Dot &dot);


static char     DrawOnButton    (sf::RenderWindow &window, 
                                 Plane &left_coord_plane, Plane &right_coord_plane);

static Dot      ZoomDot         (const Plane &coord_plane, const Dot &dot);


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

    Vector vec(-1.0, 1.0);
    Dot dot(10, 3);
    DrawVector(window, left_coord_plane, Null_dot, vec);


    sf::Event event;
    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(event.type == sf::Event::MouseButtonPressed)
        {
            update_window_flag = DrawOnButton(window, left_coord_plane, right_coord_plane);
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
    Dot dot_prev = coord_plane.axis_origin;
    Dot dot_next = dot_prev + dir;

    while (CheckDotOnPlane(coord_plane, dot_next))
    {
        DrawCircle(window, dot_prev, Stroke_radius, Default_axis_color);

        dot_prev  = dot_next;   
        dot_next += dir;       
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
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f((float)dot_begin.GetX(), (float)dot_begin.GetY()), color_line),
        sf::Vertex(sf::Vector2f((float)dot_end.GetX(), (float)dot_end.GetY()), color_line)
    };

    window.draw(line, 2, sf::Lines);

    return;
   
}

//===============================================================================

static void DrawVector(sf::RenderWindow &window, const Plane &coord_plane, 
                       const Dot &dot_start, const Vector &dir)
{

    Vector norm_res = ~ (Vector)dir;
    Vector norm_ort = (&norm_res); 
    
    Vector tendril1 = ~((norm_ort + norm_res));
    Vector tendril2 = ~((norm_res - norm_ort));

    tendril1 *= (!(Vector)dir) / 5.0;
    tendril2 *= (!(Vector)dir) / 5.0;

    Dot coord1 = dir - tendril1;
    Dot coord2 = dir - tendril2;

    Dot dot_begin = ZoomDot(coord_plane, dot_start) + coord_plane.axis_origin;
    Dot dot_end   = ZoomDot(coord_plane, dir) + dot_begin;

    if (!CheckDotOnPlane(coord_plane, dot_begin) ||
        !CheckDotOnPlane(coord_plane, dot_end))
    {
        printf("line cannot be drawn because one of the coordinates is out of plane's bounds");
        return;
    }

    DrawLine(window, dot_begin, dot_end, Default_vec_color);

    Dot zoom_coord1 = ZoomDot(coord_plane, coord1) + dot_begin;
    Dot zoom_coord2 = ZoomDot(coord_plane, coord2) + dot_begin;;

    DrawLine(window, dot_end, zoom_coord1, Default_vec_color);
    DrawLine(window, dot_end, zoom_coord2, Default_vec_color);

    return;
   
}

static Dot ZoomDot(const Plane &coord_plane, const Dot &dot)
{
    Vector vec1 = coord_plane.abscissa * dot.GetX();
    Vector vec2 = coord_plane.ordinate * dot.GetY();

    Dot new_dot = vec1 + vec2;

    return new_dot;
}

//===============================================================================


static int CheckDotOnPlane(const Plane &coord_plane, Dot &dot)
{

    double left_border  = coord_plane.plane_origin.GetX();
    double right_border = coord_plane.plane_origin.GetX() + (double)coord_plane.plane_weight;
    
    double up_border   = coord_plane.plane_origin.GetY();
    double down_border = coord_plane.plane_origin.GetY() + (double)coord_plane.plane_hight;

    double dot_x = dot.GetX();
    double dot_y = dot.GetY();

    return  (dot_x < right_border) && (dot_x > left_border) &&
            (dot_y < down_border)  && (dot_y > up_border);  
}

//===============================================================================

static char DrawOnButton(sf::RenderWindow &window, 
                         Plane &left_coord_plane, Plane &right_coord_plane)
{
    Dot mouse_coord((double)sf::Mouse::getPosition(window).x, 
                    (double)sf::Mouse::getPosition(window).y);

    
    printf ("%lg %lg\n", mouse_coord.GetX(), mouse_coord.GetY());

    if (CheckDotOnPlane(left_coord_plane, mouse_coord))
    {
        mouse_coord = mouse_coord - left_coord_plane.plane_origin;
        DrawVector(window, left_coord_plane, Null_dot, ~mouse_coord);

        return TRUE;
    }
    else if (CheckDotOnPlane(right_coord_plane, mouse_coord))
    {
        mouse_coord = mouse_coord - right_coord_plane.plane_origin;
        DrawVector(window, right_coord_plane, Null_dot, ~mouse_coord);

        return TRUE;
    } 

    return FALSE;
}