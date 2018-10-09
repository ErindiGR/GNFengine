#ifndef SYSTEM_H
#define SYSTEM_H


#include <sdl/SDL.h>


class system
{

    static SDL_Event _event;


public:

    static void init();
    static void term();
    static void event();
    static void update();
    static void draw();  


    static SDL_Event& get_event();
};


#endif //!SYSTEM_H