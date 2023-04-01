# SimpleArithmeticParser

SimpleArithmeticParser is an arithmetic expression parser written in C++ that demonstrates recursive descent parsing techniques. The parser can evaluate expressions with addition, subtraction, multiplication, and division operators, as well as handle parentheses and follow the order of operations (PEMDAS).

## Recursive Descent Parsing

Recursive descent parsing is a top-down parsing technique that starts with the highest-level grammar rule and recursively applies lower-level grammar rules until a valid parse tree is constructed or an error is encountered. It typically consists of a set of mutually recursive functions, each responsible for parsing a specific grammar rule.

This parser uses recursive descent parsing to evaluate arithmetic expressions by breaking them down into a hierarchy of expressions, terms, and factors, as defined by the grammar rules.

## Parser Grammar Rules

The grammar employed by the provided parser can be described using Backus-Naur Form (BNF) notation as follows:
```
<expression> ::= <term> {('+' | '-') <term>}
<term>       ::= <factor> {('*' | '/') <factor>}
<factor>     ::= '(' <expression> ')' | <integer>
<integer>    ::= <digit> {<digit>}
<digit>      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
```
This grammar represents arithmetic expressions with the following rules:

`<expression>` An expression is a sequence of one or more terms separated by addition (+) or subtraction (-) operators.  
`<term>` A term is a sequence of one or more factors separated by multiplication (*) or division (/) operators.  
`<factor>` A factor is either an expression enclosed in parentheses or an integer.  
`<integer>` An integer is a sequence of one or more digits.  
`<digit>` A digit is any of the characters '0' through '9'.  
Note that the grammar does not include whitespace handling, as it is implicitly ignored by the parser implementation.

## Standard Libarary Functions

There are several standard library functions that can be useful when writing a parser in C++. Some of these functions are part of the `<cctype>` and `<algorithm>` headers. Here are a few examples:

**`<cctype>` functions:**

`std::isalpha` Checks if a character is an alphabetic letter (A-Z, a-z).  
`std::isalnum` Checks if a character is an alphanumeric character (A-Z, a-z, 0-9).  
`std::isspace` Checks if a character is a whitespace character (e.g., space, tab, newline).  
`std::islower` Checks if a character is a lowercase letter (a-z).  
`std::isupper` Checks if a character is an uppercase letter (A-Z).  
`std::tolower` Converts an uppercase character to its lowercase equivalent.  
`std::toupper` Converts a lowercase character to its uppercase equivalent.

**`<algorithm>` functions:**

`std::find` Searches for a value in a range (e.g., a character in a string).  
`std::find_if` Searches for the first element in a range that satisfies a given predicate (e.g., the first non-whitespace character in a string).  
`std::all_of` Checks if all elements in a range satisfy a given predicate (e.g., all characters in a string are digits).  
`std::any_of` Checks if at least one element in a range satisfies a given predicate (e.g., a string contains at least one digit).  
`std::none_of` Checks if none of the elements in a range satisfy a given predicate (e.g., a string contains no digits).

These functions can be helpful when you need to classify, search, or manipulate characters within a string while writing a parser. Depending on your parser's requirements, you may also find other standard library functions and algorithms useful.

## Source Files

This project consists of three main source files:

1. [parser.h](https://github.com/SaturnMatt/SimpleArithmeticParser/blob/main/Parser/parser.h) - Contains the declaration of the `Parser` class, which is responsible for parsing arithmetic expressions using recursive descent parsing techniques. It declares the constructor, public methods, and private methods for the `Parser` class.

2. [parser.cpp](https://github.com/SaturnMatt/SimpleArithmeticParser/blob/main/Parser/parser.cpp) - Contains the implementation of the `Parser` class. This file defines the constructor and methods declared in the `parser.h` header file, including the recursive descent parsing functions for expressions, terms, factors, and integers.

3. [main.cpp](https://github.com/SaturnMatt/SimpleArithmeticParser/blob/main/Parser/main.cpp) - Contains the main program that demonstrates how to use the `Parser` class. It provides a simple command-line interface for users to enter arithmetic expressions, which are then parsed and evaluated by the `Parser`. The results of the evaluations are printed to the console.

You can find the source files in the [SimpleArithmeticParser repository](https://github.com/SaturnMatt/SimpleArithmeticParser).

## How to Use the Parser

1. Clone the repository and compile the code using a C++11 compatible compiler:
`g++ -std=c++11 main.cpp -o parser`
2. Run the parser executable:
`./parser`
3. Enter an arithmetic expression when prompted:
`Enter an arithmetic expression: (7 + 3) * (4 - 2)`
4. The parser will evaluate the expression and display the result:
`Result: 20`

Note that the parser ignores whitespace and can handle various spacing formats in the input. If the input expression is malformed or contains invalid characters, the parser will display an appropriate error message.
