#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "entity.h"

class camera :
    public entity
{
    static std::weak_ptr<entity> _current;


    float _fov;

    float _near;

    float _far;


    
public:

    static std::weak_ptr<entity> get_current();
    static void set_current(std::weak_ptr<entity> cam);

    camera();
    ~camera();


    json serialize();
    void deserialize(json& serialized);


    inline float get_fov(){return _fov;}
    inline void set_fov(float f){_fov = f;}
    inline float get_near(){return _near;}
    inline void set_near(float n){_near = n;}
    inline float get_far(){return _far;}
    inline void set_far(float f){_far = f;}

    glm::mat4 get_perspective_view();


};

#endif //!CAMERA_H