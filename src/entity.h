#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "object.h"
#include "transform.h"


class entity :
    public object
{
    transform _transform;

    std::string _class_name;
public:

    entity();
    ~entity();

    virtual void update();
    virtual void draw();

    json serialize();
    void deserialize(json& serialized);

    void set_transform(transform& t);
    transform& get_transform();

    void set_class_name(std::string class_name);
    const std::string get_class_name();

};


#endif //!ENTITY_H