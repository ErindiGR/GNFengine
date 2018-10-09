#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

#include "commun.h"
#include "resource.h"


class shader
{
    uint _id;

public:

    shader(std::string path);
    ~shader();


    void use();
    
    void set_float(const std::string& name,const float f);
    void set_int(const std::string& name,const int i);
    void set_texture(const std::string& name,const uint texture,uint i);
    void set_matrix4(const std::string& name,const glm::mat4& mat);
    void set_matrix3(const std::string& name,const glm::mat3& mat);
    void set_vec3(const std::string& name,const glm::vec3& vec);
    void set_vec2(const std::string& name,const glm::vec2& vec);    


    inline const uint get_id(){return _id;}

};

extern library<shader> shader_library;


#endif //!SHADER_H