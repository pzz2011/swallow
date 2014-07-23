#ifndef TEST_TYPE_INFERENCE_H
#define TEST_TYPE_INFERENCE_H

#include "tests/semantics/semantic-test.h"
#include "semantics/type.h"


using namespace Swift;

class TestTypeInference : public SemanticTestCase
{
    CPPUNIT_TEST_SUITE(TestTypeInference);
    CPPUNIT_TEST(testIntLiteral);
    CPPUNIT_TEST(testStringLiteral);
    CPPUNIT_TEST(testTuple);
    CPPUNIT_TEST_SUITE_END();
public:
    void testIntLiteral()
    {
        SEMANTIC_ANALYZE(L"let a = 34");
        Identifier* a = NULL;

        CPPUNIT_ASSERT(a = dynamic_cast<Identifier*>(scope->lookup(L"a")));
        TypePtr type = a->getType();
        CPPUNIT_ASSERT(type);
        TypePtr Int = symbolRegistry.getCurrentScope()->lookupType(L"Int");
        CPPUNIT_ASSERT(type == Int);

    }
    void testStringLiteral()
    {
        SEMANTIC_ANALYZE(L"let a = \"345\"");
        Identifier* a = NULL;

        CPPUNIT_ASSERT(a = dynamic_cast<Identifier*>(scope->lookup(L"a")));
        TypePtr type = a->getType();
        CPPUNIT_ASSERT(type);
        TypePtr String = symbolRegistry.getCurrentScope()->lookupType(L"String");
        CPPUNIT_ASSERT(type == String);
    }
    void testTuple()
    {
        /*
        SEMANTIC_ANALYZE(L"let (a, b) = (1, 0.3)");
        Identifier* a = NULL;
        CPPUNIT_ASSERT(a = dynamic_cast<Identifier*>(scope->lookup(L"a")));
        TypePtr type = a->getType();
        CPPUNIT_ASSERT(type);
        TypePtr String = symbolRegistry.getCurrentScope()->lookupType(L"Int");
        CPPUNIT_ASSERT(type == String);
        */
    }


};
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestTypeInference, "alltest");



#endif//TEST_TYPE_INFERENCE_H
