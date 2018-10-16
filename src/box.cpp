#include "box.h"


#include "time.h"

#include "camera.h"

#include "renderer.h"



box::box()
{
    set_class_name("box");

    _shader = shader_library.create("simple.glsl");

    _texture = texture_library.create("tile128.bmp");

    _mesh = mesh_library.create("box.obj");
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

    glm::mat4 pv = std::dynamic_pointer_cast<camera>(camera::get_current().lock())->get_perspective_view();
    _shader.lock()->set_matrix4("pv",pv);

    glm::mat4 mm = get_transform().get_model_matrix();
    _shader.lock()->set_matrix4("mm",mm);

    _shader.lock()->set_texture("texture0",_texture.lock()->get_id(),0);

    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    _mesh.lock()->draw();
}