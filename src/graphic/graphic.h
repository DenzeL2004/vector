#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#include "../plane/plane.h"


int ShowWindow();



void     DrawLine    (sf::RenderWindow &window, 
                      const Dot &dot_begin, const Dot &dot_end, const sf::Color color_line);

void     DrawCircle  (sf::RenderWindow &window, const Dot &dot, 
                      const float radius, const sf::Color color);



#endif //#endif _GRAPHIC_H_