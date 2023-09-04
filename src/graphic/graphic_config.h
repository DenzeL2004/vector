#ifndef _GRAPHIC_CONFIG_H_
#define _GRAPHIC_CONFIG_H_

const uint32_t Default_window_hight  = 600;
const uint32_t Default_window_weight = 800;

const uint32_t Default_plane_hight  = 252;
const uint32_t Default_plane_weight = 336;

const Dot Shift_dot = {10, 10};


//===============================================================================
//LEFT COORD PLANE
const Dot      left_plane_origin = Null_dot;
const uint32_t left_plane_hight  = Default_plane_hight;
const uint32_t left_plane_weight = Default_plane_weight;

const Dot      left_axis_origin  = Null_dot;
const Vector   left_abscissa     = Unit_vector_x;
const Vector   left_ordinate     = Unit_vector_y;

//RIGHT COORD PLANE
const Dot      right_plane_origin = Null_dot;
const uint32_t right_plane_hight  = Default_plane_hight;
const uint32_t right_plane_weight = Default_plane_weight;

const Dot      right_axis_origin  = Null_dot;
const Vector   right_abscissa     = Unit_vector_x;
const Vector   right_ordinate     = Unit_vector_y;

//===============================================================================

const uint32_t Max_limit_vector_cnt = 100;


#endif //#endif _GRAPHIC_CONFIG_H_