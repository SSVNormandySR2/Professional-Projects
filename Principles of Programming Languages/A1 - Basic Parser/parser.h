#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "lexer.h"
#include <vector>
#include <map>
#include <algorithm>

/*
 * This enum is for statement types
 */
typedef enum
{
    input_statement,
    output_statement,
    do_statement,
    invoke_statement,
    assign_statement
} stateType;

/*
 * This enum is for operators
 */
typedef enum
{
    add,
    subtract,
    multiply,
    divide,
    nothing
} op;

/*
 * This struct is a linked list of statement
 * information for program execution
 */
struct statement
{
    stateType type;
    int dstAddr;
    op sign;
    int opAddr1;
    int opAddr2;
    int procAddr;
    statement* next;
};

class Parser {
private:
    LexicalAnalyzer lexer;
    void syntax_error();
    Token expect(TokenType expected_type);
    std::map<std::string, int> varTable; //Symbol table
    std::vector<int> varMem; //Symbol memoryint nextAddr; //Memory counter
    std::map<std::string, int> procTable; //Procedure table
    std::vector<statement*> procMem; //Procedure pointers
    std::vector<int> inputMem; //Input vector
    int nextAddr; //Memory counter
    int procCounter; //Procedure counter
    int inputCounter; //Input counter
    int errorCounter; //Syntax error counter
public:
    Parser();
    void parseInput();
    statement* parseInputProgram();
    void parseProcDeclSection();
    void parseProcDecl();
    int parseProcName();
    statement* parseProcBody();
    statement* parseStatementList();
    statement* parseStatement();
    statement* parseInputStatement();
    statement* parseOutputStatement();
    statement* parseProcInvocation();
    statement* parseDoStatement();
    statement* parseAssignStatement();
    statement* parseExpression();
    int parsePrimary();
    op parseOperator();
    statement* parseMain();
    void parseInputs();

    int varSearch(std::string);
    int procSearch(std::string);
    int allocateVar(std::string);
    int allocateProc(std::string);
    void insertVar(int);
    void insertProc(statement*);
    void insertInput(int);
    void executeProgram(statement*);
};

#endif
