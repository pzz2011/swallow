
#include "value-binding.h"
#include "node-visitor.h"
USE_SWIFT_NS


ValueBinding::ValueBinding(NodeType::T nodeType)
    :Pattern(nodeType), binding(NULL)
{
}
ValueBinding::~ValueBinding()
{
    SafeDelete(binding);
}

void ValueBinding::setBinding(Pattern* st)
{
    this->binding = st;
}
Pattern* ValueBinding::getBinding()
{
    return binding;
}

LetBinding::LetBinding()
    :ValueBinding(NodeType::LetBinding)
{
}
void LetBinding::serialize(std::wostream& out)
{
    out<<L"let ";
    getBinding()->serialize(out);
}
void LetBinding::accept(NodeVisitor* visitor)
{
    visitor->visitLetBinding(this);
}

VarBinding::VarBinding()
    :ValueBinding(NodeType::VarBinding)
{
}
void VarBinding::serialize(std::wostream& out)
{
    out<<L"var ";
    getBinding()->serialize(out);
}
void VarBinding::accept(NodeVisitor* visitor)
{
    visitor->visitVarBinding(this);
}
