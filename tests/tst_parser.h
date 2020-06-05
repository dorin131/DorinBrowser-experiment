#ifndef TST_PARSER_H
#define TST_PARSER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"
#include "../JS/parser.h"

using namespace testing;

TEST(Parser, EmptyCode)
{
    js::Tokenizer t = js::Tokenizer("3");
    auto p = js::Parser(t);
    js::Program program = p.parse_program();

    EXPECT_EQ(program.get_type(), "Program");
    auto expression_statement = program.get_elements().front();
    EXPECT_EQ(expression_statement->get_type(), "ExpressionStatement");
    auto expression = static_cast<js::ExpressionStatement*>(expression_statement)->get_expression();
    EXPECT_EQ(expression->get_type(), "Literal");
    EXPECT_EQ(static_cast<js::Literal*>(expression)->get_token().get_value(), "3");
}

#endif // TST_PARSER_H
