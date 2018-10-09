#include "window.h"

#include <assert.h>
#include "system.h"


std::shared_ptr<window> window::_current;

window::window(std::string name,uint width,uint height)
{

    _name = name;

    _width = width;

    _height = height;

    _close = false;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    _window = SDL_CreateWindow(name.c_str(),100,100,width,height,SDL_WINDOW_OPENGL);
	
	_glcontext = SDL_GL_CreateContext(_window);

	SDL_GL_MakeCurrent(_window,_glcontext);

}



window::~window()
{
    if(_window)
        SDL_DestroyWindow(_window);
}


void window::set_current(std::shared_ptr<window> w)
{
    _current = w;
}

std::weak_ptr<window> window::get_current()
{
    return _current;
}

bool window::get_close()
{
    return (system::get_event().type == SDL_QUIT) || _close;
}

void window::close()
{
    _close = true;
}

void window::swap_buffer()
{
    SDL_GL_SwapWindow(_window);
}

void window::term()
{
    SDL_DestroyWindow(_window);
    _window = 0;
}