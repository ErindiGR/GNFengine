#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "commun.h"


#include "renderer.h"
#include "shader.h"

class rect
{

    float _x,_y;
    float _width,_height;

    friend class gui;

public:

    rect(float x,float y,float width,float height);

    bool point_inside(glm::vec2 p);
    bool point_inside(float px,float py);
};




class character
{
    uint _texture;
    uint _advance;
    glm::ivec2 _size;
    glm::ivec2 _bearing;

    friend class gui;

public:

    character()
    {
        _texture = 0;
        _advance = 0;
        _size = glm::ivec2(0,0);
        _bearing =  glm::ivec2(0,0);
    }

    character(uint texture,uint advance,glm::ivec2 size,glm::ivec2 bearing)
    {
        _texture = texture;
        _advance = advance;
        _size = size;
        _bearing = bearing;
    }

    inline uint get_texture(){return _texture;}
    inline uint get_advance(){return _advance;}
    inline glm::ivec2 get_size(){return _size;}
    inline glm::ivec2 get_bearing(){return _bearing;}

};





class gui
{

    static std::unordered_map<char,character> _freetype_char;

    static std::string _focused_name;
    
    
    static shader*_text_shader;
    static uint _text_pos;

public:

    static void init();

    static inline void set_focus(std::string name)
    {
        _focused_name = name;
    }

    static inline bool has_focus(std::string name)
    {
        return (_focused_name == name);
    }

    static inline std::unordered_map<char,character>& get_freetype_char()
    {
        return _freetype_char;
    }

    static void text_area(rect r,std::string name,std::string& text);
    static bool button(rect r,std::string name);

};


#endif //!GUI_H