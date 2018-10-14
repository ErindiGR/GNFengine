#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>

#include <glew/glew.h>

#include "commun.h"


class pname
{
public:

    static const uint PACK_ALIGNMENT;
    static const uint UNPACK_ALIGNMENT;
    
    static const uint TEXTURE_MIN_FILTER;
    static const uint TEXTURE_MAG_FILTER;
    static const uint TEXTURE_WRAP_S;
    static const uint TEXTURE_WRAP_T;
};

class param
{
public:

    static const uint REPEAT;
    static const uint CLAMP;
    static const uint CLAMP_TO_EDGE;

    static const uint NEAREST;
    static const uint LINEAR;
    static const uint NEAREST_MIPMAP_NEAREST;
    static const uint LINEAR_MIPMAP_NEAREST;
    static const uint NEAREST_MIPMAP_LINEAR;
    static const uint LINEAR_MIPMAP_LINEAR;
};

class mask
{
public:

    static const uint COLOR_BUFFER_BIT;
    static const uint DEPTH_BUFFER_BIT;
    static const uint ACCUM_BUFFER_BIT;
    static const uint STENCIL_BUFFER_BIT;
    
};


class mode
{
public:

    static const uint POINTS;
    static const uint LINES;
    static const uint LINE_STRIP;
    static const uint LINE_LOOP;
    static const uint TRIANGLES;
    static const uint TRIANGLE_STRIP;
    static const uint TRIANGLE_FAN;
    static const uint QUADS;
    static const uint QUAD_STRIP;
    static const uint POLYGON;

};

class type
{
public:

    static const uint VERTEX_SHADER;
    static const uint FRAGMENT_SHADER;

    static const uint FIXED;
    static const uint FLOAT;
    static const uint UNSIGNED_BYTE;
    static const uint UNSIGNED_SHORT;
    static const uint UNSIGNED_INT;
    static const uint UNSIGNED_SHORT_5_6_5;
    static const uint UNSIGNED_SHORT_4_4_4_4;
    static const uint UNSIGNED_SHORT_5_5_5_1;
};

class target
{
public:

    static const uint TEXTURE_2D;
    static const uint TEXTURE_CUBE_MAP;

    static const uint TEXTURE_CUBE_MAP_POSITIVE_X;
    static const uint TEXTURE_CUBE_MAP_POSITIVE_Y;
    static const uint TEXTURE_CUBE_MAP_POSITIVE_Z;

    static const uint TEXTURE_CUBE_MAP_NEGATIVE_X;
    static const uint TEXTURE_CUBE_MAP_NEGATIVE_Y;
    static const uint TEXTURE_CUBE_MAP_NEGATIVE_Z;

    static const uint ARRAY_BUFFER;
    static const uint ELEMENT_ARRAY_BUFFER;
};

class internal_format
{
public:

    static const uint RED;
    static const uint RGB;
    static const uint RGBA;
};

class format
{
public:

    static const uint RED;
    static const uint RGB;
    static const uint RGBA;
};

class texturei
{
public:
    static const uint TEXTURE0;
    static const uint TEXTURE1;
    static const uint TEXTURE2;
    static const uint TEXTURE3;
    static const uint TEXTURE4;
    static const uint TEXTURE5;
    static const uint TEXTURE6;
    static const uint TEXTURE7;
    static const uint TEXTURE8;
    static const uint TEXTURE9;
    static const uint TEXTURE10;
    static const uint TEXTURE11;
    static const uint TEXTURE12;
    static const uint TEXTURE13;
    static const uint TEXTURE14;
    static const uint TEXTURE15;
    static const uint TEXTURE16;
    static const uint TEXTURE17;
    static const uint TEXTURE18;
    static const uint TEXTURE19;
    static const uint TEXTURE20;
    static const uint TEXTURE21;
    static const uint TEXTURE22;
    static const uint TEXTURE23;
    static const uint TEXTURE24;
    static const uint TEXTURE25;
    static const uint TEXTURE26;
    static const uint TEXTURE27;
    static const uint TEXTURE28;
    static const uint TEXTURE29;
    static const uint TEXTURE30;
    static const uint TEXTURE31;
};

class usage
{

public:

    static const uint STATIC_DRAW;
    static const uint DYNAMIC_DRAW;

};


class normalized
{

public:

    static const uint FALSE;
    static const uint TRUE; 

};

class renderer
{

    static uint program_current;
    static uint vertexarray_current;
    
    static uint text_vao;
    static uint text_vbo;

public:

    static void init();

    static void clear_color(float r,float g,float b,float a);
    static void clear(uint mask);
    static void begin(uint mode);
    static void end();

    //this is in texture coords
    static void vertex2f(float x,float y);
    static void vertex3f(float x,float y,float z);
    static void texcoord2f(float s, float t);
    static void normal3f(float x,float y,float z);
    static void use_program(uint program);
    static uint create_program();
    static void detete_program(uint program);
    static uint create_shader(uint type);
    static void attach_shader(uint program, uint shader);
    static void delete_shader(uint shader);
    static void gen_textures(uint count,uint* textures);
    static void bind_texture(uint target,uint texture);
    static void teximage2d(uint target,uint level,uint internal_format,uint width,uint height,uint border,uint format,uint type,const void* pixels);
    static void texparameteri(uint target,uint pname,uint param);
    static void gen_vertexarray(uint count,uint* array);
    static void bind_vertexarray(uint array);
    static void pixel_storei(uint pname,uint param);
    static void draw_arrays(uint mode,int first,uint count);
    static void bind_buffer(uint target,uint buffer);
    static void active_texture(uint texturei);
    static void buffer_subdata(uint target,uint offset,uint size,const void* data);
    static void uniform3f(uint location,float x,float y,float z);
    static uint get_uniform_location(uint program,const char* name);
    static void shader_source(uint shader,uint count,const char** string,const int* length);
    static void compile_shader(uint shader);
    static void link_program(uint program);
    static void delete_program(uint program);
    static void blend_func(uint sfactor, uint dfactor);
    static void enable(uint cap);
    static void disable(uint cap);
    static void gen_buffer(uint count,uint* buffers);
    static void buffer_data(uint target,uint size,const void* data,uint usage);
    static void enable_vertex_attrib_array(uint index);
    static void vertex_attrib_pointer(uint index,int size,uint type,uint normalized,int stride,const void* pointer);
    static void draw_elements(uint mode,uint count,uint type,const void* indices);
    static void uniform_mat3fv(uint location,uint count,bool transpose,float* mat);
    static void uniform_mat4fv(uint location,uint count,bool transpose,float* mat);
    static void uniform3fv(uint location,uint count,float* vec);
    static void uniform2fv(uint location,uint count,float* vec);
    static void uniformf(uint location,float f);
    static void uniformi(uint location,int i);
    static void gnerate_mipmap(uint target);
    static void delete_texture(uint count,uint* textures);
    static void delete_vertexarray(uint count,uint* array);
    static void delete_buffer(uint count,uint* buffer);

    static void simple_quad(float sx,float sy,float ex,float ey);
    static void simple_text(float x,float y,float width,float height,uint shader,std::string text);
};

#endif //!RENDERER_H