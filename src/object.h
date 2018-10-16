#ifndef OBJECT_H
#define OBJECT_H

#include <json/json.hpp>

using json = nlohmann::json;

class object
{
    
public:

    virtual json serialize()=0;
    virtual void deserialize(json& serialized)=0;

};


#endif //!OBJECT_H