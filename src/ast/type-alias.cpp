
#include "type-alias.h"
#include "type-node.h"
#include "node-visitor.h"
USE_SWIFT_NS


TypeAlias::TypeAlias()
    :Declaration(NodeType::TypeAlias), type(NULL)
{
}
TypeAlias::~TypeAlias()
{
    SafeDelete(type);
}
void TypeAlias::serialize(std::wostream& out)
{
    out<<L"typealias " << name << " = ";
    getType()->serialize(out);
}
void TypeAlias::accept(NodeVisitor* visitor)
{
    visitor->visitTypeAlias(this);
}

const std::wstring& TypeAlias::getName()const
{
    return name;
}
void TypeAlias::setName(const std::wstring& name)
{
    this->name = name;
}

void TypeAlias::setType(TypeNode* type)
{
    this->type = type;
}
TypeNode* TypeAlias::getType()
{
    return type;
}