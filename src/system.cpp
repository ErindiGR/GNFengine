#include "system.h"

#include <algorithm>

#include "renderer.h"


#include "shader.h"
#include "window.h"
#include "input.h"
#include "gui.h"

#include "camera.h"
#include "world.h"
#include "entity.h"
#include "mesh.h"
#include "box.h"


SDL_Event system::_event;

void system::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
        std::cout << SDL_GetError() << std::endl;


    window::set_current(std::make_shared<window>("test",512u,512u));

    renderer::init();

    gui::init();


    world::set_current(std::make_shared<world>());

    std::shared_ptr<camera> cam = std::make_shared<camera>();
    world::get_current().lock()->spawn_entity(cam);

    camera::set_current(cam);

    camera::get_current().lock()->get_transform().position = glm::vec3(3,0,-4);

    
    for(int j=0;j<128;j++)
    for(int i=0;i<4;i++)
    {
        std::shared_ptr<box> b1 = std::make_shared<box>();
        b1->get_transform().position.z = 4*j;
        b1->get_transform().position.x = 2*i;
        world::get_current().lock()->spawn_entity(b1);
    }
}

void system::term()
{
    SDL_Quit();
}


void system::event()
{
    SDL_PollEvent(&_event);    
}

SDL_Event& system::get_event()
{
    return _event;    
}


void system::update()
{
    std::vector<std::weak_ptr<entity>> entities = world::get_current().lock()->get_entities();
    
    for(int i=0;i<entities.size();i++)
        entities[i].lock()->update();
    
}

bool entity_sort(std::weak_ptr<entity> a,std::weak_ptr<entity> b)
{
    float ad = glm::distance(camera::get_current().lock()->get_transform().position,
    a.lock()->get_transform().position);
    
    float bd = glm::distance(camera::get_current().lock()->get_transform().position,
    b.lock()->get_transform().position);

    return (ad<bd);
}



void system::draw()
{

    renderer::clear_color(0.2,0.2,0.6,1);
    renderer::clear(mask::COLOR_BUFFER_BIT | mask::DEPTH_BUFFER_BIT);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);


    if(camera::get_current().lock())
    {
        std::vector<std::weak_ptr<entity>> sorted = world::get_current().lock()->get_entities();

        std::sort(sorted.begin(),sorted.end(),entity_sort);

        for(int i=0;i<sorted.size();i++)
            sorted[i].lock()->draw();
    }

}

