#ifndef WORLD_H
#define WORLD_H


#include <iostream>
#include <vector>

#include "commun.h"


class world
{
    std::vector<std::shared_ptr<class entity>> _entities;

    static std::shared_ptr<world> _current;

public:

    world();
    ~world();

    static std::weak_ptr<world> get_current();
    static void set_current(std::shared_ptr<world> wrld);
    
    std::vector<std::weak_ptr<class entity>> get_entities();

    std::weak_ptr<class entity> get_entity(uint i);
    void spawn_entity(std::shared_ptr<class entity> ent);
    void destroy_entity(std::weak_ptr<class entity> ent);
    void destroy_entity(uint i);
};


#endif //!WORLD_H
