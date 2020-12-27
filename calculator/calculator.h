#include <string>
#include <stack>
#include <vector>

#ifndef CALCULATOR_H
#define CALCULATOR_H

template <typename N>
class Calculator {
public:
    Calculator();
    N parse(std::string);
private:
    std::size_t index = 0;
    std::string input;

    N expr();
    N term();
    N factor();
    N number();

    void discard_whitespace() {
        while (input[index] == ' ') {
            index += 1;
        }
    }

    bool match(char c) {
        discard_whitespace();

        bool is_match = input[index] == c;

        if (is_match) {
            index += 1;
        }

        return is_match;
    }

    bool peek_digit() {
        discard_whitespace();

        return isdigit(input[index]);
    }

    int parse_digit() {
        return input[index++] - '0';
    }
};

template<typename N>
Calculator<N>::Calculator()
{

}

template <typename N>
N Calculator<N>::parse(std::string input)
{
    this->index = 0;
    this->input = input;

    return expr();
}

/// Grammar:
///
/// expr   := term   ('+' term   | '-' term)*
/// term   := factor ('*' factor | '/' factor)*
/// factor := ['-']  (number     | '(' expr ')')
/// number := digit+

template <typename N>
N Calculator<N>::expr()
{
    N result = term();

    while (true) {
        if (match('+')) {
            result += term();
        } else if (match('-')) {
            result -= term();
        } else {
            return result;
        }
    }
}

template <typename N>
N Calculator<N>::term()
{
    N result = factor();

    while (true) {
        if (match('*')) {
            result *= factor();
        } else if (match('/')) {
            result /= factor();
        } else {
            return result;
        }
    }
}

template <typename N>
N Calculator<N>::factor()
{
    int sign = match('-') ? -1 : 1;

    if (peek_digit()) {
        return sign * number();
    }

    if (match('(')) {
        N result = expr();

        if (!match(')')) {
            // TODO: Throw the correct exception.
            throw std::exception();
        }

        return sign * result;
    }

    // TODO: Throw the correct exception.
    throw std::exception();
}

template <typename N>
N Calculator<N>::number()
{
    N result {};

    while (peek_digit()) {
        result = result * 10 + parse_digit();
    }

    return result;
}

#endif // CALCULATOR_H
