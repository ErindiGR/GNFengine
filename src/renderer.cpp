#include "renderer.h"




#include "gui.h"


const uint param::REPEAT = GL_REPEAT;
const uint param::CLAMP = GL_CLAMP_TO_EDGE;
const uint param::CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE;

const uint param::NEAREST = GL_NEAREST;
const uint param::LINEAR = GL_LINEAR;
const uint param::NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST;
const uint param::LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST;
const uint param::NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR;
const uint param::LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR;

const uint pname::PACK_ALIGNMENT = GL_PACK_ALIGNMENT;
const uint pname::UNPACK_ALIGNMENT = GL_UNPACK_ALIGNMENT;

const uint pname::TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER;
const uint pname::TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER;
const uint pname::TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S;
const uint pname::TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T;


const uint mask::COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT;
const uint mask::DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT;
const uint mask::ACCUM_BUFFER_BIT = GL_ACCUM_BUFFER_BIT;
const uint mask::STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT;


const uint mode::POINTS = GL_POINTS;
const uint mode::LINES = GL_LINES;
const uint mode::LINE_STRIP = GL_LINE_STRIP;
const uint mode::LINE_LOOP = GL_LINE_LOOP;
const uint mode::TRIANGLES = GL_TRIANGLES;
const uint mode::TRIANGLE_STRIP = GL_TRIANGLE_STRIP;
const uint mode::TRIANGLE_FAN = GL_TRIANGLE_FAN;
const uint mode::QUADS = GL_QUADS;
const uint mode::QUAD_STRIP = GL_QUAD_STRIP;
const uint mode::POLYGON = GL_POLYGON;


const uint type::VERTEX_SHADER = GL_VERTEX_SHADER;
const uint type::FRAGMENT_SHADER = GL_FRAGMENT_SHADER;

const uint type::FIXED = GL_FIXED;
const uint type::FLOAT = GL_FLOAT;

const uint type::UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
const uint type::UNSIGNED_SHORT = GL_UNSIGNED_SHORT;
const uint type::UNSIGNED_INT = GL_UNSIGNED_INT;
const uint type::UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5;
const uint type::UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4;
const uint type::UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1;

const uint target::TEXTURE_2D = GL_TEXTURE_2D;
const uint target::TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP;

const uint target::TEXTURE_CUBE_MAP_POSITIVE_X = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
const uint target::TEXTURE_CUBE_MAP_POSITIVE_Y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
const uint target::TEXTURE_CUBE_MAP_POSITIVE_Z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;

const uint target::TEXTURE_CUBE_MAP_NEGATIVE_X = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
const uint target::TEXTURE_CUBE_MAP_NEGATIVE_Y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
const uint target::TEXTURE_CUBE_MAP_NEGATIVE_Z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;

const uint target::ARRAY_BUFFER = GL_ARRAY_BUFFER;
const uint target::ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER;

const uint internal_format::RED = GL_RED;
const uint internal_format::RGB = GL_RGB;
const uint internal_format::RGBA = GL_RGBA;

const uint format::RED = GL_RED;
const uint format::RGB = GL_RGB;
const uint format::RGBA = GL_RGBA;


const uint texturei::TEXTURE0  = GL_TEXTURE0 ;
const uint texturei::TEXTURE1  = GL_TEXTURE1 ;
const uint texturei::TEXTURE2  = GL_TEXTURE2 ;
const uint texturei::TEXTURE3  = GL_TEXTURE3 ;
const uint texturei::TEXTURE4  = GL_TEXTURE4 ;
const uint texturei::TEXTURE5  = GL_TEXTURE5 ;
const uint texturei::TEXTURE6  = GL_TEXTURE6 ;
const uint texturei::TEXTURE7  = GL_TEXTURE7 ;
const uint texturei::TEXTURE8  = GL_TEXTURE8 ;
const uint texturei::TEXTURE9  = GL_TEXTURE9 ;
const uint texturei::TEXTURE10 = GL_TEXTURE10;
const uint texturei::TEXTURE11 = GL_TEXTURE11;
const uint texturei::TEXTURE12 = GL_TEXTURE12;
const uint texturei::TEXTURE13 = GL_TEXTURE13;
const uint texturei::TEXTURE14 = GL_TEXTURE14;
const uint texturei::TEXTURE15 = GL_TEXTURE15;
const uint texturei::TEXTURE16 = GL_TEXTURE16;
const uint texturei::TEXTURE17 = GL_TEXTURE17;
const uint texturei::TEXTURE18 = GL_TEXTURE18;
const uint texturei::TEXTURE19 = GL_TEXTURE19;
const uint texturei::TEXTURE20 = GL_TEXTURE20;
const uint texturei::TEXTURE21 = GL_TEXTURE21;
const uint texturei::TEXTURE22 = GL_TEXTURE22;
const uint texturei::TEXTURE23 = GL_TEXTURE23;
const uint texturei::TEXTURE24 = GL_TEXTURE24;
const uint texturei::TEXTURE25 = GL_TEXTURE25;
const uint texturei::TEXTURE26 = GL_TEXTURE26;
const uint texturei::TEXTURE27 = GL_TEXTURE27;
const uint texturei::TEXTURE28 = GL_TEXTURE28;
const uint texturei::TEXTURE29 = GL_TEXTURE29;
const uint texturei::TEXTURE30 = GL_TEXTURE30;
const uint texturei::TEXTURE31 = GL_TEXTURE31;


const uint usage::STATIC_DRAW = GL_STATIC_DRAW;
const uint usage::DYNAMIC_DRAW = GL_DYNAMIC_DRAW;

const uint normalized::FALSE = GL_FALSE;
const uint normalized::TRUE = GL_TRUE; 




uint renderer::program_current = 0;
uint renderer::vertexarray_current = 0;

uint renderer::text_vao = 0;
uint renderer::text_vbo = 0;



void renderer::init()
{
    //glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        printf("renderer failed to initalize");
    }

    gen_vertexarray(1,&text_vao);
    gen_buffer(1,&text_vbo);
    bind_vertexarray(text_vao);
    bind_buffer(GL_ARRAY_BUFFER,text_vbo);
    buffer_data(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, usage::DYNAMIC_DRAW);
    enable_vertex_attrib_array(0);
    vertex_attrib_pointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    bind_buffer(GL_ARRAY_BUFFER,0);
    bind_vertexarray(0);

}


void renderer::clear_color(float r,float g,float b,float a)
{
    glClearColor(r,g,b,a);
}


void renderer::clear(uint mask)
{
    glClear(mask);
}

void renderer::begin(uint mode)
{
    glBegin(mode);
}

void renderer::end()
{
    glEnd();
}

void renderer::vertex2f(float x,float y)
{
    glVertex2f((x-0.5f)*2.0f,(1.0f-y-0.5f)*2.0f);    
}

void renderer::vertex3f(float x,float y,float z)
{
    glVertex3f(x,y,z);    
}

void renderer::texcoord2f(float s, float t)
{
    glTexCoord2f(s,t);
}

void renderer::normal3f(float x,float y,float z)
{
    glNormal3f(x,y,z);
}

void renderer::use_program(uint program)
{
    if(program_current == program)
        return;

    glUseProgram(program);

    program_current = program;
}

uint renderer::create_program()
{
    return glCreateProgram();
}
void renderer::detete_program(uint program)
{
    glDeleteProgram(program);
}
uint renderer::create_shader(uint type)
{
    return glCreateShader(type);
}
void renderer::attach_shader(uint program, uint shader)
{
    glAttachShader(program,shader);
}
void renderer::delete_shader(uint shader)
{
    glDeleteShader(shader);
}
void renderer::gen_textures(uint count,uint* textures)
{
    glGenTextures(count,textures);
}
void renderer::bind_texture(uint target,uint texture)
{
    glBindTexture(target,texture);
}
void renderer::gen_vertexarray(uint count,uint* array)
{
    glGenVertexArrays(count, array);
}
void renderer::bind_vertexarray(uint array)
{
    if(vertexarray_current == array)
        return;

    glBindVertexArray(array);

    vertexarray_current = array;
}

void renderer::pixel_storei(uint pname,uint param)
{
    glPixelStorei(pname,param);
}

void renderer::teximage2d(uint target,uint level,uint internal_format,uint width,uint height,
    uint border,uint format,uint type,const void* pixels)
{
    glTexImage2D(target,level,internal_format,width,height,border,format,type,pixels);
}

void renderer::texparameteri(uint target,uint pname,uint param)
{
    glTexParameteri(target,pname,param);
}

void renderer::draw_arrays(uint mode,int first,uint count)
{
    glDrawArrays(mode,first,count);
}
void renderer::bind_buffer(uint target,uint buffer)
{
    glBindBuffer(target,buffer);
}
void renderer::active_texture(uint texturei)
{
    glActiveTexture(texturei);
}
void renderer::buffer_subdata(uint target,uint offset,uint size,const void* data)
{
    glBufferSubData(target,offset,size,data);
}
void renderer::uniform3f(uint location,float x,float y,float z)
{
    glUniform3f(location,x,y,z);
}
uint renderer::get_uniform_location(uint shader,const char* name)
{
   return glGetUniformLocation(shader,name);
}
void renderer::shader_source(uint shader,uint count,const char** string,const int* length)
{
    glShaderSource(shader,count,string,length);
}
void renderer::compile_shader(uint shader)
{
    glCompileShader(shader);
}

void renderer::link_program(uint program)
{
    glLinkProgram(program);
}

void renderer::delete_program(uint program)
{
    glDeleteProgram(program);
}
void renderer::blend_func(uint sfactor, uint dfactor)
{
    glBlendFunc(sfactor,dfactor);
}
void renderer::enable(uint cap)
{
    glEnable(cap);
}
void renderer::disable(uint cap)
{
    glDisable(cap);
}
void renderer::gen_buffer(uint count,uint* buffers)
{
    glGenBuffers(count,buffers);
}
void renderer::buffer_data(uint target,uint size,const void* data,uint usage)
{
    glBufferData(target,size,data,usage);
}
void renderer::enable_vertex_attrib_array(uint index)
{
    glEnableVertexAttribArray(index);
}
void renderer::vertex_attrib_pointer(uint index,int size,uint type,uint normalized,int stride,const void* pointer)
{
    glVertexAttribPointer(index,size,type,normalized,stride,pointer);
}
void renderer::draw_elements(uint mode,uint count,uint type,const void* indices)
{
    glDrawElements(mode,count,type,indices);
}
void renderer::uniform_mat3fv(uint location,uint count,bool transpose,float* mat)
{
    glUniformMatrix3fv(location,count,transpose,mat);
}
void renderer::uniform_mat4fv(uint location,uint count,bool transpose,float* mat)
{   
    glUniformMatrix4fv(location,count,transpose,mat);
}
void renderer::uniform3fv(uint location,uint count,float* vec)
{
    glUniform3fv(location,count,vec);
}
void renderer::uniform2fv(uint location,uint count,float* vec)
{
    glUniform2fv(location,count,vec);
}
void renderer::uniformf(uint location,float f)
{
    glUniform1f(location,f);
}
void renderer::uniformi(uint location,int i)
{
    glUniform1i(location,i);
}
void renderer::gnerate_mipmap(uint target)
{
    glGenerateMipmap(target);
}
void renderer::delete_texture(uint count,uint* textures)
{
    glDeleteTextures(count,textures);
}
void renderer::delete_vertexarray(uint count,uint* array)
{
    glDeleteVertexArrays(count,array);
}
void renderer::delete_buffer(uint count,uint* buffer)
{
    glDeleteBuffers(count,buffer);
}




void renderer::simple_quad(float sx,float sy,float ex,float ey)
{
    begin(mode::TRIANGLES);

    vertex2f(sx,ey);
    vertex2f(ex,sy);
    vertex2f(sx,sy);
    
    vertex2f(sx,ey);
    vertex2f(ex,ey);
    vertex2f(ex,sy);
    
    end();
}


void renderer::simple_text(float x,float y,float width,float height,uint shader,std::string text)
{

    enable(GL_BLEND);

    blend_func(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  

    use_program(shader);

    uniform3f(get_uniform_location(shader, "textColor"), 0,0,0);
    active_texture(texturei::TEXTURE0);
    bind_vertexarray(text_vao);


    width = ((x+width)-0.5f)*2.0f;
    x = (x-0.5f)*2.0f;
    y = -(y-0.5f)*2.0f;
    
    float scale = (1.0f/48.0f) * height;

    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++)
    {

        character ch = gui::get_freetype_char()[*c];

        GLfloat xpos = x + ch.get_bearing().x * scale;
        GLfloat ypos = y - (ch.get_size().y - ch.get_bearing().y) * scale;

        GLfloat w = ch.get_size().x * scale;
        GLfloat h = ch.get_size().y * scale;
        
        
        GLfloat vertices[6][4] = {
            { xpos,     ypos + h,   0.0, 0.0 },            
            { xpos,     ypos,       0.0, 1.0 },
            { xpos + w, ypos,       1.0, 1.0 },

            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos + w, ypos + h,   1.0, 0.0 }           
        };


        x += ((ch.get_advance() >> 6)* scale);
        
        if(x>width)break;
        
        bind_texture(target::TEXTURE_2D, ch.get_texture());
        
        bind_buffer(GL_ARRAY_BUFFER, text_vbo);
        buffer_subdata(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        bind_buffer(GL_ARRAY_BUFFER, 0);
        
        draw_arrays(mode::TRIANGLES, 0, 6);

    }

    bind_vertexarray(0);

    bind_texture(target::TEXTURE_2D, 0);

    use_program(0);

    disable(GL_BLEND);
}

