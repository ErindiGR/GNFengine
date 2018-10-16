#include "camera.h"

#include "window.h"

std::weak_ptr<entity> camera::_current;

std::weak_ptr<entity> camera::get_current()
{
    return _current;
}

void camera::set_current(std::weak_ptr<entity> cam)
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

json camera::serialize() 
{
    json serialized;

    serialized["class_name"] = get_class_name();
    serialized["transform"] = get_transform().serialize();
    serialized["fov"] = _fov;
    serialized["near"] = _near;
    serialized["far"] = _far;

    return serialized;
}

void camera::deserialize(json& serialized)
{
    get_transform().deserialize(serialized["transform"]);
    
    _fov  = serialized["fov"];
    _near = serialized["near"];
    _far  = serialized["far"];
}