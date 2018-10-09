#include "time.h"


#include <iostream>

#include <sdl/SDL.h>



double time::_time_prev = 0;
double time::_time_fps_prev = 0;
uint   time::_fps = 0;
float  time::_dt = 0;


double time::get_time()
{
    return SDL_GetPerformanceCounter() * 1000 / (double)SDL_GetPerformanceFrequency();
}

float time::get_delta_time()
{
    return _dt;
}

void time::update()
{
    double time_current = get_time();
    _dt = time_current - _time_prev;
    _time_prev = time_current;

    if(get_time() - _time_fps_prev >= 1000)
    {
        std::cout << _fps <<std::endl;
        _fps=0;
        _time_fps_prev = get_time();
    }
    _fps++;
}