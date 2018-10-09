#include "input.h"

#include <iostream>

#include <sdl/SDL.h>

#include "system.h"

#include "window.h"

std::unordered_map<std::string,key>  input::string_key_map=
{
{std::string("UNKNOWN"),(key)0},

{std::string("A"),(key)4},
{std::string("B"),(key)5},
{std::string("C"),(key)6},
{std::string("D"),(key)7},
{std::string("E"),(key)8},
{std::string("F"),(key)9},
{std::string("G"),(key)10},
{std::string("H"),(key)11},
{std::string("I"),(key)12},
{std::string("J"),(key)13},
{std::string("K"),(key)14},
{std::string("L"),(key)15},
{std::string("M"),(key)16},
{std::string("N"),(key)17},
{std::string("O"),(key)18},
{std::string("P"),(key)19},
{std::string("Q"),(key)20},
{std::string("R"),(key)21},
{std::string("S"),(key)22},
{std::string("T"),(key)23},
{std::string("U"),(key)24},
{std::string("V"),(key)25},
{std::string("W"),(key)26},
{std::string("X"),(key)27},
{std::string("Y"),(key)28},
{std::string("Z"),(key)29},

{std::string("ONE"),(key)30},
{std::string("TWO"),(key)31},
{std::string("THREE"),(key)32},
{std::string("FOR"),(key)33},
{std::string("FIVE"),(key)34},
{std::string("SIX"),(key)35},
{std::string("SEVEN"),(key)36},
{std::string("EIGHT"),(key)37},
{std::string("NINE"),(key)38},
{std::string("ZERO"),(key)39},

{std::string("1"),(key)30},
{std::string("2"),(key)31},
{std::string("3"),(key)32},
{std::string("4"),(key)33},
{std::string("5"),(key)34},
{std::string("6"),(key)35},
{std::string("7"),(key)36},
{std::string("8"),(key)37},
{std::string("9"),(key)38},
{std::string("0"),(key)39},

{std::string("RETURN"),(key)40},
{std::string("ESCAPE"),(key)41},
{std::string("BACKSPACE"),(key)42},
{std::string("TAB"),(key)43},
{std::string("SPACE"),(key)44},

{std::string("MINUS"),(key)45},
{std::string("EQUALS"),(key)46},
{std::string("LEFTBRACKET"),(key)47},
{std::string("RIGHTBRACKET"),(key)48},
{std::string("BACKSLASH"),(key)49}, 

{std::string("-"),(key)45},
{std::string("="),(key)46},
{std::string("["),(key)47},
{std::string("]"),(key)48},
{std::string("\\"),(key)49}, 

{std::string("NONUSHASH"),(key)50}, 

{std::string("SEMICOLON"),(key)51},
{std::string("APOSTROPHE"),(key)52},
{std::string("GRAVE"),(key)53}, 

{std::string("COMMA"),(key)54},
{std::string("PERIOD"),(key)55},
{std::string("SLASH"),(key)56},


{std::string(","),(key)54},
{std::string("."),(key)55},
{std::string("/"),(key)56},

{std::string("CAPSLOCK"),(key)57},

{std::string("F1"),(key)58},
{std::string("F2"),(key)59},
{std::string("F3"),(key)60},
{std::string("F4"),(key)61},
{std::string("F5"),(key)62},
{std::string("F6"),(key)63},
{std::string("F7"),(key)64},
{std::string("F8"),(key)65},
{std::string("F9"),(key)66},
{std::string("F10"),(key)67},
{std::string("F11"),(key)68},
{std::string("F12"),(key)69},

{std::string("PRINTSCREEN"),(key)70},
{std::string("SCROLLLOCK"),(key)71},
{std::string("PAUSE"),(key)72},
{std::string("INSERT"),(key)73}, 

{std::string("HOME"),(key)74},
{std::string("PAGEUP"),(key)75},
{std::string("DELETE"),(key)76},
{std::string("END"),(key)77},
{std::string("PAGEDOWN"),(key)78},
{std::string("RIGHT"),(key)79},
{std::string("LEFT"),(key)80},
{std::string("DOWN"),(key)81},
{std::string("UP"),(key)82},

{std::string("NUMLOCKCLEAR"),(key)83}, 

{std::string("KP_DIVIDE"),(key)84},
{std::string("KP_MULTIPLY"),(key)85},
{std::string("KP_MINUS"),(key)86},
{std::string("KP_PLUS"),(key)87},
{std::string("KP_ENTER"),(key)88},
{std::string("KP_1"),(key)89},
{std::string("KP_2"),(key)90},
{std::string("KP_3"),(key)91},
{std::string("KP_4"),(key)92},
{std::string("KP_5"),(key)93},
{std::string("KP_6"),(key)94},
{std::string("KP_7"),(key)95},
{std::string("KP_8"),(key)96},
{std::string("KP_9"),(key)97},
{std::string("KP_0"),(key)98},
{std::string("KP_PERIOD"),(key)99},

{std::string("NONUSBACKSLASH"),(key)100}, 

{std::string("APPLICATION"),(key)101}, 
{std::string("POWER"),(key)102},
{std::string("KP_EQUALS"),(key)103},
{std::string("F13"),(key)104},
{std::string("F14"),(key)105},
{std::string("F15"),(key)106},
{std::string("F16"),(key)107},
{std::string("F17"),(key)108},
{std::string("F18"),(key)109},
{std::string("F19"),(key)110},
{std::string("F20"),(key)111},
{std::string("F21"),(key)112},
{std::string("F22"),(key)113},
{std::string("F23"),(key)114},
{std::string("F24"),(key)115},
{std::string("EXECUTE"),(key)116},
{std::string("HELP"),(key)117},
{std::string("MENU"),(key)118},
{std::string("SELECT"),(key)119},
{std::string("STOP"),(key)120},
{std::string("AGAIN"),(key)121},  
{std::string("UNDO"),(key)122},
{std::string("CUT"),(key)123},
{std::string("COPY"),(key)124},
{std::string("PASTE"),(key)125},
{std::string("FIND"),(key)126},
{std::string("MUTE"),(key)127},
{std::string("VOLUMEUP"),(key)128},
{std::string("VOLUMEDOWN"),(key)129},

{std::string("KP_COMMA"),(key)133},
{std::string("KP_EQUALSAS400"),(key)134},

{std::string("INTERNATIONAL1"),(key)135}, 

{std::string("INTERNATIONAL2"),(key)136},
{std::string("INTERNATIONAL3"),(key)137}, 
{std::string("INTERNATIONAL4"),(key)138},
{std::string("INTERNATIONAL5"),(key)139},
{std::string("INTERNATIONAL6"),(key)140},
{std::string("INTERNATIONAL7"),(key)141},
{std::string("INTERNATIONAL8"),(key)142},
{std::string("INTERNATIONAL9"),(key)143},
{std::string("LANG1"),(key)144}, 
{std::string("LANG2"),(key)145},
{std::string("LANG3"),(key)146}, 
{std::string("LANG4"),(key)147}, 
{std::string("LANG5"),(key)148},
{std::string("LANG6"),(key)149}, 
{std::string("LANG7"),(key)150}, 
{std::string("LANG8"),(key)151}, 
{std::string("LANG9"),(key)152}, 

{std::string("ALTERASE"),(key)153}, 
{std::string("SYSREQ"),(key)154},
{std::string("CANCEL"),(key)155},
{std::string("CLEAR"),(key)156},
{std::string("PRIOR"),(key)157},
{std::string("RETURN2"),(key)158},
{std::string("SEPARATOR"),(key)159},
{std::string("OUT"),(key)160},
{std::string("OPER"),(key)161},
{std::string("CLEARAGAIN"),(key)162},
{std::string("CRSEL"),(key)163},
{std::string("EXSEL"),(key)164},

{std::string("KP_00"),(key)176},
{std::string("KP_000"),(key)177},
{std::string("THOUSANDSSEPARATOR"),(key)178},
{std::string("DECIMALSEPARATOR"),(key)179},
{std::string("CURRENCYUNIT"),(key)180},
{std::string("CURRENCYSUBUNIT"),(key)181},
{std::string("KP_LEFTPAREN"),(key)182},
{std::string("KP_RIGHTPAREN"),(key)183},
{std::string("KP_LEFTBRACE"),(key)184},
{std::string("KP_RIGHTBRACE"),(key)185},
{std::string("KP_TAB"),(key)186},
{std::string("KP_BACKSPACE"),(key)187},
{std::string("KP_A"),(key)188},
{std::string("KP_B"),(key)189},
{std::string("KP_C"),(key)190},
{std::string("KP_D"),(key)191},
{std::string("KP_E"),(key)192},
{std::string("KP_F"),(key)193},
{std::string("KP_XOR"),(key)194},
{std::string("KP_POWER"),(key)195},
{std::string("KP_PERCENT"),(key)196},
{std::string("KP_LESS"),(key)197},
{std::string("KP_GREATER"),(key)198},
{std::string("KP_AMPERSAND"),(key)199},
{std::string("KP_DBLAMPERSAND"),(key)200},
{std::string("KP_VERTICALBAR"),(key)201},
{std::string("KP_DBLVERTICALBAR"),(key)202},
{std::string("KP_COLON"),(key)203},
{std::string("KP_HASH"),(key)204},
{std::string("KP_SPACE"),(key)205},
{std::string("KP_AT"),(key)206},
{std::string("KP_EXCLAM"),(key)207},
{std::string("KP_MEMSTORE"),(key)208},
{std::string("KP_MEMRECALL"),(key)209},
{std::string("KP_MEMCLEAR"),(key)210},
{std::string("KP_MEMADD"),(key)211},
{std::string("KP_MEMSUBTRACT"),(key)212},
{std::string("KP_MEMMULTIPLY"),(key)213},
{std::string("KP_MEMDIVIDE"),(key)214},
{std::string("KP_PLUSMINUS"),(key)215},
{std::string("KP_CLEAR"),(key)216},
{std::string("KP_CLEARENTRY"),(key)217},
{std::string("KP_BINARY"),(key)218},
{std::string("KP_OCTAL"),(key)219},
{std::string("KP_DECIMAL"),(key)220},
{std::string("KP_HEXADECIMAL"),(key)221},

{std::string("LCTRL"),(key)224},
{std::string("LSHIFT"),(key)225},
{std::string("LALT"),(key)226},
{std::string("LGUI"),(key)227}, 
{std::string("RCTRL"),(key)228},
{std::string("RSHIFT"),(key)229},
{std::string("RALT"),(key)230}, 
{std::string("RGUI"),(key)231}, 

{std::string("MODE"),(key)257},

{std::string("AUDIONEXT"),(key)258},
{std::string("AUDIOPREV"),(key)259},
{std::string("AUDIOSTOP"),(key)260},
{std::string("AUDIOPLAY"),(key)261},
{std::string("AUDIOMUTE"),(key)262},
{std::string("MEDIASELECT"),(key)263},
{std::string("WWW"),(key)264},
{std::string("MAIL"),(key)265},
{std::string("CALCULATOR"),(key)266},
{std::string("COMPUTER"),(key)267},
{std::string("AC_SEARCH"),(key)268},
{std::string("AC_HOME"),(key)269},
{std::string("AC_BACK"),(key)270},
{std::string("AC_FORWARD"),(key)271},
{std::string("AC_STOP"),(key)272},
{std::string("AC_REFRESH"),(key)273},
{std::string("AC_BOOKMARKS"),(key)274},

{std::string("BRIGHTNESSDOWN"),(key)275},
{std::string("BRIGHTNESSUP"),(key)276},
{std::string("DISPLAYSWITCH"),(key)277}, 

{std::string("KBDILLUMTOGGLE"),(key)278},
{std::string("KBDILLUMDOWN"),(key)279},
{std::string("KBDILLUMUP"),(key)280},
{std::string("EJECT"),(key)281},
{std::string("SLEEP"),(key)282},

{std::string("APP1"),(key)283},
{std::string("APP2"),(key)284},

{std::string("AUDIOREWIND"),(key)285},
{std::string("AUDIOFASTFORWARD"),(key)286},
{std::string("NUM_SCANCODES"),(key)512}
};



std::array<uint8,1024> input::keystates_prev;
std::array<uint8,1024> input::keystates_current;
std::unordered_map<std::string,axis> input::axis_map(64);
glm::ivec2 input::mouse_pos_prev;
glm::ivec2 input::mouse_pos_current;

axis::axis():
    positive(2),
    negative(2)
{

}


void axis::add_keys(key p,key n)
{
    for(int i=0;i<positive.size();i++)
    {
        if(
        positive[i] == p || 
        positive[i] == n ||
        negative[i] == p || 
        negative[i] == n
        )
        {
            printf("key:%d or key:%d have been added before",p,n);
            return;
        }
    }

    negative.push_back(n);
    positive.push_back(p);
}

int  axis::get_value()
{
    int pos = 0;
    int neg = 0;

    for(int i=0;i<positive.size();i++)
    {
        pos = input::get_key_press(positive[i]);
        
        if(pos)
            break;
    }
    
    for(int i=0;i<negative.size();i++)
    {
        neg = input::get_key_press(negative[i]);
        
        if(neg)
            break;
    }

    return pos-neg;
}




void input::update()
{
    keystates_prev = keystates_current;

    const uint8* kbs = SDL_GetKeyboardState(0);

    for(int i=0;i<keystates_current.size();i++)
        keystates_current[i] = kbs[i];

    mouse_pos_prev = mouse_pos_current;
    SDL_GetMouseState(&mouse_pos_current.x,&mouse_pos_current.y);

}

glm::ivec2 input::get_mouse_pos()
{
    return mouse_pos_current;
}

glm::ivec2 input::get_mouse_delta()
{
    return mouse_pos_current-mouse_pos_prev;
}

bool input::get_mouse_press(mouse_button b)
{
    return (SDL_GetMouseState(0,0) == SDL_BUTTON((uint)b));
}
bool input::get_mouse_releas(mouse_button b)
{
    return (SDL_GetMouseState(0,0) != SDL_BUTTON((uint)b));
}

bool input::get_key_press(key k)
{
    int i = static_cast<int>(k);
    return keystates_current[i] == (uint8)keystate::PRESSED;
}

bool input::get_key_releas(key k)
{
    int i = static_cast<int>(k);
    return keystates_current[i] == (uint8)keystate::RELEASED;
}

bool input::get_key_prev_press(key k)
{
    int i = static_cast<int>(k);
    return keystates_prev[i] == (uint8)keystate::PRESSED;
}
bool input::get_key_prev_releas(key k)
{
    int i = static_cast<int>(k);
    return keystates_prev[i] == (uint8)keystate::RELEASED;
}


bool input::get_key_press(std::string k)
{
    int i = static_cast<int>(string_key_map[k]);
    return keystates_current[i] == (uint8)keystate::PRESSED;
}


bool input::get_key_releas(std::string k)
{
    int i = static_cast<int>(string_key_map[k]);
    return keystates_current[i] == (uint8)keystate::RELEASED;
}

void input::set_axis(std::string name,key p,key n)
{
    axis_map[name].add_keys(p,n);
}

int  input::get_axis(std::string name)
{
    return axis_map[name].get_value();
}

glm::vec2 input::get_mouse_posf()
{
    glm::vec2 screen = window::get_current().lock()->get_size();
    return (glm::vec2)mouse_pos_current/screen;
}

glm::vec2 input::get_mouse_deltaf()
{
    glm::vec2 screen = window::get_current().lock()->get_size();
    return (glm::vec2)(mouse_pos_current-mouse_pos_prev)/screen;
}