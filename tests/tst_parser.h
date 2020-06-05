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
    EXPECT_EQ(program.get_elements().front()->get_type(), "ExpressionStatement");
}

#endif // TST_PARSER_H
