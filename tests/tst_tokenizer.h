#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"

using namespace testing;

TEST(Tokenizer, GettingTokens)
{
    std::string input = "\"hello\"; 'world'; var abc = 1 + 2 == function () { return 1 >= 4 };";
    js::Tokenizer t = js::Tokenizer(input);

    std::vector<js::Token> expected_tokens = {
        js::Token(js::Token::STRING, "hello"),
        js::Token(js::Token::SEMICOLON, ";"),
        js::Token(js::Token::STRING, "world"),
        js::Token(js::Token::SEMICOLON, ";"),
        js::Token(js::Token::VAR, "var"),
        js::Token(js::Token::IDENTIFIER, "abc"),
        js::Token(js::Token::ASSIGN, "="),
        js::Token(js::Token::NUMBER, "1"),
        js::Token(js::Token::ADD, "+"),
        js::Token(js::Token::NUMBER, "2"),
        js::Token(js::Token::EQ, "=="),
        js::Token(js::Token::FUNCTION, "function"),
        js::Token(js::Token::LPAREN, "("),
        js::Token(js::Token::RPAREN, ")"),
        js::Token(js::Token::LBRACE, "{"),
        js::Token(js::Token::RETURN, "return"),
        js::Token(js::Token::NUMBER, "1"),
        js::Token(js::Token::GTE, ">="),
        js::Token(js::Token::NUMBER, "4"),
        js::Token(js::Token::RBRACE, "}"),
        js::Token(js::Token::SEMICOLON, ";"),
        js::Token(js::Token::EOS, 0),
        js::Token(js::Token::EOS, 0),
        js::Token(js::Token::EOS, 0),
    };

    for (js::Token expected_token : expected_tokens) {
        js::Token actual_token = t.next_token();
        EXPECT_EQ(actual_token, expected_token);
    }
}

#endif // TST_TEST_H
