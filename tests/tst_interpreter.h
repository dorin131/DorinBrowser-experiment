#ifndef TST_INTERPRETER_H
#define TST_INTERPRETER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../JS/tokenizer.h"
#include "../JS/parser.h"
#include "../JS/value.h"
#include "../JS/interpreter.h"

using namespace testing;

struct test {
    std::string code;
    js::Value::Type result_type;
    std::string result_value;
    test(std::string c, js::Value::Type r_t, std::string r_v)
        : code(c), result_type(r_t), result_value(r_v) {}
};

std::vector<test> tests = {
    test("1+2", js::Value::NUMBER, "3"),
    test("2*3;", js::Value::NUMBER, "6"),
    test("2 * (3 + 1);", js::Value::NUMBER, "8"),
    test("\"hello\" + \"world\"", js::Value::STRING, "helloworld"),
    test("\"hello\" + 100", js::Value::STRING, "hello100"),
    test("2 * 2; 3 * 3", js::Value::NUMBER, "9"),
    test("var x = 1", js::Value::UNDEFINED, ""),
    test("var x = 1; x", js::Value::NUMBER, "1"),
    test("var x = 10 * (3+3); x + 1;", js::Value::NUMBER, "61"),
    test("var x = 10 * (3+3); var y = x + 1; y-1;", js::Value::NUMBER, "60"),
    test("function() {}", js::Value::UNDEFINED, ""),
    test("function() { 1 + 2; };", js::Value::UNDEFINED, ""),
    test("function() { return 3; };", js::Value::UNDEFINED, ""),
    test("var f = function() { return 4; }; f()", js::Value::NUMBER, "4"),
    test("var f = function() { return 4 / 2; }; f() *3;", js::Value::NUMBER, "6"),
    test("var f = function() { var ff = function(){return 8;}; return ff(); }; f()", js::Value::NUMBER, "8"),
    test("var f = function(a) {};", js::Value::UNDEFINED, ""),
    test("var f = function(a) { return a; }; f(88)", js::Value::NUMBER, "88"),
    test("var f = function(a,b,c) { return a+b-c; }; var x = 2;", js::Value::UNDEFINED, ""),
    test("var f = function(a,b,c) { return a+b-c; }; var x = 2; f(x,x,3)", js::Value::NUMBER, "1"),
    test("function f() { return 3; };", js::Value::UNDEFINED, ""),
    test("function f() { return 4; }; f()", js::Value::NUMBER, "4"),
    test("function f(a,b,c) { return a+b-c; }; var x = 2; f(x,x,3)", js::Value::NUMBER, "1"),
};

TEST(Interpreter, AllTests)
{
    for (test test : tests) {
        js::Tokenizer t = js::Tokenizer(test.code);
        auto p = js::Parser(t);
        js::Program* program;
        try {
            program = p.parse_program();
        } catch (js::SyntaxError e) {
            std::cerr << "Parsing error: " + e.message << std::endl;
            GTEST_NONFATAL_FAILURE_("");
            return;
        }
        js::Interpreter interpreter;
        auto result = interpreter.run(program);

        std::cout << std::endl << test.code << std::endl;
        program->dump(0);

        EXPECT_EQ(result.get_type(), test.result_type);
        EXPECT_EQ(result.get_value(), test.result_value);
    }
}

#endif // TST_INTERPRETER_H
