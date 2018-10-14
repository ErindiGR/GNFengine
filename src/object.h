#ifndef OBJECT_H
#define OBJECT_H

#include <json/json.hpp>

using json = nlohmann::json;

class object
{
    
public:

    virtual json serialize()
    {
        json serialized;

        serialized["class_name"] = "object";

        return serialized;
    }
    virtual void deserialize(json& serialized)
    {

    }

};


#endif //!OBJECT_H