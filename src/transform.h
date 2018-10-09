#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/vec4.hpp>


class transform
{

public:

    glm::vec3 position;
    glm::vec3 size;
    glm::quat rotation;


    transform();

    glm::mat4 get_model_matrix();

    glm::vec3 get_forward();

    glm::vec3 get_up();


};


#endif //!TRANSFORM_H