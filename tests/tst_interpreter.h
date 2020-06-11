#ifndef TST_INTERPRETER_H
#define TST_INTERPRETER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"
#include "../JS/parser.h"
#include "../JS/value.h"
#include "../JS/interpreter.h"

using namespace testing;

TEST(Interpreter, InterpretExpression)
{
    js::Tokenizer t = js::Tokenizer("1+2");
    auto p = js::Parser(t);
    js::Program* program = p.parse_program();
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "3");
}

TEST(Interpreter, InterpretExpression2)
{
    js::Tokenizer t = js::Tokenizer("2*3;");
    auto p = js::Parser(t);
    js::Program* program = p.parse_program();
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "6");
}

TEST(Interpreter, InterpretExpression3)
{
    js::Tokenizer t = js::Tokenizer("2 * (3 + 1);");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "8");
}

TEST(Interpreter, InterpretExpression4)
{
    js::Tokenizer t = js::Tokenizer("\"hello\" + \"world\"");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "helloworld");
}

TEST(Interpreter, InterpretExpression5)
{
    js::Tokenizer t = js::Tokenizer("\"hello\" + 100");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "hello100");
}

TEST(Interpreter, InterpretExpression6)
{
    js::Tokenizer t = js::Tokenizer("2 * 2; 3 * 3");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_value(), "9");
}

TEST(Interpreter, InterpretExpression7)
{
    js::Tokenizer t = js::Tokenizer("var x = 1");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_type(), js::Value::UNDEFINED);
}

TEST(Interpreter, InterpretExpression8)
{
    js::Tokenizer t = js::Tokenizer("var x = 1; x");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_type(), js::Value::NUMBER);
    EXPECT_EQ(result.get_value(), "1");
}

TEST(Interpreter, InterpretExpression9)
{
    js::Tokenizer t = js::Tokenizer("var x = 10 * (3+3); x + 1;");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_type(), js::Value::NUMBER);
    EXPECT_EQ(result.get_value(), "61");
}

TEST(Interpreter, InterpretExpression10)
{
    js::Tokenizer t = js::Tokenizer("var x = 10 * (3+3); var y = x + 1; y-1;");
    auto p = js::Parser(t);
    js::Program* program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        std::cerr << "Parsing error: " + e.message << std::endl;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    program->dump(0);

    EXPECT_EQ(result.get_type(), js::Value::NUMBER);
    EXPECT_EQ(result.get_value(), "60");
}

#endif // TST_INTERPRETER_H
