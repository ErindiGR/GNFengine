#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "entity.h"

class camera :
    public entity
{
    static std::shared_ptr<camera> _current;


    float _fov;

    float _near;

    float _far;


    
public:

    static std::weak_ptr<camera> get_current();
    static void set_current(std::shared_ptr<camera> cam);

    camera();
    ~camera();

    inline float get_fov(){return _fov;}
    inline void set_fov(float f){_fov = f;}
    inline float get_near(){return _near;}
    inline void set_near(float n){_near = n;}
    inline float get_far(){return _far;}
    inline void set_far(float f){_far = f;}

    glm::mat4 get_perspective_view();


};

#endif //!CAMERA_H