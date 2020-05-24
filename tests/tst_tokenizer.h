#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"

using namespace testing;

TEST(Tokenizer, GettingTokens)
{
    std::string input = "\"hello\"; 'world'; var abc = 1 + 2 == function () { return 1 >= 4 };";
    js::Tokenizer* t = new js::Tokenizer(input);

    std::vector<js::Token*> expected_tokens = {
        new js::Token(js::Token::STRING, "hello"),
        new js::Token(js::Token::SEMICOLON, ";"),
        new js::Token(js::Token::STRING, "world"),
        new js::Token(js::Token::SEMICOLON, ";"),
        new js::Token(js::Token::VAR, "var"),
        new js::Token(js::Token::IDENTIFIER, "abc"),
        new js::Token(js::Token::ASSIGN, "="),
        new js::Token(js::Token::NUMBER, "1"),
        new js::Token(js::Token::ADD, "+"),
        new js::Token(js::Token::NUMBER, "2"),
        new js::Token(js::Token::EQ, "=="),
        new js::Token(js::Token::FUNCTION, "function"),
        new js::Token(js::Token::LPAREN, "("),
        new js::Token(js::Token::RPAREN, ")"),
        new js::Token(js::Token::LBRACE, "{"),
        new js::Token(js::Token::RETURN, "return"),
        new js::Token(js::Token::NUMBER, "1"),
        new js::Token(js::Token::GTE, ">="),
        new js::Token(js::Token::NUMBER, "4"),
        new js::Token(js::Token::RBRACE, "}"),
        new js::Token(js::Token::SEMICOLON, ";"),
        new js::Token(js::Token::EOS, 0),
        new js::Token(js::Token::EOS, 0),
        new js::Token(js::Token::EOS, 0),
    };

    for (js::Token* expected_token : expected_tokens) {
        js::Token* actual_token = t->next_token();
        EXPECT_EQ(*actual_token, *expected_token);
    }
}

#endif // TST_TEST_H
