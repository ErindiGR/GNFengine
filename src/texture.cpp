#include "texture.h"

#include <sdl/SDL.h>


#include "renderer.h"


library<texture> texture_library(2048u);


texture::texture(std::string path)
{
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());

    if(!surface)
    {
        std::cout << "failed to load: " << path << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    std::cout << "loading file: " << path << std::endl;

    _width = surface->w;
    _height = surface->h;
    _id = 0;


    _data.reserve(_width*_height*surface->format->BytesPerPixel);

    for(int i=0;i<_width*_height*surface->format->BytesPerPixel;i++)
        _data.push_back(((uint8*)surface->pixels)[i]);


    std::cout 
    << "width: "    << _width                               << std::endl
    << "height: "   << _height                              << std::endl
    << "channels: " << (uint)surface->format->BytesPerPixel << std::endl;
    
    SDL_FreeSurface(surface);

    std::cout << "file: " << path << " loaded successfully" << std::endl;


    gen();
}

texture::texture(std::string path,std::vector<uint8> data,uint width,uint height)
{
    _data = data;
    _width = width;
    _height = height;
    _id = 0;

    gen();
}

texture::~texture()
{
    degen();
}

void texture::gen()
{
    renderer::gen_textures(1, &_id);

    renderer::bind_texture(target::TEXTURE_2D, _id);


    renderer::teximage2d(target::TEXTURE_2D,0,internal_format::RGB,
    _width,_height,0,format::RGBA,GL_UNSIGNED_INT_8_8_8_8,&(_data[0]));

    renderer::texparameteri(target::TEXTURE_2D,pname::TEXTURE_MIN_FILTER,param::LINEAR_MIPMAP_LINEAR);
    renderer::texparameteri(target::TEXTURE_2D,pname::TEXTURE_MAG_FILTER,param::LINEAR_MIPMAP_LINEAR);
    renderer::texparameteri(target::TEXTURE_2D,pname::TEXTURE_WRAP_S,param::REPEAT);
    renderer::texparameteri(target::TEXTURE_2D,pname::TEXTURE_WRAP_T,param::REPEAT);

    renderer::gnerate_mipmap(target::TEXTURE_2D);

    renderer::bind_texture(target::TEXTURE_2D, 0);
}

void texture::degen()
{
    renderer::delete_texture(1,&_id);
}

void texture::bind()
{
    renderer::bind_texture(target::TEXTURE_2D, _id);
}