/*
 * Vincent Latona
 */

#ifndef __PARSER_H__
#define __PARSER_H__

#include "execute.h"
#include "lexer.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

class Parser
{
private:
    std::map<std::string, int> memMap;
    LexicalAnalyzer lexer;
    int searchMem(std::string);
    Token expect(TokenType);
    void syntaxError();
    struct InstructionNode* parseProgram();
    void parseVariableSection();
    void parseIDList();
    struct InstructionNode* parseBody();
    struct InstructionNode* parseStatementList();
    struct InstructionNode* parseStatement();
    struct InstructionNode* parseAssignStatement();
    struct InstructionNode* parseExpression();
    int parsePrimary();
    ArithmeticOperatorType parseOperator();
    struct InstructionNode* parseOutputStatement();
    struct InstructionNode* parseInputStatement();
    struct InstructionNode* parseWhileStatement();
    struct InstructionNode* parseIfStatement();
    struct InstructionNode* parseCondition();
    ConditionalOperatorType parseRelationalOperator();
    struct InstructionNode* parseSwitchStatement();
    struct InstructionNode* parseForStatement();
    struct InstructionNode* parseCaseList(Token);
    struct InstructionNode* parseCase(Token);
    struct InstructionNode* parseDefaultCase();
    void parseInputs();
    void parseNumList();
public:
    struct InstructionNode* parseInputProgram();
};

#endif //__PARSER_H__
