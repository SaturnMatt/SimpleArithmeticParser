// SimpleArithmeticParser
// https://github.com/SaturnMatt/SimpleArithmeticParser
//
// This project is a simple arithmetic expression parser that
// demonstrates recursive descent parsing techniques in C++.
//
// Released under the MIT License. For details, see the accompanying LICENSE file
// or visit https://opensource.org/licenses/MIT

#include "parser.h"

Parser::Parser(const std::string& input) : input(input), pos(0) {}

// Main parsing function
int Parser::parse() {
    skip_whitespace();
    int result = parse_expression();
    skip_whitespace();
    if (pos < input.size()) {
        throw std::runtime_error("Unexpected character: " + std::string(1, input[pos]));
    }
    return result;
}

// Expression consisting of terms separated by '+' or '-'
int Parser::parse_expression() {
    int left = parse_term();
    skip_whitespace();
    while (pos < input.size() && (input[pos] == '+' || input[pos] == '-')) {
        char op = input[pos++];
        skip_whitespace();
        int right = parse_term();
        if (op == '+') left += right;
        else left -= right;
        skip_whitespace();
    }
    return left;
}

// Term consisting of factors separated by '*' or '/'
int Parser::parse_term() {
    int left = parse_factor();
    skip_whitespace();
    while (pos < input.size() && (input[pos] == '*' || input[pos] == '/')) {
        char op = input[pos++];
        skip_whitespace();
        int right = parse_factor();
        if (op == '*') left *= right;
        else left /= right;
        skip_whitespace();
    }
    return left;
}

// Factor is either an expression in parentheses or an integer
int Parser::parse_factor() {
    int value;
    skip_whitespace();
    if (input[pos] == '(') {
        pos++;
        skip_whitespace();
        value = parse_expression();
        skip_whitespace();
        if (input[pos] == ')') {
            pos++;  // Consume the closing parenthesis
        }
        else {
            throw std::runtime_error("Expected closing parenthesis");
        }
    }
    else if (std::isdigit(input[pos])) {
        value = parse_integer();
    }
    else {
        throw std::runtime_error("Unexpected character: " + std::string(1, input[pos]));
    }
    return value;
}

int Parser::parse_integer() {
    int value = 0;
    while (pos < input.size() && std::isdigit(input[pos])) {
        value = value * 10 + (input[pos++] - '0');
    }
    return value;
}

void Parser::skip_whitespace() {
    while (pos < input.size() && std::isspace(input[pos])) {
        pos++;
    }
}