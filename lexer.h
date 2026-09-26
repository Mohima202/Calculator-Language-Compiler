
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
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
struct Token
{
    TokenType type;
    string value;
};
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
