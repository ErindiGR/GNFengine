#ifndef TEXTURE_H
#define TEXTURE_H


#include <unordered_map>
#include <iostream>

#include "commun.h"
#include "resource.h"


class texture
{

    uint _id;
    
    uint _width;
    uint _height;

    bool _generated;
    bool _placeholders[3];

    std::vector<uint8> _data;

public:

    texture(std::string path);
    texture(std::string path,std::vector<uint8> data,uint width,uint height);
    ~texture();
    
    void gen();
    void degen();
    void bind();


    inline const uint get_id(){return _id;}

};

extern library<texture> texture_library;


#endif //!TEXTURE_H