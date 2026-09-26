
#include "lexer.h"
#include <cctype>

Lexer::Lexer(string text)
{
    input = text;
    pos = 0;
}

vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;

    while (pos < input.length())
    {
        char current = input[pos];

        // Ignore spaces
        if (isspace(current))
        {
            pos++;
            continue;
        }

        // Identifier / Keyword
        if (isalpha(current))
        {
            string word;

            while (pos < input.length() &&
                   (isalnum(input[pos]) || input[pos] == '_'))
            {
                word += input[pos];
                pos++;
            }

            if (word == "int")
                tokens.push_back({KEYWORD, word});
            else
                tokens.push_back({IDENTIFIER, word});

            continue;
        }

        // Number
        if (isdigit(current))
        {
            string number;

            while (pos < input.length() && isdigit(input[pos]))
            {
                number += input[pos];
                pos++;
            }

            tokens.push_back({NUMBER, number});
            continue;
        }

        switch (current)
        {
        case '=':
            tokens.push_back({ASSIGN, "="});
            break;

        case '+':
            tokens.push_back({PLUS, "+"});
            break;

        case '-':
            tokens.push_back({MINUS, "-"});
            break;

        case '*':
            tokens.push_back({MULTIPLY, "*"});
            break;

        case '/':
            tokens.push_back({DIVIDE, "/"});
            break;

        case ';':
            tokens.push_back({SEMICOLON, ";"});
            break;

        case '(':
            tokens.push_back({LPAREN, "("});
            break;

        case ')':
            tokens.push_back({RPAREN, ")"});
            break;

        default:
            tokens.push_back({INVALID, string(1, current)});
            break;
        }

        pos++;
    }

    tokens.push_back({END_OF_FILE, "EOF"});

    return tokens;
}

void Lexer::printTokens(vector<Token> tokens)
{
    cout << "\n========== TOKENS ==========\n";

    for (Token t : tokens)
    {
        switch (t.type)
        {
        case KEYWORD:
            cout << "KEYWORD : " << t.value << endl;
            break;

        case IDENTIFIER:
            cout << "IDENTIFIER : " << t.value << endl;
            break;

        case NUMBER:
            cout << "NUMBER : " << t.value << endl;
            break;

        case ASSIGN:
            cout << "ASSIGN : " << t.value << endl;
            break;

        case PLUS:
            cout << "PLUS : " << t.value << endl;
            break;

        case MINUS:
            cout << "MINUS : " << t.value << endl;
            break;

        case MULTIPLY:
            cout << "MULTIPLY : " << t.value << endl;
            break;

        case DIVIDE:
            cout << "DIVIDE : " << t.value << endl;
            break;

        case SEMICOLON:
            cout << "SEMICOLON : " << t.value << endl;
            break;

        case LPAREN:
            cout << "LPAREN : " << t.value << endl;
            break;

        case RPAREN:
            cout << "RPAREN : " << t.value << endl;
            break;

        case INVALID:
            cout << "LEXICAL ERROR : Invalid Character -> "
                 << t.value << endl;
            break;

        default:
            break;
        }
    }
}
