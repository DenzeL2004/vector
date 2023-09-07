#ifndef _GRAPHIC_CONFIG_H_
#define _GRAPHIC_CONFIG_H_

const uint32_t Default_window_hight  = 1200;
const uint32_t Default_window_weight = 1600;

const uint32_t Default_plane_hight  = (uint32_t)((double)Default_window_hight  / 1.1);
const uint32_t Default_plane_weight = (uint32_t)((double)Default_window_weight / 1.75);

const double X_plane_start = 10.0;
const double Y_plane_start = 10.0;

const Dot Left_corner  = Vector(X_plane_start, Y_plane_start);
const Dot Right_corner = Vector(X_plane_start + Default_plane_weight + 50, Y_plane_start);


//===============================================================================
//LEFT COORD PLANE
const Dot      left_plane_origin = Left_corner;
const uint32_t left_plane_hight  = Default_plane_hight;
const uint32_t left_plane_weight = Default_plane_weight;

const Dot      left_axis_origin  = Vector(100.0, 100.0);
const Vector   left_abscissa     = Vector(10.0, 0.0);
const Vector   left_ordinate     = Vector(0.0, -10.0);

//RIGHT COORD PLANE
const Dot      right_plane_origin = Right_corner;
const uint32_t right_plane_hight  = Default_plane_hight;
const uint32_t right_plane_weight = Default_plane_weight;

const Dot      right_axis_origin  = Vector(300.0, 500.0);
const Vector   right_abscissa     = Vector(10.0, 0.0);
const Vector   right_ordinate     = Vector(0.0, 10.0);

//===============================================================================

const uint32_t Max_limit_vector_cnt = 100;

const float Stroke_radius = 1.5f;

const double Len_tendril = 15.0;

const sf::Color Default_vec_color = sf::Color::Red;
const sf::Color Default_axis_color = sf::Color::Black;

#endif //#endif _GRAPHIC_CONFIG_H_