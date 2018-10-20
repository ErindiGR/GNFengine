#include "world.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


#include "entity.h"
#include "camera.h"
#include "box.h"


std::shared_ptr<world> world::_current(0);

world::world():
    _entities()
{
    _entities.reserve(256);
}

world::~world()
{

}


std::weak_ptr<world> world::get_current()
{
    return _current;
}

void world::set_current(std::shared_ptr<world> wrld)
{
    _current = wrld;
}

std::vector<std::weak_ptr<entity>> world::get_entities()
{
    std::vector<std::weak_ptr<entity>> r;        
    r.reserve(_entities.size());

    for(int i = 0;i<_entities.size();i++)
    {
        r.push_back(_entities[i]);
    }

    return r;
}
    

std::weak_ptr<entity> world::get_entity(uint i)
{
    return _entities[i];
}

void world::spawn_entity(std::shared_ptr<entity> ent)
{
    _entities.push_back(ent);
}

void world::destroy_entity(std::weak_ptr<entity> ent)
{

}

void world::destroy_entity(uint i)
{
    _entities.erase(_entities.begin() + i);
}

json world::serialize() 
{
    json serialized;

    for(uint i=0;i<_entities.size();i++)
        serialized["entities"][i] = _entities[i]->serialize();


    return serialized;
}


std::shared_ptr<entity> create_entity_form_str(std::string class_name)
{

#define STRTOSRD(x) else if(class_name == #x )\
{\
    return std::make_shared<x>();\
}

    if(class_name == "entity")
    {
        return std::make_shared<entity>();
    }
    STRTOSRD(camera)
    STRTOSRD(box)
    else
    {
        return 0;
    }


#undef STRTOSRD

}



void world::deserialize(json& serialized)
{
    _entities.clear();

    for(uint i=0;i<serialized["entities"].size();i++)
    {
        std::shared_ptr<entity> e = create_entity_form_str(serialized["entities"][i]["class_name"]);
        
        e->deserialize(serialized["entities"][i]);

        _entities.push_back(e);
    }
}


void world::save(std::string path)
{
    std::ofstream file(path);

    file << std::setw(4) << serialize() << std::endl;
}

void world::load(std::string path)
{
    std::ifstream file(path);
    
    json j;
    file >> j;

    deserialize(j);
}