#include "gui.h"

#include "input.h"


rect::rect(float x,float y,float width,float height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

bool rect::point_inside(glm::vec2 p)
{
    return (
        p.x>_x && p.x<_x+_width&&
        p.y>_y && p.y<_y+_height
    );
}
bool rect::point_inside(float px,float py)
{
    return (
        px>_x && px<_x+_width&&
        py>_y && py<_y+_height
    );
}


std::unordered_map<char,character> gui::_freetype_char;

std::string gui::_focused_name = "";


std::vector<std::pair<key,std::pair<char,char>>> text_key =
{
    {key::A,{'a','A'}},
    {key::B,{'b','B'}},
    {key::C,{'c','C'}},
    {key::D,{'d','D'}},
    {key::E,{'e','E'}},
    {key::F,{'f','F'}},
    {key::G,{'g','G'}},
    {key::H,{'h','H'}},
    {key::I,{'i','I'}},
    {key::J,{'j','J'}},
    {key::K,{'k','K'}},
    {key::L,{'l','L'}},
    {key::M,{'m','M'}},
    {key::N,{'n','N'}},
    {key::O,{'o','O'}},
    {key::P,{'p','P'}},
    {key::Q,{'q','Q'}},
    {key::R,{'r','R'}},
    {key::S,{'s','S'}},
    {key::T,{'t','T'}},
    {key::U,{'u','U'}},
    {key::V,{'v','V'}},
    {key::W,{'w','W'}},
    {key::X,{'x','X'}},
    {key::Y,{'y','Y'}},
    {key::Z,{'z','Z'}},
    {key::ONE,{'1','!'}},
    {key::TWO,{'2','@'}},
    {key::THREE,{'3','#'}},
    {key::FOUR,{'4','$'}},
    {key::FIVE,{'5','%'}},
    {key::SIX,{'6','^'}},
    {key::SEVEN,{'7','&'}},
    {key::EIGHT,{'8','*'}},
    {key::NINE,{'9','('}},
    {key::ZERO,{'0',')'}},
    {key::LEFTBRACKET,{'[','{'}},
    {key::RIGHTBRACKET,{']','}'}},
    {key::COMMA,{',','<'}},
    {key::SPACE,{' ',' '}},
    {key::MINUS,{'-','_'}},
    {key::EQUALS,{'=','+'}},
    {key::PERIOD,{'.','>'}},
    {key::APOSTROPHE,{'\'','\"'}},
    {key::SLASH,{'/','?'}},
    {key::BACKSLASH,{'\\','|'}},
    {key::SEMICOLON,{';',':'}}
};



shader* gui::_text_shader = 0;
uint gui::_text_pos = 0;

void gui::text_area(rect r,std::string name,std::string& text)
{

    int f = has_focus(name);
    int pi = r.point_inside(input::get_mouse_posf());

    float c = 1.0 * f +(0.9*pi+ 0.8*(1-pi))*(1-f);


    renderer::use_program(0);
    glColor3f(1,1,1);
    renderer::simple_quad(r._x,r._y,r._x+r._width,r._y+r._height);

    glColor3f(c,c,c);
    renderer::simple_quad(r._x+0.01f,r._y+0.01f,r._x+r._width-0.01f,r._y+r._height-0.01f);
    

    std::string display_text;
    display_text = text.substr(0,_text_pos);
    if(f)display_text.push_back('|');
    display_text += text.substr(_text_pos);

#define RTEXT(x) renderer::simple_text(r._x+0.01f,r._y+(r._height *0.8f),r._width,(r._height *1.6f),_text_shader->get_id(),x)

     RTEXT(display_text);

    if(!f)
    {
        if(input::get_mouse_press(mouse_button::BUTTON_LEFT) && pi)
        {
            set_focus(name);
            _text_pos = text.size();
        }
    }
    else
    {

#define GETKEY(x) (input::get_key_press(x) && input::get_key_prev_releas(x))

        for(int i=0;i<text_key.size();i++)
        {
            if(GETKEY(text_key[i].first))
            {
                int m = input::get_key_press(key::LSHIFT);
                char letter = text_key[i].second.second * m + text_key[i].second.first *(1-m);

                text.insert(text.begin()+_text_pos,letter);
                _text_pos++;
            }
        }
    
        if(GETKEY(key::BACKSPACE))
        {
            if(text.size()>=_text_pos && text.size()>0 && _text_pos>0)
            {
                text.erase(text.begin()+(--_text_pos));
            }
        }

        if(GETKEY(key::DELETE))
        {
            if(text.size()>_text_pos)
                text.erase(text.begin()+_text_pos);
        }

        if(GETKEY(key::LEFT) && _text_pos > 0)
        {
            _text_pos--;
        }

        if(GETKEY(key::RIGHT) && _text_pos < text.size())
        {
            _text_pos++;
        }

        if(GETKEY(key::RETURN))
            set_focus("");

#undef GETKEY
#undef RTEXT
    }
}


bool gui::button(rect r,std::string name)
{

    glColor3f(0,0,0);
    renderer::simple_quad(r._x+0.01f,r._y+0.01f,r._x+0.01f+r._width,r._y+0.01f+r._height);
    glColor3f(1,1,1);
    renderer::simple_quad(r._x,r._y,r._x+r._width,r._y+r._height);

    return (r.point_inside(input::get_mouse_posf()) && 
        input::get_mouse_press(mouse_button::BUTTON_LEFT));

}

void gui::init()
{

    FT_Library freetype;
    FT_Face    face;
    
    if(FT_Init_FreeType(&freetype))
        std::cout << "freetype failed to initialize" << std::endl;

    if(FT_New_Face(freetype,"cour.ttf",0,&face))
        std::cout << "failed to load freetype face" << std::endl;

    FT_Set_Pixel_Sizes(face,0,48);


    renderer::pixel_storei(pname::UNPACK_ALIGNMENT,1);

    for (uint8 c = 0; c < 128; c++)
    {
        
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "failed to load char: " << c << std::endl;
            continue;
        }
        
        
        uint texture;
        renderer::gen_textures(1, &texture);
        renderer::bind_texture(target::TEXTURE_2D,texture);
        renderer::teximage2d(
            target::TEXTURE_2D,
            0,
            internal_format::RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            format::RED,
            type::UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        
        
        renderer::texparameteri(target::TEXTURE_2D, pname::TEXTURE_WRAP_S, param::CLAMP_TO_EDGE);
        renderer::texparameteri(target::TEXTURE_2D, pname::TEXTURE_WRAP_T, param::CLAMP_TO_EDGE);
        renderer::texparameteri(target::TEXTURE_2D, pname::TEXTURE_MIN_FILTER, param::LINEAR);
        renderer::texparameteri(target::TEXTURE_2D, pname::TEXTURE_MAG_FILTER, param::LINEAR);
        
        
        uint advance = face->glyph->advance.x;

        int w = face->glyph->bitmap.width;
        int h = face->glyph->bitmap.rows;

        int bearingx = face->glyph->bitmap_left;
        int bearingy = face->glyph->bitmap_top;

        character character(texture, advance, glm::ivec2(w,h),glm::ivec2(bearingx,bearingy));

        _freetype_char[c] = character;
    }

    renderer::pixel_storei(pname::PACK_ALIGNMENT,1);

    FT_Done_Face(face);
    FT_Done_FreeType(freetype);



    _text_shader = new shader("text_shader.glsl");
}