#include "shader.h"

#include <fstream>
#include <streambuf>
#include <sstream>
#include <assert.h>

#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"


library<shader> shader_library(512u);


shader::shader(std::string path)
{
    std::ifstream t(path);

    assert(t.is_open());

    std::string buffer((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());



    std::string vert = buffer.substr(0,buffer.find("#split#"));
    const char* v = vert.c_str();

    std::string frag = buffer.substr(buffer.find("#split#")+sizeof("#split#"));
    const char* f =  frag.c_str();

    //std::cout << v << f <<std::endl;


    uint vertex_shader = renderer::create_shader(type::VERTEX_SHADER);
    uint frag_shader = renderer::create_shader(type::FRAGMENT_SHADER);

    int success;
    char infoLog[512];

    renderer::shader_source(vertex_shader,1,&v,0); 
    renderer::compile_shader(vertex_shader);

    glGetShaderiv(vertex_shader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "failed to compile vertex shader: \n" << infoLog << std::endl;
    }   

    
    renderer::shader_source(frag_shader,1,&f,0);
    renderer::compile_shader(frag_shader);

    glGetShaderiv(frag_shader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(frag_shader, 512, NULL, infoLog);
        std::cout << "failed to compile fragment shader: \n" << infoLog << std::endl;
    }


    _id = renderer::create_program();

    renderer::attach_shader(_id,vertex_shader);
    renderer::attach_shader(_id,frag_shader);

    renderer::link_program(_id);

    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(_id, 512, NULL, infoLog);
        std::cout << "failed to link program: \n" << infoLog << std::endl;
    }

    renderer::delete_shader(vertex_shader);
    renderer::delete_shader(frag_shader);

}

shader::~shader()
{
    renderer::delete_program(_id);
}



void shader::use()
{
    renderer::use_program(_id);
}

void shader::set_float(const std::string& name,const float f)
{
    renderer::uniformf(renderer::get_uniform_location(_id, name.c_str()),f);
}

void shader::set_int(const std::string& name,const int i)
{
    renderer::uniformi(renderer::get_uniform_location(_id, name.c_str()),i);
}

void shader::set_texture(const std::string& name,const uint texture,uint i)
{
    renderer::active_texture(texturei::TEXTURE0+i);
    renderer::uniformi(renderer::get_uniform_location(_id, name.c_str()),i);
    renderer::bind_texture(target::TEXTURE_2D,texture);
}

void shader::set_matrix4(const std::string& name,const glm::mat4& mat)
{
    renderer::uniform_mat4fv(renderer::get_uniform_location(_id, name.c_str()),1,false,(float*)glm::value_ptr(mat));
}

void shader::set_matrix3(const std::string& name,const glm::mat3& mat)
{
    renderer::uniform_mat3fv(renderer::get_uniform_location(_id, name.c_str()),1,false,(float*)glm::value_ptr(mat));
}

void shader::set_vec3(const std::string& name,const glm::vec3& vec)
{
    renderer::uniform3fv(renderer::get_uniform_location(_id, name.c_str()),1,(float*)glm::value_ptr(vec));
}

void shader::set_vec2(const std::string& name,const glm::vec2& vec)
{
    renderer::uniform2fv(renderer::get_uniform_location(_id, name.c_str()),1,(float*)glm::value_ptr(vec));
}