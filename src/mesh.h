#ifndef MESH_H
#define MESH_H

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <array>

#include <glm/glm.hpp>


#include "commun.h"
#include "resource.h"


struct vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texcoord;
};

class mesh
{    

    uint _vao;

    enum
    {
        INDICES,
        VERTEX,
        N
    };

    std::array<uint,N> _vbo;

    std::vector<vertex> _vertex;
    std::vector<uint16> _indices;

    bool _generated;
    bool _placeholder[3];

public:

    mesh(std::string path);
    mesh(std::string path, std::vector<vertex> v,std::vector<uint16> i);
    ~mesh();

    void gen();
    void degen();
    void draw();


};

extern library<mesh> mesh_library;

#endif MESH_H