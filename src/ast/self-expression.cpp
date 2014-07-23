#include "self-expression.h"
#include "node-visitor.h"
USE_SWIFT_NS




SelfExpression::SelfExpression(Expression* expr)
    :Expression(NodeType::Self), expression(expr)
{
}
SelfExpression::~SelfExpression()
{
    SafeDelete(expression);
}

void SelfExpression::setExpression(Expression* expr)
{
    this->expression = expr;
}
Expression* SelfExpression::getExpression()
{
    return expression;
}


void SelfExpression::serialize(std::wostream& out)
{
    getExpression()->serialize(out);
    out<<L".self";
}
void SelfExpression::accept(NodeVisitor* visitor)
{
    visitor->visitSelf(this);
}
