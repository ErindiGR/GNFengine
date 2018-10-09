#include "mesh.h"


#include "renderer.h"



library<mesh> mesh_library(1024u);


mesh::mesh(std::string path)
{

}

mesh::~mesh()
{
   degen();
}

mesh::mesh(std::string path,std::vector<vertex> v,std::vector<uint16> i)
{
    _vertex = v;
    _indices = i;

    _generated = false;

    gen();
}

void mesh::gen()
{
    if(_generated)
        return;

    uint indices_size  = _indices.size() * sizeof(_indices[0]);
    uint vertex_size   = _vertex.size() * sizeof(_vertex[0]);


    renderer::gen_vertexarray(1,&_vao);
    renderer::bind_vertexarray(_vao);

    renderer::gen_buffer(N,&_vbo[0]);

    renderer::bind_buffer(target::ELEMENT_ARRAY_BUFFER,_vbo[INDICES]);
    renderer::buffer_data(target::ELEMENT_ARRAY_BUFFER,indices_size,&_indices[0],usage::STATIC_DRAW);


    renderer::bind_buffer(target::ARRAY_BUFFER,_vbo[VERTEX]);
    renderer::buffer_data(target::ARRAY_BUFFER,vertex_size,&_vertex[0],usage::STATIC_DRAW);

    renderer::enable_vertex_attrib_array(0);
    renderer::vertex_attrib_pointer(0, 3,type::FLOAT, normalized::FALSE, sizeof(vertex), (void*)0);

    renderer::enable_vertex_attrib_array(1);
    renderer::vertex_attrib_pointer(1, 3, type::FLOAT, normalized::FALSE, sizeof(vertex), (void*)(sizeof(glm::vec3)));

    renderer::enable_vertex_attrib_array(2);
    renderer::vertex_attrib_pointer(2, 2, type::FLOAT, normalized::FALSE, sizeof(vertex), (void*)(2 * sizeof(glm::vec3)));


    renderer::bind_vertexarray(0);

    _generated = true;

}

void mesh::degen()
{
    if(!_generated)
        return;

     //renderer::delete_vertexarray(1,&_vao);
    //renderer::delete_buffer(N,&_vbo[0]);

    _generated = false;
}


void mesh::draw()
{
    renderer::bind_vertexarray(_vao);
    renderer::draw_elements(mode::TRIANGLES,_indices.size(),type::UNSIGNED_SHORT,0);
}



