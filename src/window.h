#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <glm/glm.hpp>

#include <sdl/SDL.h>

#include "commun.h"

class window
{
    SDL_Window* _window;

    SDL_GLContext _glcontext;

    std::string _name;

    uint _width;
    uint _height;

    static std::shared_ptr<window> _current;

    bool _close;

public:

    window(std::string name,uint width,uint height);
    ~window();


    bool get_close();
    void close();
    void swap_buffer();

    inline glm::ivec2 get_size()
    {
        return glm::ivec2(_width,_height);
    }

    inline float get_aspect()
    {
        return (float)_width/(float)_height;
    }

    //use on when the program ends
    void term();

    static void set_current(std::shared_ptr<window> w);
    static std::weak_ptr<window> get_current();
};

#endif //!WINDOW_H