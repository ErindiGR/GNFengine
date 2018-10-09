#include "world.h"

#include "entity.h"


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