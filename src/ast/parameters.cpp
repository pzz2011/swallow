
#include "parameters.h"
#include "parameter.h"
#include "node-visitor.h"
USE_SWIFT_NS


Parameters::Parameters()
:Node(NodeType::Parameters)
{
    variadicParameters = false;
}
Parameters::~Parameters()
{
    SafeDeleteAll(parameters);
}

void Parameters::serialize(std::wostream& out)
{
}
void Parameters::accept(NodeVisitor* visitor)
{
    visitor->visitParameters(this);
}

void Parameters::setVariadicParameters(bool val)
{
    variadicParameters = val;
}
bool Parameters::isVariadicParameters()const
{
    return variadicParameters;
}

void Parameters::addParameter(Parameter* parameter)
{
    parameters.push_back(parameter);
}
int Parameters::numParameters()const
{
    return parameters.size();
}
Parameter* Parameters::getParameter(int i)
{
    return static_cast<Parameter*>(parameters[i]);
}
