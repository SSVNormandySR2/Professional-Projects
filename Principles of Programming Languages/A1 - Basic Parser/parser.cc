/*
 * Vincent Latona
 */
#include <iostream>
#include <cstdlib>
#include "parser.h"

using namespace std;

void Parser::syntax_error()
{
    cout << "SYNTAX ERROR !!!\n";
    errorCounter++;
    exit(1);
}

/*
 * This constructor instantiates private data
 */
Parser::Parser()
{
    nextAddr = 0; //Counters start at 0
    inputCounter = 0;
    procCounter = 0;
    errorCounter = 0;
}

// this function gets a token and checks if it is
// of the expected type. If it is, the token is
// returned, otherwise, syntax_error() is generated
// this function is particularly useful to match
// terminals in a right hand side of a rule.
Token Parser::expect(TokenType expected_type)
{
    Token t = lexer.GetToken();
    if (t.token_type != expected_type)
        syntax_error();
    return t;
}

/*
 * This function searches the variable table for a given variable
 */
int Parser::varSearch(string varName)
{
    auto iterator = varTable.find(varName); //Search table
    if(iterator == varTable.end()) //Not found case
    {
        return -1; //Return -1 for not found
    }
    else //Found case
    {
        return iterator->second; //Return address of variable
    }
}

/*
 * This function searches the procedure table for a given procedure
 */
int Parser::procSearch(string procName)
{
    auto iterator = procTable.find(procName); //Search table
    if(iterator == procTable.end()) //Not found case
    {
        return -1; //Return -1 for not found
    }
    else //Found case
    {
        return iterator->second; //Return address of procedure
    }
}

/*
 * This function inserts a new entry into the variable table
 */
int Parser::allocateVar(string varName)
{
    varTable.insert(pair<string, int>(varName, nextAddr)); //Insert new binding
    return nextAddr; //Return address of variable
}

/*
 * This function inserts a new entry into the procedure table
 */
int Parser::allocateProc(string procName)
{
    procTable.insert(pair<string, int>(procName, procCounter)); //Insert new binding
    return procCounter; //Return address of procedure
}

/*
 * This function inserts variables and their values into variable memory
 */
void Parser::insertVar(int value)
{
    varMem.push_back(value); //Insert variable value into variable memory
    nextAddr++; //Increment to next available address
    return; //Return from function
}

/*
 * This function inserts procedure pointers into procedure memory
 */
void Parser::insertProc(statement* head)
{
    procMem.push_back(head); //Insert procedure pointer into procedure memory
    procCounter++; //Increment to next available address
    return; //Return from function
}

/*
 * This function inserts input values into the input memory
 */
void Parser::insertInput(int value)
{
    inputMem.push_back(value); //Insert input value into input memory
    inputCounter++; //Increment to next available address
    return; //Return from function
}

/*
 * This function initializes the recursive-descent parsing of stdin
 */
void Parser::parseInput()
{
    statement* main = parseInputProgram(); //Handle rules
    parseInputs(); //Handle rules
    expect(END_OF_FILE); //Consume token
    if(errorCounter == 0 && main != NULL) //Success case
    {
        inputCounter = 0; //Reset input counter
        executeProgram(main); //Execute program
        return; //Return from function
    }
    else //Error case
    {
        return; //Return
    }
}

/*
 * This function handles the input_program rules
 */
statement* Parser::parseInputProgram()
{
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == PROC) //Check for proc_decl_section
    {
        parseProcDeclSection(); //Handle rules
        statement* main = parseMain(); //Handle rules
        if(errorCounter == 0 && main != NULL) //Success case
        {
            return main; //Return linked list
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else if(t.token_type == MAIN) //Check for main
    {
        statement* main = parseMain(); //Handle rules
        if(errorCounter == 0 && main != NULL) //Success case
        {
            return main; //Return linked list
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else
    {
        syntax_error(); //Unknown input
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the proc_decl_section rules
 */
void Parser::parseProcDeclSection()
{
    parseProcDecl(); //Handle rules
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == PROC) //Check for proc_decl
    {
        parseProcDeclSection(); //Handle recursive rule
    }
    return; //Return from function
}

/*
 * This function handles the proc_decl rules
 */
void Parser::parseProcDecl()
{
    expect(PROC); //Consume token
    int procAddr = parseProcName(); //Handle rules
    statement* list = parseProcBody(); //Handle rules
    expect(ENDPROC); //Consume token
    if(errorCounter == 0 && procAddr != -1 && list != NULL) //Success case
    {
        insertProc(list); //Insert procedure into memory
        return; //Return from function
    }
    else //Error case
    {
        return; //Return from function
    }
}

/*
 * This function handles the proc_name rules
 */
int Parser::parseProcName()
{
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == ID) //Check for ID
    {
        Token id = expect(ID); //Consume token
        int addr = procSearch(id.lexeme); //Search table for procedure
        if(addr < 0) //Not found case
        {
            addr = allocateProc(id.lexeme); //Allocate procedure memory
        }
        return addr; //Return address of procedure
    }
    else if(t.token_type == NUM) //Check for NUM
    {
        Token num = expect(NUM); //Consume token
        int addr = procSearch(num.lexeme); //Search table for procedure
        if(addr < 0) //Not found case
        {
            addr = allocateProc(num.lexeme); //Allocate procedure memory
        }
        return addr; //Return address of procedure
    }
    else
    {
        syntax_error(); //Unknown input
        return -1; //Return -1 for error
    }
}

/*
 * This function handles the proc_body rules
 */
statement* Parser::parseProcBody()
{
    statement* list = parseStatementList(); //Handle rules
    if(errorCounter == 0 && list != NULL) //Success case
    {
        return list; //Return linked list
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the statement_list rules
 */
statement* Parser::parseStatementList()
{
    statement* list = parseStatement(); //Handle rules
    if(errorCounter == 0 && list != NULL) //Success case
    {
        Token t1 = lexer.peek(1); //Look at current token
        Token t2 = lexer.peek(2); //Look at next token
        if(t1.token_type == INPUT |
           t1.token_type == OUTPUT |
           t1.token_type == DO) //Check for input/output/do_statements
        {
            statement* next = parseStatementList(); //Handle recursive rule
            if(errorCounter == 0 && next != NULL) //Success case
            {
                list->next = next; //Link nodes
            }
            else //Error case
            {
                return NULL; //Return empty pointer
            }
        }
        else if(t1.token_type == ID &&
                t2.token_type == EQUAL) //Check for assign_statement
        {
            statement* next = parseStatementList(); //Handle recursive rule
            if(errorCounter == 0 && next != NULL) //Success case
            {
                list->next = next; //Link nodes
            }
            else //Error case
            {
                return NULL; //Return empty pointer
            }
        }
        else if((t1.token_type == ID | t1.token_type == NUM) &&
                t2.token_type == SEMICOLON) //Check for proc_invocation
        {
            statement* next = parseStatementList(); //Handle recursive rule
            if(errorCounter == 0 && next != NULL) //Success case
            {
                list->next = next; //Link nodes
            }
            else //Error case
            {
                return NULL; //Return empty pointer
            }
        }
        return list; //Return linked list
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the statement rules
 */
statement* Parser::parseStatement()
{
    Token t1 = lexer.peek(1); //Look at current token
    Token t2 = lexer.peek(2); //Look at next token
    if(t1.token_type == INPUT) //Check for input_statement
    {
        statement* list = parseInputStatement(); //Handle rules
        if(errorCounter == 0 && list != NULL) //Success case
        {
            return list; //Return node pointer
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else if(t1.token_type == OUTPUT) //Check for output_statement
    {
        statement* list = parseOutputStatement(); //Handle rules
        if(errorCounter == 0 && list != NULL) //Success case
        {
            return list; //Return node pointer
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else if(t1.token_type == DO) //Check for do_statement
    {
        statement* list = parseDoStatement(); //Handle rules
        if(errorCounter == 0 && list != NULL) //Success case
        {
            return list; //Return node pointer
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else if(t1.token_type == ID &&
            t2.token_type == EQUAL) //Check for assign_statement
    {
        statement* list = parseAssignStatement(); //Handle rules
        if(errorCounter == 0 && list != NULL) //Success case
        {
            return list; //Return node pointer
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else if((t1.token_type == ID | t1.token_type == NUM) &&
            t2.token_type == SEMICOLON) //Check for proc_invocation
    {
        statement* list = parseProcInvocation(); //Handle rules
        if(errorCounter == 0 && list != NULL) //Success case
        {
            return list; //Return node pointer
        }
        else //Error case
        {
            return NULL; //Return empty pointer
        }
    }
    else
    {
        syntax_error(); //Unknown input
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the input_statement rules
 */
statement* Parser::parseInputStatement()
{
    expect(INPUT); //Consume token
    Token id = expect(ID); //Consume token
    expect(SEMICOLON); //Consume token
    if(errorCounter == 0) //Success case
    {
        int addr = varSearch(id.lexeme); //Search table for variable
        if(addr < 0) //Not found case
        {
            addr = allocateVar(id.lexeme); //Allocate variable memory
            insertVar(0); //Insert variable into memory
        }
        statement* list = new statement(); //Create new node and instantiate data
        list->type = input_statement;
        list->dstAddr = addr;
        list->sign = nothing;
        list->opAddr1 = -1;
        list->opAddr2 = -1;
        list->procAddr = -1;
        list->next = NULL;
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the output_statement rules
 */
statement* Parser::parseOutputStatement()
{
    expect(OUTPUT); //Consume token
    Token id = expect(ID); //Consume token
    expect(SEMICOLON); //Consume token
    if(errorCounter == 0) //Success case
    {
        int addr = varSearch(id.lexeme); //Search table for variable
        if(addr < 0) //Not found case
        {
            addr = allocateVar(id.lexeme); //Allocate variable memory
            insertVar(0); //Insert variable into memory
        }
        statement* list = new statement(); //Create new node and instantiate data
        list->type = output_statement;
        list->dstAddr = addr;
        list->sign = nothing;
        list->opAddr1 = -1;
        list->opAddr2 = -1;
        list->procAddr = -1;
        list->next = NULL;
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the proc_invocation rules
 */
statement* Parser::parseProcInvocation()
{
    int procAddr = parseProcName(); //Handle rules
    expect(SEMICOLON); //Consume token
    if(errorCounter == 0 && procAddr != -1) //Success case
    {
        statement* list = new statement(); //Create node and instantiate data
        list->type = invoke_statement;
        list->dstAddr = -1;
        list->sign = nothing;
        list->opAddr1 = -1;
        list->opAddr2 = -1;
        list->procAddr = procAddr;
        list->next = NULL;
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointers
    }
}

/*
 * This function handles the do_statement rules
 */
statement* Parser::parseDoStatement()
{
    expect(DO); //Consume token
    Token id = expect(ID); //Consume token
    statement* list = parseProcInvocation(); //Handle rules
    if(errorCounter == 0 && list != NULL) //Success case
    {
        int addr = varSearch(id.lexeme); //Search table for variable
        if(addr < 0) //Not found case
        {
            addr = allocateVar(id.lexeme); //Allocate variable memory
            insertVar(0); //Insert variable into memory
        }
        list->type = do_statement; //Modify returned node data
        list->dstAddr = addr;
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return emtpy pointer
    }
}

/*
 * This function handles the assign_statement rules
 */
statement* Parser::parseAssignStatement()
{
    Token id = expect(ID); //Consume token
    expect(EQUAL); //Consume token
    statement* list = parseExpression(); //Handle rules
    expect(SEMICOLON); //Consume token
    if(errorCounter == 0 && list != NULL) //Success case
    {
        int addr = varSearch(id.lexeme); //Search table for variable
        if(addr < 0) //Not found case
        {
            addr = allocateVar(id.lexeme); //Allocate variable memory
            insertVar(0); //Insert variable into memory
        }
        list->dstAddr = addr; //Add LHS to assign statement
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the expression rules
 */
statement* Parser::parseExpression()
{
    int op1 = parsePrimary(); //Handle rules
    int op2 = -1; //Initialize placeholders
    op expr = nothing;
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == PLUS | t.token_type == MINUS |
       t.token_type == MULT | t.token_type == DIV) //Check for operator
    {
        expr = parseOperator(); //Handle rules
        op2 = parsePrimary(); //Handle rules
        if(op2 == -1 | expr == nothing) //Error case
        {
            return NULL; //Return emtpy pointer
        }
    }
    if(errorCounter == 0 && op1 != -1) //Success case
    {
        statement* list = new statement(); //Create new node and instantiate data
        list->type = assign_statement;
        list->sign = expr;
        list->opAddr1 = op1;
        list->opAddr2 = op2;
        list->procAddr = -1;
        list->next = NULL;
        return list; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the primary rules
 */
int Parser::parsePrimary()
{
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == ID) //Check for ID
    {
        Token id = expect(ID); //Consume token
        int addr = varSearch(id.lexeme); //Search table for variable
        if(addr < 0) //Not found case
        {
            addr = allocateVar(id.lexeme); //Allocate variable memory
            insertVar(0); //Insert variable into memory
        }
        return addr; //Return address of variable
    }
    else if(t.token_type == NUM) //Check for NUM
    {
        Token num = expect(NUM); //Consume token
        int addr = varSearch(num.lexeme); //Search table for constant
        if(addr < 0) //Not found case
        {
            addr = allocateVar(num.lexeme); //Allocate constant memory
            int value = stoi(num.lexeme); //Obtain constant value
            insertVar(value); //Insert constant into memory
        }
        return addr; //Return address of variable
    }
    else
    {
        syntax_error(); //Unknown input
        return -1; //Return -1 for error
    }
}

/*
 * This function handles the operator rules
 */
op Parser::parseOperator()
{
    Token t = lexer.peek(1); //Look at current token
    if(t.token_type == PLUS) //Check for PLUS
    {
        expect(PLUS); //Consume token
        if(errorCounter == 0) //Success case
        {
            return add; //Return add sign
        }
        else //Error case
        {
            return nothing; //Return nothing for error
        }
    }
    else if(t.token_type == MINUS) //Check for MINUS
    {
        expect(MINUS); //Consume token
        if(errorCounter == 0) //Success case
        {
            return subtract; //Return subtraction sign
        }
        else //Error case
        {
            return nothing; //Return nothing for error
        }
    }
    else if(t.token_type == MULT) //Check for MULT
    {
        expect(MULT); //Consume token
        if(errorCounter == 0) //Success case
        {
            return multiply; //Return multiply sign
        }
        else //Error case
        {
            return nothing; //Return nothing for error
        }
    }
    else if(t.token_type == DIV) //Check for DIV
    {
        expect(DIV); //Consume token
        if(errorCounter == 0) //Success case
        {
            return divide; //Return divide sign
        }
        else //Error case
        {
            return nothing; //Return nothing for error
        }
    }
    else
    {
        syntax_error(); //Unknown input
        return nothing; //Return nothing for error
    }
}

/*
 * This function handles the main rules
 */
statement* Parser::parseMain()
{
    expect(MAIN); //Consume token
    statement* main = parseProcBody(); //Handle rules
    if(errorCounter == 0 && main != NULL) //Success case
    {
        return main; //Return node pointer
    }
    else //Error case
    {
        return NULL; //Return empty pointer
    }
}

/*
 * This function handles the inputs rules
 */
void Parser::parseInputs()
{
    Token input = expect(NUM); //Consume token
    if(errorCounter == 0) //Success case
    {
        int insert = stoi(input.lexeme); //Convert lexeme to int
        insertInput(insert); //Insert input into input memory
        Token t = lexer.peek(1); //Look at current token
        if(t.token_type == NUM) //Check for NUM
        {
            parseInputs(); //Handle recursive rule
        }
        return; //Return from function
    }
    else //Error case
    {
        return; //Return from function
    }
}

/*
 * This function executes the stored program
 */
void Parser::executeProgram(statement* start)
{
    if(errorCounter == 0 && start != NULL) //Valid syntax case
    {
        statement* programCounter = start; //Point to first instruction
        while(programCounter != NULL) //Program iterator
        {
            switch(programCounter->type) //Handle statement types
            {
                case input_statement: //Handle input logic
                    varMem[programCounter->dstAddr] = inputMem[inputCounter]; //Assign input to variable
                    inputCounter++; //Increment to next input
                    break; //Break from condition check
                case output_statement: //Handle output logic
                    cout << varMem[programCounter->dstAddr] << " "; //Print output
                    break; //Break from condition check
                case do_statement: //Handle do logic
                    for(int a = 0; a < varMem[programCounter->dstAddr]; a++) //Iterate procedure calls
                    {
                        executeProgram(procMem[programCounter->procAddr]); //Execute procedure
                    }
                    break; //Break from condition check
                case invoke_statement: //Handle invoke logic
                    executeProgram(procMem[programCounter->procAddr]); //Execute procedure
                    break; //Break from condition check
                case assign_statement: //Handle assign logic
                    if(programCounter->opAddr2 == -1 && programCounter->sign == nothing)
                    {
                        varMem[programCounter->dstAddr] = varMem[programCounter->opAddr1]; //Assign single value
                    }
                    else
                    {
                        switch(programCounter->sign) //Handle operator types
                        {
                            case add: //Handle addition logic
                                varMem[programCounter->dstAddr] =
                                        varMem[programCounter->opAddr1] + varMem[programCounter->opAddr2]; //Assign addition
                                break; //Break from condition check
                            case subtract: //Handle subtraction logic
                                varMem[programCounter->dstAddr] =
                                        varMem[programCounter->opAddr1] - varMem[programCounter->opAddr2]; //Assign subtraction
                                break; //Break from condition check
                            case multiply: //Handle multiplication logic
                                varMem[programCounter->dstAddr] =
                                        varMem[programCounter->opAddr1] * varMem[programCounter->opAddr2]; //Assign multiplication
                                break; //Break from condition check
                            case divide: //Handle division logic
                                if(varMem[programCounter->opAddr2] == 0) //0 division error
                                {
                                    cout << "\nError: Division by Zero.\n"; //Print error
                                }
                                else //Carry out operation
                                {
                                    varMem[programCounter->dstAddr] =
                                            varMem[programCounter->opAddr1] / varMem[programCounter->opAddr2]; //Assign division
                                }
                                break; //Break from condition check
                            default: //Default case
                                break; //Break from condition check
                        }
                    }
                    break; //Break from condition check
                default: //Default case
                    break; //Break from condition check
            }
            programCounter = programCounter->next; //Iterate
        }
        return; //Return from function
    }
    else //Invalid syntax case
    {
        return; //Return from invalid syntax
    }
}

int main()
{
    // note: the parser class has a lexer object instantiated in it (see file
    // parser.h). You should not be declaring a separate lexer object.
    // You can access the lexer object in the parser functions as shown in
    // the example  method Parser::readAndPrintAllInput()
    // If you declare another lexer object, lexical analysis will
    // not work correctly
    Parser parser;

    parser.parseInput();
}