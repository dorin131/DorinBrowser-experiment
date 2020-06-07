#ifndef TST_INTERPRETER_H
#define TST_INTERPRETER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"
#include "../JS/parser.h"
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

#endif // TST_INTERPRETER_H
