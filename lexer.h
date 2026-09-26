
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Types of tokens
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    SEMICOLON,
    LPAREN,
    RPAREN,
    END_OF_FILE,
    INVALID
};

// Token structure
struct Token
{
    TokenType type;
    string value;
};

// Lexer class
class Lexer
{
private:
    string input;
    int pos;

public:
    Lexer(string text);

    vector<Token> tokenize();

    void printTokens(vector<Token> tokens);
};

#endif
