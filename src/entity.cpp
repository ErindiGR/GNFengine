#include "entity.h"

#include "input.h"

#include "window.h"



entity::entity():
    _transform()
{
    
}
entity::~entity()
{

}

void entity::update()
{
    
}


void entity::draw()
{
    
}

void entity::set_transform(transform& t)
{
    _transform = t;
}
transform& entity::get_transform()
{
    return _transform;
}

void entity::set_class_name(std::string class_name)
{
    _class_name = class_name;
}
const std::string entity::get_class_name()
{
    return _class_name;
}


json entity::serialize() 
{
    json serialized;

    serialized["class_name"] = _class_name;
    serialized["transform"] = _transform.serialize();


    return serialized;
}

void entity::deserialize(json& serialized)
{
    _transform.deserialize(serialized["transform"]);
}