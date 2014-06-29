#ifndef ENUM_DEF_H
#define ENUM_DEF_H
#include "declaration.h"
#include <string>

SWIFT_NS_BEGIN

class EnumDef : public Declaration
{
public:
    EnumDef();
public:
    void setName(const std::wstring& name);
    const std::wstring& getName()const;
public:
    virtual void serialize(std::wostream& out);
private:
    std::wstring name;
};

SWIFT_NS_END

#endif//ENUM_DEF_H