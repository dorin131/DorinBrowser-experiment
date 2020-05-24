#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"

using namespace testing;

TEST(Tests, Test)
{
    js::Tokenizer* t = new js::Tokenizer(".");

    EXPECT_EQ(t->next_token(), *new js::Token(js::Token::PERIOD, "."));
}

#endif // TST_TEST_H
