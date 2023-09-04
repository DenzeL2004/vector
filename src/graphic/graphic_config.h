#ifndef _GRAPHIC_CONFIG_H_
#define _GRAPHIC_CONFIG_H_

const uint32_t Default_window_hight  = 1200;
const uint32_t Default_window_weight = 1600;

const uint32_t Default_plane_hight  = (uint32_t)((double)Default_window_hight  / 1.5);
const uint32_t Default_plane_weight = (uint32_t)((double)Default_window_weight / 2.3);

const Dot Left_corner  = {10, 10};
const Dot Right_corner = {Left_corner.x + Default_plane_weight + 50, 10};


//===============================================================================
//LEFT COORD PLANE
const Dot      left_plane_origin = Left_corner;
const uint32_t left_plane_hight  = Default_plane_hight;
const uint32_t left_plane_weight = Default_plane_weight;

const Dot      left_axis_origin  = {100, 100};
const Vector   left_abscissa     = {10, 0};
const Vector   left_ordinate     = {0, 10};

//RIGHT COORD PLANE
const Dot      right_plane_origin = Right_corner;
const uint32_t right_plane_hight  = Default_plane_hight;
const uint32_t right_plane_weight = Default_plane_weight;

const Dot      right_axis_origin  = {300, 500};
const Vector   right_abscissa     = {10, 10};
const Vector   right_ordinate     = {-10, 10};

//===============================================================================

const uint32_t Max_limit_vector_cnt = 100;

const float Stroke_radius = 1.f;


#endif //#endif _GRAPHIC_CONFIG_H_