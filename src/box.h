#ifndef BOX_H
#define BOX_H


#include <iostream>

#include "entity.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"


class box :
    public entity
{

    std::weak_ptr<shader> _shader;
    std::weak_ptr<mesh> _mesh;
    std::weak_ptr<texture> _texture;

public:

    box();
    ~box();

    void update();
    void draw();

    json serialize();
    void deserialize(json& serialized);

};


#endif //!BOX_H