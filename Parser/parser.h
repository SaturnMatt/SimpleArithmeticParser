// SimpleArithmeticParser
// Copyright (c) 2023 Matt Moen
// https://github.com/SaturnMatt/SimpleArithmeticParser
// Created: 2023-03-25
//
// This project is an educational arithmetic expression parser that
// demonstrates recursive descent parsing techniques in C++.
//
// Released under the MIT License. For details, see the accompanying LICENSE file
// or visit https://opensource.org/licenses/MIT

#pragma once

#include <string>
#include <cctype>
#include <stdexcept>

// The Parser class provides methods for parsing arithmetic expressions
// using recursive descent parsing techniques.
class Parser {
public:
    // Constructor that takes an input string containing the arithmetic expression
    Parser(const std::string& input);

    // Parses the arithmetic expression and returns the result as an integer
    int parse();

private:
    std::string input;  // The input arithmetic expression
    size_t pos;  // The current position in the input string

    // Skips whitespace characters in the input string
    void skip_whitespace();

    // Parses an expression consisting of terms separated by '+' or '-'
    int parse_expression();

    // Parses a term consisting of factors separated by '*' or '/'
    int parse_term();

    // Parses a factor, which is either an expression in parentheses or an integer
    int parse_factor();

    // Parses an integer value from the input string
    int parse_integer();
};
