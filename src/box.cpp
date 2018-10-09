#include "box.h"


#include "time.h"

#include "camera.h"

#include "renderer.h"



box::box()
{
    set_class_name("box");

    _shader = shader_library.create("simple.glsl");

    std::vector<uint8> d = 
    {
        0,0,0,255,255,255,255,255,255,0,0,0,
        0,0,0,255,255,255,255,255,255,0,0,0,
        0,0,0,255,255,255,255,255,255,0,0,0,
        0,0,0,255,255,255,255,255,255,0,0,0,
    };

    //_texture = texture_library.create("box",d,4,4);
    _texture = texture_library.create("tile128.bmp");


    std::vector<vertex> v;
    std::vector<uint16> i;

    v.reserve(8);
    i.reserve(36);

    v.push_back({glm::vec3(1,1,1),glm::vec3(1,0,0),glm::vec2(1,1)});//0
    v.push_back({glm::vec3(-1,1,1),glm::vec3(1,0,0),glm::vec2(0,1)});//1
   
    v.push_back({glm::vec3(1,-1,1),glm::vec3(1,0,0),glm::vec2(1,0)});//2
    v.push_back({glm::vec3(-1,-1,1),glm::vec3(1,0,0),glm::vec2(0,0)});//3
   
    v.push_back({glm::vec3(1,1,-1),glm::vec3(1,0,0),glm::vec2(1,1)});//4
    v.push_back({glm::vec3(-1,1,-1),glm::vec3(1,0,0),glm::vec2(0,1)});//5
   
    v.push_back({glm::vec3(1,-1,-1),glm::vec3(1,0,0),glm::vec2(1,0)});//6
    v.push_back({glm::vec3(-1,-1,-1),glm::vec3(1,0,0),glm::vec2(0,0)});//7


    i.push_back(0);
    i.push_back(1);
    i.push_back(3);

    i.push_back(2);
    i.push_back(0);
    i.push_back(3);

    i.push_back(4);
    i.push_back(0);
    i.push_back(2);

    i.push_back(6);
    i.push_back(4);
    i.push_back(2);

    i.push_back(5);
    i.push_back(4);
    i.push_back(6);

    i.push_back(7);
    i.push_back(5);
    i.push_back(6);

    i.push_back(1);
    i.push_back(5);
    i.push_back(7);

    i.push_back(3);
    i.push_back(1);
    i.push_back(7);

    i.push_back(4);
    i.push_back(5);
    i.push_back(1);

    i.push_back(0);
    i.push_back(4);
    i.push_back(1);

    i.push_back(6);
    i.push_back(2);
    i.push_back(3);

    i.push_back(7);
    i.push_back(6);
    i.push_back(3);

    _mesh = mesh_library.create("box",v,i);
}

box::~box()
{

}


void box::update()
{
    get_transform().position.y = sin(time::get_time() * 0.0001f) * 2.0f;
}


void box::draw()
{
    _shader.lock()->use();

    glm::mat4 pv = camera::get_current().lock()->get_perspective_view();
    _shader.lock()->set_matrix4("pv",pv);

    glm::mat4 mm = get_transform().get_model_matrix();
    _shader.lock()->set_matrix4("mm",mm);

    _shader.lock()->set_texture("texture0",_texture.lock()->get_id(),0);

    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    _mesh.lock()->draw();
}