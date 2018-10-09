#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "transform.h"


class entity
{
    transform _transform;

    std::string _class_name;
public:

    entity();
    ~entity();

    virtual void update();
    virtual void draw();

    void set_transform(transform& t);
    transform& get_transform();

    void set_class_name(std::string class_name);
    const std::string get_class_name();

};


#endif //!ENTITY_H