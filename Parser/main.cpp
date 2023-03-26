// SimpleArithmeticParser
// Copyright (c) 2023 Matt Moen
// https://github.com/SaturnMatt/SimpleArithmeticParser
// Created: 2023-03-25
//
// This project is a simple arithmetic expression parser that
// demonstrates recursive descent parsing techniques in C++.
//
// Released under the MIT License. For details, see the accompanying LICENSE file
// or visit https://opensource.org/licenses/MIT

#include <iostream>
#include "parser.h"

int main() {
    std::string input;

    // Loop until the user enters a blank expression
    while (true) {
        std::cout << "Enter an arithmetic expression (or press ENTER to exit): ";
        std::getline(std::cin, input);

        if (input.empty()) break;

        try {
            Parser parser(input);
            int result = parser.parse();

            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
