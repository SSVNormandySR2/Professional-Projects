/*
 * Vincent Latona
 */

#include "parser.h"

using namespace std;

/*
 * This function parses and obtains the instruction-list
 */
struct InstructionNode * parse_generate_intermediate_representation()
{
    Parser parser; //Create parser object
    return parser.parseInputProgram(); //Return instruction list
}

/*
 * This function attempts to consume an expected token
 */
Token Parser::expect(TokenType expected)
{
    Token t = lexer.GetToken(); //Get token
    if(t.token_type != expected) //Error case
    {
        syntaxError(); //Print error
    }
    return t; //Return correct token
}

/*
 * This function prints syntax error and exits
 */
void Parser::syntaxError()
{
    cout << "SYNTAX ERROR !!!\n"; //Print error
    exit(1); //Exit program
    return; //Return from function
}

/*
 * This function searches the table for the index of a given variable/constant
 */
int Parser::searchMem(string search)
{
    auto index = memMap.find(search);
    if(index == memMap.end()) //Not found case
    {
        return -1; //Return invalid index
    }
    return index->second; //Return valid index
}

/*
 * This function parses the input program
 */
struct InstructionNode* Parser::parseInputProgram()
{
    struct InstructionNode* instrList = parseProgram(); //Parse program rules
    expect(END_OF_FILE); //Consume token
    return instrList; //Return instruction list
}

/*
 * This function parses the program rules
 */
struct InstructionNode* Parser::parseProgram()
{
    parseVariableSection(); //Parse variable-section rules
    struct InstructionNode* instrList = parseBody(); //Parse body rules
    parseInputs(); //Parse inputs rules
    return instrList; //Return instruction list
}

/*
 * This function parses variable-section rules
 */
void Parser::parseVariableSection()
{
    parseIDList(); //Parse id-list rules
    expect(SEMICOLON); //Consume token
    return; //Return from function
}

/*
 * This function parses id-list rules
 */
void Parser::parseIDList()
{
    Token var = expect(ID); //Consume token
    int index = searchMem(var.lexeme); //Search memory
    if(index == -1) //Allocate case
    {
        memMap.insert(pair<string, int>(var.lexeme, next_available)); //Make index mapping
        mem[next_available] = 0; //Initialize location
        next_available++; //Increment for next location
    }
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == COMMA) //Recursive case
    {
        expect(COMMA); //Consume token
        parseIDList(); //Parse id-list rules
    }
    return; //Return from function
}

/*
 * This function parses body rules
 */
struct InstructionNode* Parser::parseBody()
{
    expect(LBRACE); //Consume token
    struct InstructionNode* instrList = parseStatementList(); //Parse statement-list rules
    expect(RBRACE); //Consume token
    return instrList; //Return instruction list
}

/*
 * This function parses statement-list rules
 */
struct InstructionNode* Parser::parseStatementList()
{
    struct InstructionNode* instr1 = parseStatement(); //Parse statement rules
    struct InstructionNode* recList = NULL; //Initialize recursive list
    Token t = lexer.peek(1); //Check next token
    if((t.token_type == ID) | (t.token_type == INPUT) | (t.token_type == OUTPUT) | (t.token_type == WHILE) |
            (t.token_type == IF) | (t.token_type == SWITCH) | (t.token_type == FOR)) //Recursive case
    {
        recList = parseStatementList(); //Parse statement-list rules
    }
    struct InstructionNode* iterator = instr1; //Initialize iterator to head of possible list
    struct InstructionNode* follower = NULL; //Initialize follower to NULL
    while(iterator != NULL) //Iterate through possible list
    {
        follower = iterator; //Move follower
        iterator = iterator->next; //Iterate
    }
    if(follower == NULL) //Empty list case
    {
        return NULL; //Return NULL
    }
    follower->next = recList; //Link to recursive list
    return instr1; //Return instruction list
}

/*
 * This function parses statement rules
 */
struct InstructionNode* Parser::parseStatement()
{
    struct InstructionNode* instrList = NULL; //Initialize list to return
    Token t = lexer.peek(1); //Check next token
    switch(t.token_type) //Switch on token
    {
        case ID: //Assign case
            instrList = parseAssignStatement(); //Parse assign-statement rules
            break;
        case WHILE: //While case
            instrList = parseWhileStatement(); //Parse while-statement rules
            break;
        case IF: //If case
            instrList = parseIfStatement(); //Parse if-statement rules
            break;
        case SWITCH: //Switch case
            instrList = parseSwitchStatement(); //Parse switch-statement rules
            break;
        case FOR: //For case
            instrList = parseForStatement(); //Parse for-statement rules
            break;
        case INPUT: //Input case
            instrList = parseInputStatement(); //Parse input-statement rules
            break;
        case OUTPUT: //Output case
            instrList = parseOutputStatement(); //Parse output-statement rules
            break;
        default: //Error case
            syntaxError(); //Print error
            break;
    }
    return instrList; //Return instruction list
}

/*
 * This function parses assign-statement rules
 */
struct InstructionNode* Parser::parseAssignStatement()
{
    struct InstructionNode* assignment = NULL; //Create instruction to return
    Token var = expect(ID); //Consume token
    int index = searchMem(var.lexeme); //Search memory
    expect(EQUAL); //Consume token
    Token t1 = lexer.peek(1); //Check next token
    Token t2 = lexer.peek(2); //Check next token
    if(((t1.token_type == ID) | (t1.token_type == NUM)) &
    ((t2.token_type == PLUS) | (t2.token_type == MINUS) | (t2.token_type == MULT) | (t2.token_type == DIV))) //ID EQUAL expr SEMICOLON case
    {
        assignment = parseExpression(); //Parse expression rules
        assignment->assign_inst.left_hand_side_index = index; //Assign LHS index
    }
    else if((t1.token_type == ID) | (t1.token_type == NUM)) //ID EQUAL primary SEMICOLON
    {
        int operand1 = parsePrimary(); //Parse primary rules
        assignment = new InstructionNode; //Allocate memory for instruction
        assignment->type = ASSIGN; //Assign assign type
        assignment->assign_inst.left_hand_side_index = index; //Assign LHS index
        assignment->assign_inst.operand1_index = operand1; //Assign operand1 index
        assignment->assign_inst.operand2_index = -1; //No operand2 index
        assignment->assign_inst.op = OPERATOR_NONE; //Assign no operator
        assignment->next = NULL; //Initialize next as NULL
    }
    else //Error case
    {
        syntaxError(); //Print error
    }
    expect(SEMICOLON); //Consume token
    return assignment; //Return assignment instruction
}

/*
 * This function parses expression rules
 */
struct InstructionNode* Parser::parseExpression()
{
    int operand1 = parsePrimary(); //Parse primary rules
    ArithmeticOperatorType arithOp = parseOperator(); //Parse operator rules
    int operand2 = parsePrimary(); //Parse primary rules
    struct InstructionNode* expression = new InstructionNode; //Create new instruction
    expression->type = ASSIGN; //Assign assign type
    expression->assign_inst.operand1_index = operand1; //Assign operand1 index
    expression->assign_inst.operand2_index = operand2; //Assign operand2 index
    expression->assign_inst.op = arithOp; //Assign arithmetic operator
    expression->next = NULL; //Initialize next as NULL
    return expression; //Return expression instruction
}

/*
 * This function parses primary rules
 */
int Parser::parsePrimary()
{
    int index = -1; //Initialize index to return
    Token var; //Initialize var token
    Token t = lexer.peek(1); //Get next token
    switch(t.token_type) //Switch on token
    {
        case ID: //ID case
            var = expect(ID); //Consume token
            index = searchMem(var.lexeme); //Search memory
            break;
        case NUM: //NUM case
            var = expect(NUM); //Consume token
            index = searchMem(var.lexeme); //Search memory
            if(index == -1) //Allocate case
            {
                memMap.insert(pair<string, int>(var.lexeme, next_available)); //Make index mapping
                mem[next_available] = stoi(var.lexeme); //Initialize location value
                index = next_available; //Assign index as current index in mem
                next_available++; //Increment for next location
            }
            break;
        default: //Error case
            syntaxError(); //Print error
            break;
    }
    return index; //Return primary index
}

/*
 * This function parses operator rules
 */
ArithmeticOperatorType Parser::parseOperator()
{
    ArithmeticOperatorType arithOp = OPERATOR_DIV; //Initialize as div
    Token t = lexer.peek(1); //Get next token
    switch(t.token_type)
    {
        case PLUS: //Plus case
            expect(PLUS); //Consume token
            arithOp = OPERATOR_PLUS; //Assign plus
            break;
        case MINUS: //Minus case
            expect(MINUS); //Consume token
            arithOp = OPERATOR_MINUS; //Assign minus
            break;
        case MULT: //Mult case
            expect(MULT); //Consume token
            arithOp = OPERATOR_MULT; //Assign mult
            break;
        case DIV: //Div case
            expect(DIV); //Consume token
            break;
        default: //Error case
            syntaxError(); //Print error
            break;
    }
    return arithOp; //Return arithmetic operator
}

/*
 * This function parses output-statement rules
 */
struct InstructionNode* Parser::parseOutputStatement()
{
    expect(OUTPUT); //Consume token
    Token var = expect(ID); //Consume token
    expect(SEMICOLON); //Consume token
    int index = searchMem(var.lexeme); //Search mem
    struct InstructionNode* output = new InstructionNode; //Create new instruction
    output->type = OUT; //Assign out type
    output->output_inst.var_index = index; //Assign output index
    output->next = NULL; //Initialize next as NULL
    return output; //Return output instruction
}

/*
 * This function parses input-statement rules
 */
struct InstructionNode* Parser::parseInputStatement()
{
    expect(INPUT); //Consume token
    Token var = expect(ID); //Consume token
    expect(SEMICOLON); //Consume token
    int index = searchMem(var.lexeme); //Search mem
    struct InstructionNode* input = new InstructionNode; //Create new instruction
    input->type = IN; //Assign in type
    input->input_inst.var_index = index; //Assign input index
    input->next = NULL; //Initialize next as NULL
    return input; //Return input instruction
}

/*
 * This function parses while-statement rules
 */
struct InstructionNode* Parser::parseWhileStatement()
{
    expect(WHILE); //Consume token
    struct InstructionNode* condition = parseCondition(); //Parse condition rules
    struct InstructionNode* body = parseBody(); //Parse body rules
    struct InstructionNode* iterator = body; //Initialize iterator to head of body
    struct InstructionNode* follower = NULL; //Initialize follower to NULL
    while(iterator != NULL) //Iterate through body to last instruction
    {
        follower = iterator; //Move follower
        iterator = iterator->next; //Iterate
    }
    if(follower == NULL) //Emtpy list case
    {
        return NULL; //Return NULL
    }
    condition->next = body; //Link condition to body
    struct InstructionNode* jump = new InstructionNode; //Create new instruction
    jump->type = JMP; //Assign jmp type
    jump->jmp_inst.target = condition; //Link jump to condition
    follower->next = jump; //Link last in body to jump
    struct InstructionNode* noop = new InstructionNode; //Create new instruction
    noop->type = NOOP; //Assign noop type
    noop->next = NULL; //Initialize next as NULL
    jump->next = noop; //Link jump to noop
    condition->cjmp_inst.target = noop; //Make noop target
    return condition; //Return while instruction list
}

/*
 * This function parses if-statement rules
 */
struct InstructionNode* Parser::parseIfStatement()
{
    expect(IF); //Consume token
    struct InstructionNode* condition = parseCondition(); //Parse condition rules
    struct InstructionNode* body = parseBody(); //Parse body rules
    struct InstructionNode* iterator = body; //Initialize iterator to head of body
    struct InstructionNode* follower = NULL; //Initialize follower to NULL
    while(iterator != NULL) //Iterate through body to last instruction
    {
        follower = iterator; //Move follower
        iterator = iterator->next; //Iterate
    }
    if(follower == NULL) //Empty body case
    {
        return NULL; //Return NULL
    }
    condition->next = body; //Link condition to body
    struct InstructionNode* noop = new InstructionNode; //Create new instruction
    noop->type = NOOP; //Assign noop type
    noop->next = NULL; //Initialize next as NULL
    follower->next = noop; //Link last in body to noop
    condition->cjmp_inst.target = noop; //Link target to noop
    return condition; //Return if instruction list
}

/*
 * This function parses condition rules
 */
struct InstructionNode* Parser::parseCondition()
{
    int operand1 = parsePrimary(); //Parse primary rules
    ConditionalOperatorType condOp = parseRelationalOperator(); //Parse relational-operator rules
    int operand2 = parsePrimary(); //Parse primary rules
    struct InstructionNode* conditional = new InstructionNode; //Create new instruction
    conditional->type = CJMP; //Assign cjmp type
    conditional->cjmp_inst.condition_op = condOp; //Assign conditional operator
    conditional->cjmp_inst.operand1_index = operand1; //Assign operand1 index
    conditional->cjmp_inst.operand2_index = operand2; //Assign operand2 index
    conditional->cjmp_inst.target = NULL; //Initialize target as NULL
    conditional->next = NULL; //Initialize next as NULL
    return conditional; //Return conditional instruction
}

/*
 * This function parses relational-operator rules
 */
ConditionalOperatorType Parser::parseRelationalOperator()
{
    ConditionalOperatorType condOp = CONDITION_NOTEQUAL; //Initialize as notequal
    Token t = lexer.peek(1); //Check next token
    switch(t.token_type) //Switch on token
    {
        case GREATER: //Greater case
            expect(GREATER); //Consume token
            condOp = CONDITION_GREATER; //Assign greater
            break;
        case LESS: //Less case
            expect(LESS); //Consume token
            condOp = CONDITION_LESS; //Assign less
            break;
        case NOTEQUAL: //Notequal case
            expect(NOTEQUAL); //Consume token
            break;
        default: //Error case
            syntaxError(); //Print error
            break;
    }
    return condOp; //Return conditional operator
}

/*
 * This function parses switch-statement rules
 */
struct InstructionNode* Parser::parseSwitchStatement()
{
    expect(SWITCH); //Consume token
    Token var = expect(ID); //Consume token
    expect(LBRACE); //Consume token
    struct InstructionNode* conditionList = parseCaseList(var); //Parse case-list rules
    struct InstructionNode* iterator = conditionList; //Initialize iterator to head of condition list
    struct InstructionNode* follower = NULL; //Initialize follower to NULL
    while(iterator != NULL) //Iterate to last condition
    {
        follower = iterator; //Move follower
        iterator = iterator->next; //Iterate
    }
    if(follower == NULL) //Empty list case
    {
        return NULL; //Return NULL
    }
    struct InstructionNode* noop = new InstructionNode; //Create new instruction
    noop->type = NOOP; //Assign noop type
    noop->next = NULL; //Initialize next as NULL
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == DEFAULT) //Default case
    {
        struct InstructionNode* defaultList = parseDefaultCase(); //Parse default-case rules
        follower->next = defaultList; //Link last condition to default list
        iterator = defaultList; //Reset iterator
        follower = NULL; //Reset follower
        while(iterator != NULL) //Iterate to last instruction
        {
            follower = iterator; //Move follower
            iterator = iterator->next; //Iterate
        }
        if(follower == NULL) //Empty list case
        {
            return NULL; //Return NULL
        }
    }
    follower->next = noop; //Link end of default to noop
    expect(RBRACE); //Consume token
    iterator = conditionList; //Reset iterator
    while((iterator != NULL) && (iterator->type == CJMP)) //Iterate and point last of bodies to noop
    {
        struct InstructionNode* bodyIterator = iterator->cjmp_inst.target; //Initialize iterator to head of body
        follower = NULL; //Reset follower
        while(bodyIterator != NULL) //Iterate body and point last to noop
        {
            follower = bodyIterator; //Move follower
            bodyIterator = bodyIterator->next; //Iterate
        }
        if(follower == NULL) //Empty list case
        {
            return NULL; //Return NULL
        }
        follower->next = noop; //Link last of body to noop
        iterator = iterator->next; //Iterate
    }
    return conditionList; //Return switch instruction list
}

/*
 * This function parses for-statement rules
 */
struct InstructionNode* Parser::parseForStatement()
{
    expect(FOR); //Consume token
    expect(LPAREN); //Consume token
    struct InstructionNode* init = parseAssignStatement(); //Parse assign-statement rules
    struct InstructionNode* condition = parseCondition(); //Parse condition rules
    expect(SEMICOLON); //Consume token
    struct InstructionNode* iterate = parseAssignStatement(); //Parse assign-statement rules
    expect(RPAREN); //Consume token
    struct InstructionNode* body = parseBody(); //Parse body rules
    struct InstructionNode* iterator = body; //Initialize iterator to head of body
    struct InstructionNode* follower = NULL; //Initialize follower to NULL
    while(iterator != NULL) //Iterate through body to last instruction
    {
        follower = iterator; //Move follower
        iterator = iterator->next; //Iterate
    }
    if(follower == NULL) //Empty list case
    {
        return NULL; //Return NULL
    }
    init->next = condition; //Link init to condition
    condition->next = body; //Link condition to body
    follower->next = iterate; //Link last in body to iterate
    struct InstructionNode* jump = new InstructionNode; //Create new instruction
    jump->type = JMP; //Assign jmp type
    jump->jmp_inst.target = condition; //Link jump to condition
    iterate->next = jump;
    struct InstructionNode* noop = new InstructionNode; //Create new instruction
    noop->type = NOOP; //Assign noop type
    noop->next = NULL; //Initialize next as NULL
    jump->next = noop; //Link jump to noop
    condition->cjmp_inst.target = noop; //Make noop target
    return init; //Return for instruction list
}

/*
 * This function parses case-list rules
 */
struct InstructionNode* Parser::parseCaseList(Token var)
{
    struct InstructionNode* condition1 = parseCase(var); //Parse case rules
    struct InstructionNode* recCondition = NULL; //Initialize recursive conditions as NULL
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == CASE) //Recursive case
    {
        recCondition = parseCaseList(var); //Parse case-list rules
    }
    condition1->next = recCondition; //Link condition1 to recursive conditions
    return condition1; //Return condition instruction list
}

/*
 * This function parses case rules
 */
struct InstructionNode* Parser::parseCase(Token var)
{
    expect(CASE); //Consume token
    Token num = expect(NUM); //Consume token
    int index1 = searchMem(var.lexeme); //Search mem
    int index2 = searchMem(num.lexeme); //Search mem
    if(index2 == -1) //Allocate case
    {
        memMap.insert(pair<string, int>(num.lexeme, next_available)); //Make index mapping
        mem[next_available] = stoi(num.lexeme); //Assign value to index
        index2 = next_available; //Set index to current mem index
        next_available++; //Increment for next location
    }
    expect(COLON); //Consume token
    struct InstructionNode* caseBody = parseBody(); //Parse body rules
    struct InstructionNode* condition = new InstructionNode; //Create new instruction
    condition->type = CJMP; //Assign cjmp type
    condition->cjmp_inst.condition_op = CONDITION_NOTEQUAL; //Assign notequal conditional operator
    condition->cjmp_inst.operand1_index = index1; //Assign operand1 index
    condition->cjmp_inst.operand2_index = index2; //Assign operand2 index
    condition->cjmp_inst.target = caseBody; //Make case body target
    condition->next = NULL; //Initialize next as NULL
    return condition; //Return case instruction list
}

/*
 * This function parses default-case rules
 */
struct InstructionNode* Parser::parseDefaultCase()
{
    expect(DEFAULT); //Consume token
    expect(COLON); //Consume token
    struct InstructionNode* caseBody = parseBody(); //Parse body rules
    struct InstructionNode* noop = new InstructionNode; //Create new instruction
    noop->type = NOOP; //Assign noop type
    noop->next = caseBody; //Link noop to case body
    return noop; //Return default instruction list
}

/*
 * This function parses inputs rules
 */
void Parser::parseInputs()
{
    parseNumList(); //Parse num-list rules
    return; //Return from function
}

/*
 * This function parses num-list rules
 */
void Parser::parseNumList()
{
    Token num = expect(NUM); //Consume token
    inputs.push_back(stoi(num.lexeme)); //Add input value to input vector
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == NUM) //Recursive case
    {
        parseNumList(); //Parse num-list rules
    }
    return; //Return from function
}