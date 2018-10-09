#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include <unordered_map>


#include "commun.h"


template<class T>
class library
{

    std::unordered_map<std::string,std::shared_ptr<T>> _library;

public:

    library(uint reserve)
    {
        _library.reserve(reserve);
    }

    inline std::weak_ptr<T> get(std::string path)
    {
        return _library[path];
    }

    template<class... _Types>
    inline std::weak_ptr<T> create(std::string path, _Types ... args)
    {
        std::weak_ptr<T> r = get(path);
        
        if(r.lock())
            return r;
        
        _library[path] = std::make_shared<T>(path, args...);

        r = _library[path];

        return r;
    }
};


#endif //!RESOURCE_H