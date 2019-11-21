#include "catch2/catch.hpp"
#include "tokenizer/tokenizer.h"
#include "fmt/core.h"

#include <sstream>
#include <vector>

// 下面是示例如何书写测试用例
TEST_CASE("Test hello world.") {
    std::string input =
            "begin\n"
            "var a=1+2;\n"
            "print(a);\n"
            "end\n";
    std::stringstream ss;
    ss.str(input);
    miniplc0::Tokenizer tkz(ss);
    std::vector<miniplc0::Token> output = {
            miniplc0::Token(miniplc0::TokenType::BEGIN, std::string("begin"), 0, 0, 0, 5),
            miniplc0::Token(miniplc0::TokenType::VAR, std::string("var"), 1, 0, 1, 3),
            miniplc0::Token(miniplc0::TokenType::IDENTIFIER, std::string("a"), 1, 4, 1, 5),
            miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN, '=', 1, 5, 1, 6),
            miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER, 1, 1, 6, 1, 7),
            miniplc0::Token(miniplc0::TokenType::PLUS_SIGN, '+', 1, 7, 1, 8),
            miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER, 2, 1, 8, 1, 9),
            miniplc0::Token(miniplc0::TokenType::SEMICOLON, ';', 1, 9, 1, 10),
            miniplc0::Token(miniplc0::TokenType::PRINT, std::string("print"), 2, 0, 2, 5),
            miniplc0::Token(miniplc0::TokenType::LEFT_BRACKET, '(', 2, 5, 2, 6),
            miniplc0::Token(miniplc0::TokenType::IDENTIFIER, std::string("a"), 2, 6, 2, 7),
            miniplc0::Token(miniplc0::TokenType::RIGHT_BRACKET, ')', 2, 7, 2, 8),
            miniplc0::Token(miniplc0::TokenType::SEMICOLON, ';', 2, 8, 2, 9),
            miniplc0::Token(miniplc0::TokenType::END, std::string("end"), 3, 0, 3, 3)
    };
    auto result = tkz.AllTokens();
    REQUIRE_FALSE(result.second.has_value());
    REQUIRE((result.first == output));
}