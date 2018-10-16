#ifndef WORLD_H
#define WORLD_H


#include <iostream>
#include <vector>

#include "commun.h"
#include "object.h"


class world :
    public object
{
    std::vector<std::shared_ptr<class entity>> _entities;

    static std::shared_ptr<world> _current;

public:

    world();
    ~world();
    

    void load(std::string path);
    void save(std::string path);
    
    json serialize();
    void deserialize(json& serialized);


    static std::weak_ptr<world> get_current();
    static void set_current(std::shared_ptr<world> wrld);
    
    std::vector<std::weak_ptr<class entity>> get_entities();

    std::weak_ptr<class entity> get_entity(uint i);
    void spawn_entity(std::shared_ptr<class entity> ent);
    void destroy_entity(std::weak_ptr<class entity> ent);
    void destroy_entity(uint i);
};


#endif //!WORLD_H
