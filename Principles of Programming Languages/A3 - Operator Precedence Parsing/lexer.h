#ifndef __LEXER__H__
#define __LEXER__H__

#include <vector>
#include <string>

#include "inputbuf.h"

// ------- token types -------------------

typedef enum { END_OF_FILE = 0,
    SCALAR, ARRAY, OUTPUT, PLUS, MINUS, DIV, MULT,
    EQUAL, SEMICOLON,
    LBRAC, RBRAC, LPAREN, RPAREN, LBRACE, RBRACE,
    DOT, NUM, ID, ERROR
} TokenType;

class Token {
public:
    void Print();

    std::string lexeme;
    TokenType token_type;
    int line_no;
};

class LexicalAnalyzer {
public:
    Token GetToken();
    void UngetToken(int);
    Token peek(int);
    LexicalAnalyzer();

private:
    std::vector<Token> tokenList;
    Token GetTokenMain();
    int line_no;
    int index;
    Token tmp;
    InputBuffer input;

    bool SkipSpace();
    int FindKeywordIndex(std::string);
    Token ScanIdOrKeyword();
    Token ScanNumber();
};

#endif  //__LEXER__H__