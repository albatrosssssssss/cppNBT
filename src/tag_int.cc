/******************************************************************************
 *
 *  TAG_Int implementation (tag_int.cc)
 *  ---
 *  Created: 02.02.2011 15:42:45
 *  Author:  Lukas Niederbremer
 *
 ******************************************************************************/
#include "tag_int.h"

namespace nbt
{
    TagInt::TagInt(const std::string &name, const int32_t &value) : Tag(name)
    {
        _value = value;
    }

    
    TagInt::TagInt(const TagInt &t) : Tag(t.getName())
    {
        _value = t.getValue();
    }


    int32_t TagInt::getValue() const
    {
        return _value;
    }


    void TagInt::setValue(const int32_t &value)
    {
        _value = value;
    }


    uint8_t TagInt::getType() const
    {
        return TAG_INT;
    }


    ByteArray TagInt::toByteArray()
    {
        ByteArray ret = Tag::toByteArray();

        uint8_t *split = reinterpret_cast<uint8_t *>(&_value);

        for (int i = 3; i >= 0; --i)
            ret.push_back(split[i]);

        return ret;
    }


    std::string TagInt::toString()
    {
        std::stringstream ret;

        ret << "TAG_Int";

        if (!_name.empty())
            ret << "(\"" << _name << "\")";
        
        ret << ": " << _value;

        return ret.str();
    }
}
