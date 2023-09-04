#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#include "../plane/plane.h"

struct Vectors_info
{
    uint32_t vectors_cnt = 0;
    Vector *vectors = nullptr;

    char *vectors_draw_flag = nullptr;
};



int ShowWindow();


void VectorsInfoCtor (Vectors_info *vector_info);

void VectorsInfoDtor (Vectors_info *vector_info);

#endif //#endif _GRAPHIC_H_