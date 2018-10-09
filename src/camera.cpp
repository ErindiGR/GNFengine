#include "camera.h"

#include "window.h"

std::shared_ptr<camera> camera::_current;

std::weak_ptr<camera> camera::get_current()
{
    return _current;
}

void camera::set_current(std::shared_ptr<camera> cam)
{
    _current = cam;
}

camera::camera():
    _fov(glm::radians(90.0f)),
    _near(0.1f),
    _far(1000.0f)
{
    set_class_name("camera");
}
camera::~camera()
{
    
}


glm::mat4 camera::get_perspective_view()
{
    float aspect = window::get_current().lock()->get_aspect();
    glm::mat4 p = glm::perspective(_fov,aspect,_near,_far);
    glm::mat4 v = glm::lookAt(get_transform().position,get_transform().position + get_transform().get_forward(),get_transform().get_up());

    return p*v;
}