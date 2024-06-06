/*
 * Vincent Latona
 */

#ifndef __PARSER_H__
#define __PARSER_H__

#include "lexer.h"
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>

/*
 * Enum for nodeType
 */
typedef enum nodeType{TERM, EXPR};

/*
 * Enum for data types
 */
typedef enum dataType{arraydecl, scalar, arraytype, error};

/*
 * Structure for tree nodes
 */
struct treeNode
{
    std::string lexeme; //Lexeme of the token
    std::string op; //Operator of the token
    dataType data = error;
    int line = 0;
    struct treeNode* left = NULL; //Left node
    struct treeNode* center = NULL; //Center node
    struct treeNode* right = NULL; //Right node
};

/*
 * Structure for stack nodes
 */
struct stackNode
{
    nodeType type; //Node type
    Token token; //Token if applicable
    struct treeNode* root = NULL; //Tree root pointer
};

/*
 * This class implements the parser and program
 */
class Parser
{
private:
    LexicalAnalyzer lexer; //Private objects/variables
    std::string table[12][12];
    std::map<TokenType, int> binding;
    std::map<std::string, dataType> typeMap;
    std::vector<int> expressionErrors;
    std::vector<int> assignmentErrors;
    std::stack<stackNode> expr;
    std::stack<stackNode> reductionStack;
    int treeParse;
    int errCount;
    struct treeNode* first;

    Token terminalPeek(); //Private functions
    int searchTable(TokenType);
    dataType searchType(std::string);
    Token expect(TokenType);
    bool EOFpeek();
    void syntaxError();
    void parseProgram();
    void parseDeclarationSection();
    void parseScalarDeclarationSection();
    void parseArrayDeclarationSection();
    void parseIDList(dataType);
    void parseBlock();
    void parseStatementList();
    void parseStatement();
    void parseAssignStatement();
    void parseOutputStatement();
    struct treeNode* parseVariableAccess();
    struct treeNode* parseExpression();
    struct stackNode reduce(std::string);
public:
    Parser(); //Constructor
    void parseInput(); //Public functions
    void printTree();
    void typeCheck();
};

#endif //__PARSER_H__