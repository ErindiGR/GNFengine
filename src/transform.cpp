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

#define VEC3TO(vec) {vec.x,vec.y,vec.z}
#define QATO(q) {q.x,q.y,q.z,q.w}
#define TOVEC3(vec,s) {vec.x = s[0];vec.y = s[1];vec.z = s[2];}
#define TOQA(q,s) {q.x = s[0];q.y = s[1];q.z = s[2];q.w = s[3];}

json transform::serialize()
{
    json serialized;

    serialized["position"] = VEC3TO(position);
    serialized["size"] = VEC3TO(size);
    serialized["rotation"] = QATO(rotation);


    return serialized;
}

void transform::deserialize(json& serialized)
{
    TOVEC3(position,serialized["position"]);
    TOVEC3(size,serialized["size"]);
    TOQA(rotation,serialized["rotation"]);
    
}

#undef TOVEC3
#undef TOQA
#undef VEC3TO
#undef QATO