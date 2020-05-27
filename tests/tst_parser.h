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
    auto program = p.parse_program();
    auto result = program.to_string();

    EXPECT_EQ(result, "Program\n\tNode\n");
}

#endif // TST_PARSER_H
