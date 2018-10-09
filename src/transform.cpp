#include "transform.h"



#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

transform::transform():
    position(0),
    size(1),
    rotation()
{

}

glm::mat4 transform::get_model_matrix()
{
    glm::mat4 t = glm::translate(position);
    glm::mat4 s = glm::scale(size);
    glm::mat4 r = glm::toMat4(rotation);

    return t * r * s;
}

glm::vec3 transform::get_forward()
{
    glm::vec4 f = rotation * glm::vec4(0,0,1,0.0);
    return glm::normalize(glm::vec3(f.x,f.y,f.z));
}

glm::vec3 transform::get_up()
{
    glm::vec4 f = rotation * glm::vec4(0,1,0,0.0);
    return glm::normalize(glm::vec3(f.x,f.y,f.z));
}