#ifndef TST_PARSER_H
#define TST_PARSER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"
#include "../JS/parser.h"

using namespace testing;

TEST(Parser, Literal)
{
    js::Tokenizer t = js::Tokenizer("3");
    auto p = js::Parser(t);
    std::shared_ptr<js::Program> program = p.parse_program();
    program->dump(0);

    EXPECT_EQ(program->get_type(), "Program");
    auto expression_statement = program->get_elements().front();
    EXPECT_EQ(expression_statement->get_type(), "ExpressionStatement");
    auto expression = std::static_pointer_cast<js::ExpressionStatement>(expression_statement)->get_expression();
    EXPECT_EQ(expression->get_type(), "Literal");
    EXPECT_EQ(std::static_pointer_cast<js::Literal>(expression)->get_token().get_value(), "3");
}

TEST(Parser, BinaryExpresion)
{
    js::Tokenizer t = js::Tokenizer("1+2");
    auto p = js::Parser(t);
    std::shared_ptr<js::Program> program = p.parse_program();
    program->dump(0);

    EXPECT_EQ(program->get_type(), "Program");
    auto expression_statement = program->get_elements().front();
    EXPECT_EQ(expression_statement->get_type(), "ExpressionStatement");
    auto expression = std::static_pointer_cast<js::ExpressionStatement>(expression_statement)->get_expression();
    EXPECT_EQ(expression->get_type(), "BinaryExpression");
    auto binary_expression = std::static_pointer_cast<js::BinaryExpression>(expression);
    EXPECT_EQ(std::static_pointer_cast<js::Literal>(binary_expression->get_left())->get_token().get_value(), "1");
    EXPECT_EQ(std::static_pointer_cast<js::Literal>(binary_expression->get_right())->get_token().get_value(), "2");
    EXPECT_EQ(binary_expression->get_op(), "+");
}

#endif // TST_PARSER_H
