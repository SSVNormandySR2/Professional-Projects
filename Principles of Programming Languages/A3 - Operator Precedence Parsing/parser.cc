/*
 * Vincent Latona
 */

#include "parser.h"

using namespace std;

/*
 * This constructor instantiates a parser object
 */
Parser::Parser()
{
    first = NULL; //Initialize tree pointer
    errCount = 0; //Initialize error counter
    TokenType symbols[12] = {PLUS, MINUS, MULT, DIV, LPAREN, RPAREN,
                             LBRAC, DOT, RBRAC, NUM, ID, END_OF_FILE}; //Symbol array for mapping
    for(int a = 0; a < 12; a++) //Iterate through symbols and map to ints
    {
        binding.insert(pair<TokenType, int>(symbols[a], a)); //Bind token to int
    }
    /*
     * Initialize precedence table
     */
    table[0][0] = ">";
    table[0][1] = ">";
    table[0][2] = "<";
    table[0][3] = "<";
    table[0][4] = "<";
    table[0][5] = ">";
    table[0][6] = "<";
    table[0][7] = "err";
    table[0][8] = ">";
    table[0][9] = "<";
    table[0][10] = "<";
    table[0][11] = ">";
    table[1][0] = ">";
    table[1][1] = ">";
    table[1][2] = "<";
    table[1][3] = "<";
    table[1][4] = "<";
    table[1][5] = ">";
    table[1][6] = "<";
    table[1][7] = "err";
    table[1][8] = ">";
    table[1][9] = "<";
    table[1][10] = "<";
    table[1][11] = ">";
    table[2][0] = ">";
    table[2][1] = ">";
    table[2][2] = ">";
    table[2][3] = ">";
    table[2][4] = "<";
    table[2][5] = ">";
    table[2][6] = "<";
    table[2][7] = "err";
    table[2][8] = ">";
    table[2][9] = "<";
    table[2][10] = "<";
    table[2][11] = ">";
    table[3][0] = ">";
    table[3][1] = ">";
    table[3][2] = ">";
    table[3][3] = ">";
    table[3][4] = "<";
    table[3][5] = ">";
    table[3][6] = "<";
    table[3][7] = "err";
    table[3][8] = ">";
    table[3][9] = "<";
    table[3][10] = "<";
    table[3][11] = ">";
    table[4][0] = "<";
    table[4][1] = "<";
    table[4][2] = "<";
    table[4][3] = "<";
    table[4][4] = "<";
    table[4][5] = "=";
    table[4][6] = "<";
    table[4][7] = "err";
    table[4][8] = "<";
    table[4][9] = "<";
    table[4][10] = "<";
    table[4][11] = "err";
    table[5][0] = ">";
    table[5][1] = ">";
    table[5][2] = ">";
    table[5][3] = ">";
    table[5][4] = "err";
    table[5][5] = ">";
    table[5][6] = ">";
    table[5][7] = "err";
    table[5][8] = ">";
    table[5][9] = "err";
    table[5][10] = "err";
    table[5][11] = ">";
    table[6][0] = "<";
    table[6][1] = "<";
    table[6][2] = "<";
    table[6][3] = "<";
    table[6][4] = "<";
    table[6][5] = "<";
    table[6][6] = "<";
    table[6][7] = "=";
    table[6][8] = "=";
    table[6][9] = "<";
    table[6][10] = "<";
    table[6][11] = "err";
    table[7][0] = "err";
    table[7][1] = "err";
    table[7][2] = "err";
    table[7][3] = "err";
    table[7][4] = "err";
    table[7][5] = "err";
    table[7][6] = "err";
    table[7][7] = "err";
    table[7][8] = "=";
    table[7][9] = "err";
    table[7][10] = "err";
    table[7][11] = "err";
    table[8][0] = ">";
    table[8][1] = ">";
    table[8][2] = ">";
    table[8][3] = ">";
    table[8][4] = "err";
    table[8][5] = ">";
    table[8][6] = ">";
    table[8][7] = "err";
    table[8][8] = ">";
    table[8][9] = "err";
    table[8][10] = "err";
    table[8][11] = ">";
    table[9][0] = ">";
    table[9][1] = ">";
    table[9][2] = ">";
    table[9][3] = ">";
    table[9][4] = "err";
    table[9][5] = ">";
    table[9][6] = ">";
    table[9][7] = "err";
    table[9][8] = ">";
    table[9][9] = "err";
    table[9][10] = "err";
    table[9][11] = ">";
    table[10][0] = ">";
    table[10][1] = ">";
    table[10][2] = ">";
    table[10][3] = ">";
    table[10][4] = "err";
    table[10][5] = ">";
    table[10][6] = ">";
    table[10][7] = "err";
    table[10][8] = ">";
    table[10][9] = "err";
    table[10][10] = "err";
    table[10][11] = ">";
    table[11][0] = "<";
    table[11][1] = "<";
    table[11][2] = "<";
    table[11][3] = "<";
    table[11][4] = "<";
    table[11][5] = "err";
    table[11][6] = "<";
    table[11][7] = "err";
    table[11][8] = "err";
    table[11][9] = "<";
    table[11][10] = "<";
    table[11][11] = "acc";
}

/*
 * This function returns the token type of the top terminal
 */
Token Parser::terminalPeek()
{
    struct stackNode top = expr.top(); //Get top of stack
    if(top.type == TERM) //Terminal case
    {
        return top.token; //Return token type of terminal
    }
    else //EXPR case
    {
        expr.pop(); //Next node is terminal
        struct stackNode newTop = expr.top(); //Get terminal
        expr.push(top); //Reinsert original top
        return newTop.token; //Return token type of terminal
    }
}

/*
 * This function checks the table for an entry
 */
int Parser::searchTable(TokenType check)
{
    auto index = binding.find(check); //Search table
    if(index == binding.end()) //No entry case
    {
        return -1; //Return -1 for no entry
    }
    return index->second; //Return index
}

/*
 * This function checks for a map
 */
dataType Parser::searchType(string lexeme)
{
    auto type = typeMap.find(lexeme); //Search map
    if(type == typeMap.end()) //No entry case
    {
        return error; //Error case
    }
    return type->second; //Return data type
}

/*
 * This function parses tokens
 */
Token Parser::expect(TokenType expected)
{
    Token t = lexer.GetToken(); //Get current token
    if(t.token_type != expected) //Invalid case
    {
        syntaxError(); //Print error
    }
    return t; //Return valid token
}

/*
 * This function determines if EOF is present
 */
bool Parser::EOFpeek()
{
    bool peek = false; //Boolean to return
    Token t1 = lexer.peek(1); //Check next token
    Token t2 = lexer.peek(2); //Check 2nd token
    if((t1.token_type == RBRAC) & (t2.token_type == EQUAL)) //Bracket case
    {
        peek = true; //Make true
    }
    else if(t1.token_type == EQUAL) //Equal case
    {
        peek = true; //Make true
    }
    else if(t1.token_type == SEMICOLON) //Semicolon case
    {
        peek = true; //Make true
    }
    return peek; //Return boolean
}

/*
 * This function prints syntax error
 */
void Parser::syntaxError()
{
    cout << "SNYATX EORRR !!!\n"; //Print error
    errCount++; //Increment error count
    exit(1); //Exit program
}

/*
 * This function parses the given input
 */
void Parser::parseInput()
{
    parseProgram(); //Parse program rules
    expect(END_OF_FILE); //Consume token
    return; //Return from function
}

/*
 * This function parses program rules
 */
void Parser::parseProgram()
{
    parseDeclarationSection(); //Parse declaration section rules
    parseBlock(); //Parse block rules
    return; //Return from function
}

/*
 * This function parses declaration section rules
 */
void Parser::parseDeclarationSection()
{
    parseScalarDeclarationSection(); //Parse scalar-declaration section rules
    parseArrayDeclarationSection(); //Parse array-declaration section rules
    return; //Return from function
}

/*
 * This function parses scalar-declaration section rules
 */
void Parser::parseScalarDeclarationSection()
{
    expect(SCALAR); //Consume token
    parseIDList(scalar); //Parse id-list rules
    return; //Return from function
}

/*
 * This function parses array-declaration section rules
 */
void Parser::parseArrayDeclarationSection()
{
    expect(ARRAY); //Consume token
    parseIDList(arraydecl); //Parse id-list rules
    return; //Return from function
}

/*
 * This function parses id-list rules
 */
void Parser::parseIDList(dataType given)
{
    Token parsed = expect(ID); //Consume token
    typeMap.insert(pair<string, dataType>(parsed.lexeme, given));
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == ID) //Recursive case
    {
        parseIDList(given); //Parse id-list rules
    }
    return; //Return from function
}

/*
 * This function parses block rules
 */
void Parser::parseBlock()
{
    expect(LBRACE); //Consume token
    parseStatementList(); //Parse statement list rules
    expect(RBRACE); //Consume token
    return; //Return from function
}

/*
 * This function parses statement list rules
 */
void Parser::parseStatementList()
{
    parseStatement(); //Parse statement rules
    Token t = lexer.peek(1); //Check next token
    if((t.token_type == ID) | (t.token_type == OUTPUT)) //Recursive case
    {
        parseStatementList(); //Parse statement list rules
    }
    return; //Return from function
}

/*
 * This function parses statement rules
 */
void Parser::parseStatement()
{
    Token t = lexer.peek(1); //Check next token
    if(t.token_type == ID) //Assign case
    {
        parseAssignStatement(); //Parse assign statement rules
    }
    else if(t.token_type == OUTPUT) //Output case
    {
        parseOutputStatement(); //Parse output statement rules
    }
    else //Error case
    {
        syntaxError(); //Print error
    }
    return; //Return from function
}

/*
 * This function parses assign statement rules
 */
void Parser::parseAssignStatement()
{
    struct treeNode* root = NULL; //Syntax tree root
    struct treeNode* left = parseVariableAccess(); //Parse variable-access rules
    expect(EQUAL); //Consume token
    struct treeNode* right = parseExpression(); //Parse expression rules
    expect(SEMICOLON); //Consume token
    if((left != NULL) & (right != NULL))
    {
        root = new treeNode; //Instantiate tree node
        root->left = left; //Assign left node
        root->right = right; //Assign right node
        root->lexeme = ""; //No lexeme
        root->op = "="; //Assign =
    }
    if(treeParse == 0) //First statement case
    {
        first = root; //Assign root to global tree
        treeParse++; //Prevent multiple trees
    }
    if(right->data == error) //Error case
    {
        expressionErrors.push_back(right->line); //Add fault line
    }
    else if((left->data == error) | (right->data == error)) //Error case
    {
        expressionErrors.push_back(left->line); //Add fault line
    }
    else if(!(left->data == arraytype) & !(right->data == scalar)) //Error case
    {
        assignmentErrors.push_back(left->line); //Add fault line
    }
    return; //Return from function
}

/*
 * This function parses output statement rules
 */
void Parser::parseOutputStatement()
{
    expect(OUTPUT); //Consume token
    parseVariableAccess(); //Parse variable-access rules
    expect(SEMICOLON); //Consume token
    return; //Return from function
}

/*
 * This function parses a variable-access rules
 */
struct treeNode* Parser::parseVariableAccess()
{
    Token t1 = lexer.peek(1); //Check next token
    Token t2 = lexer.peek(2); //Check 2nd token
    Token t3 = lexer.peek(3); //Check 3rd token
    treeNode* root = NULL; //Tree root to return
    if((t1.token_type == ID) & (t2.token_type == LBRAC) & (t3.token_type == DOT)) //ID[.] case
    {
        Token t = expect(ID); //Consume token
        expect(LBRAC); //Consume token
        expect(DOT); //Consume token
        expect(RBRAC); //Consume token
        root = new treeNode; //Instantiate tree
        treeNode* center = new treeNode; //Instantiate left node
        center->left = NULL; //Nullify children
        center->center = NULL;
        center->right = NULL;
        center->lexeme = "\"" + t.lexeme + "\""; //Assign lexeme
        center->op = "ID"; //Assign ID
        center->data = searchType(t.lexeme); //Assign data type
        center->line = t.line_no; //Assign line num
        root->left = NULL; //Nullify children
        root->center = center; //Assign center node
        root->right = NULL;
        root->lexeme = ""; //No lexeme
        root->op = "[.]"; //Assign [.]
        if(searchType(t.lexeme) == arraydecl) //Valid case
        {
            root->data = arraytype; //Assign arraytype
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = t.line_no; //Assign line num
    }
    else if((t1.token_type == ID) & (t2.token_type == LBRAC)) //ID[expr] case
    {
        Token t = expect(ID); //Consume token
        expect(LBRAC); //Consume token
        treeNode* right = parseExpression(); //Parse expression rules
        expect(RBRAC); //Consume token
        root = new treeNode; //Instantiate tree
        treeNode* left = new treeNode; //Instantiate left node
        left->left = NULL; //Nullify children
        left->center = NULL;
        left->right = NULL;
        left->lexeme = "\"" + t.lexeme + "\""; //Assign lexeme
        left->op = "ID"; //Assign ID
        left->data = searchType(t.lexeme); //Assign data type
        left->line = t.line_no; //Assign line num
        root->left = left; //Assign left node
        root->center = NULL; //Nullify child
        root->right = right; //Assign right node
        root->lexeme = ""; //No lexeme
        root->op = "[]"; //Assign []
        if((searchType(t.lexeme) == arraydecl) & (right->data == scalar)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = t.line_no; //Assign line num
    }
    else if((t1.token_type == ID) & ((t2.token_type == EQUAL) | (t2.token_type == SEMICOLON))) //ID case
    {
        Token t = expect(ID); //Consume token
        root = new treeNode; //Instantiate tree
        root->left = NULL; //Nullify children
        root->center = NULL;
        root->right = NULL;
        root->lexeme = "\"" + t.lexeme + "\""; //Assign lexeme
        root->op = "ID"; //Assign ID
        if(searchType(t.lexeme) == scalar) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = t.line_no; //Assign line num
    }
    else //Error case
    {
        syntaxError(); //Print error
    }
    if(errCount == 0) //Valid parse case
    {
        return root; //Return variable-access tree
    }
    else //Invalid parse case
    {
        return NULL; //Return NULL
    }
}

/*
 * This function parses expression rules
 */
struct treeNode* Parser::parseExpression()
{

    bool done = false; //Sentinel to parse operator grammar
    Token t; //Instantiate EOF token
    t.token_type = END_OF_FILE;
    t.lexeme = "$";
    struct stackNode eof; //Instantiate bottom of stack node
    eof.type = TERM; //Assign TERM type
    eof.token = t; //Assign token
    eof.root = NULL; //Nullify tree
    expr.push(eof); //Push EOF onto stack pre-emptively
    struct treeNode* root = NULL; //Tree root to return
    while(!done) //Parse the operator grammar
    {
        bool completed = EOFpeek(); //Check for EOF
        if((completed) & (terminalPeek().token_type == END_OF_FILE)) //Finished case
        {
            done = true; //Parsing complete
            if(expr.top().type == EXPR) //Expression return case
            {
                root = expr.top().root; //Assign root of expression
                expr.pop(); //Pop stack
            }
            break; //Break operator parser
        }
        else
        {
            TokenType input = lexer.peek(1).token_type; //Check next token type
            if(EOFpeek()) //EOF symbol reached
            {
                input = END_OF_FILE; //Switch to EOF to reduce and terminate
            }
            int a = searchTable(terminalPeek().token_type); //Addr of top of stack entry
            int b = searchTable(input); //Addr of input entry
            if((a > -1) & (b > -1)) //Valid index case
            {
                if((table[a][b] == "<") | (table[a][b] == "=")) //Shift case
                {
                    Token t = lexer.GetToken(); //Get token
                    struct stackNode node; //Instantiate new node to add
                    node.type = TERM; //Assign TERM type
                    node.token = t; //Assign token
                    node.root = NULL; //Nullify tree
                    expr.push(node); //Insert new node
                }
                else if(table[a][b] == ">") //Find reduction case
                {
                    string eval = "";
                    struct stackNode lastPoppedTerm; //Last popped terminal
                    bool last = false; //Boolean for last popped instantiation
                    bool reducer = false; //Sentinel for reduction loop
                    while(!reducer) //Reduction loop
                    {
                        if((expr.top().type == TERM) & (a > -1) & (b > -1) & (table[a][b] == "<")) //Termination case
                        {
                            reducer = true; //Reduction complete
                            break; //Break reduction loop
                        }
                        struct stackNode s = expr.top(); //Get expression elements
                        expr.pop(); //Pop off of expr stack
                        if(s.type == TERM) //Terminal case
                        {
                            last = true;
                            lastPoppedTerm = s; //Set last popped terminal for loop evaluation
                            switch(lastPoppedTerm.token.token_type) //Format string for reduction
                            {
                                case ID:
                                    eval = "id" + eval; //ID case
                                    break;
                                case NUM:
                                    eval = "num" + eval; //NUM case
                                    break;
                                case LBRAC:
                                    eval = "[" + eval; //LBRAC case
                                    break;
                                case RBRAC:
                                    eval = "]" + eval; //RBRAC case
                                    break;
                                case DOT:
                                    eval = "." + eval; //DOT case
                                    break;
                                case LPAREN:
                                    eval = "(" + eval; //LPAREN case
                                    break;
                                case RPAREN:
                                    eval = ")" + eval; //RPAREN case
                                    break;
                                case PLUS:
                                    eval = "+" + eval; //PLUS case
                                    break;
                                case MINUS:
                                    eval = "-" + eval; //MINUS case
                                    break;
                                case MULT:
                                    eval = "*" + eval; //MULT case
                                    break;
                                case DIV:
                                    eval = "/" + eval; //DIV case
                                    break;
                                default:
                                    eval = "error";
                                    break;
                            }
                        }
                        else
                        {
                            eval = "expr" + eval; //E case
                        }
                        reductionStack.push(s); //Push node onto reduction stack
                        if(last) //Possible reduction case
                        {
                            a = searchTable(terminalPeek().token_type); //Find index of next terminal
                            b = searchTable(lastPoppedTerm.token.token_type); //Find index of last popped terminal
                        }
                    }
                    struct stackNode newExpr = reduce(eval); //Reduce expression
                    if(newExpr.type == TERM) //Invalid expression case
                    {
                        syntaxError(); //Print error
                        done = true; //Break sentinel
                        break; //Break loop
                    }
                    expr.push(newExpr); //Push reduced expression
                }
                else //Error case
                {
                    syntaxError(); //Print error
                }
            }
            else //Invalid index case
            {
                return NULL; //Return NULL for error
            }
        }
    }
    return root; //Return from function
}

/*
 * This function reduces a given expression string
 */
struct stackNode Parser::reduce(string evaluate)
{
    if(evaluate == "id") //E->ID
    {
        struct stackNode t = reductionStack.top(); //Get ID node
        reductionStack.pop(); //Pop ID node
        dataType type = searchType(t.token.lexeme); //Get type
        struct treeNode* root = new treeNode; //Instantiate tree node
        root->left = NULL; //Nullify children
        root->center = NULL;
        root->right = NULL;
        root->op = "ID"; //Assign ID
        root->lexeme = "\"" + t.token.lexeme + "\""; //Assign lexeme
        root->data = type; //Assign data type
        root->line = t.token.line_no; //Assign line num
        t.type = EXPR; //Change node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "num") //E->NUM
    {
        struct stackNode t = reductionStack.top(); //Get NUM node
        reductionStack.pop(); //Pop NUM node
        struct treeNode* root = new treeNode; //Instantiate tree node
        root->left = NULL; //Nullify children
        root->center = NULL;
        root->right = NULL;
        root->op = "NUM"; //Assign NUM
        root->lexeme = "\"" + t.token.lexeme + "\""; //Assign lexeme
        root->data = scalar; //Assign scalar type
        root->line = t.token.line_no; //Assign line num
        t.type = EXPR; //Change node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr[.]") //E->E[.]
    {
        struct stackNode t; //Expression node to return
        struct stackNode expr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E node
        reductionStack.pop(); //Pop [
        reductionStack.pop(); //Pop .
        reductionStack.pop(); //Pop ]
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = NULL; //Nullify unused children
        root->center = expr.root; //Assign expression tree to center node
        root->right = NULL;
        root->lexeme = ""; //No lexeme
        root->op = "[.]"; //Assign [.]
        if(expr.root->data == arraydecl) //Array case
        {
            root->data = arraytype; //Assign arraytype
        }
        else if(expr.root->data == scalar) //Array case
        {
            root->data = arraytype; //Assign arraytype
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = expr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr[expr]") //E->E[E]
    {
        struct stackNode t; //Expression node to return
        struct stackNode leftExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop [
        struct stackNode rightExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop ]
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = leftExpr.root; //Assign left expression tree to left node
        root->center = NULL; //Nullify unused nodes
        root->right = rightExpr.root; //Assign right expression tree to right node
        root->lexeme = ""; //No lexeme
        root->op = "[]"; //Assign
        if(rightExpr.root->data == scalar) //Possible valid
        {
            if(leftExpr.root->data == arraydecl) //Valid case
            {
                root->data = scalar; //Assign scalar
            }
            else if(leftExpr.root->data == arraytype) //Valid case
            {
                root->data = scalar; //Assign scalar
            }
            else //Error case
            {
                root->data = error; //Assign error
            }
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = leftExpr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "(expr)") //E->(E)
    {
        struct stackNode t; //Expression node to return
        reductionStack.pop(); //Pop (
        struct stackNode expr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop )
        t.type = EXPR; //Assign node type
        t.root = expr.root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr+expr") //E->E+E
    {
        struct stackNode t; //Expression node to return
        struct stackNode leftExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop +
        struct stackNode rightExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = leftExpr.root; //Assign left expression tree to left node
        root->center = NULL; //Nullify unused nodes
        root->right = rightExpr.root; //Assign right expression tree to right node
        root->lexeme = ""; //No lexeme
        root->op = "+"; //Assign +
        if((leftExpr.root->data == scalar) & (rightExpr.root->data == scalar)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else if((leftExpr.root->data == arraytype) & (rightExpr.root->data == arraytype)) //Valid case
        {
            root->data = arraytype; //Assign arraytype
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = leftExpr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr-expr") //E->E-E
    {
        struct stackNode t; //Expression node to return
        struct stackNode leftExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop -
        struct stackNode rightExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = leftExpr.root; //Assign left expression tree to left node
        root->center = NULL; //Nullify unused nodes
        root->right = rightExpr.root; //Assign right expression tree to right node
        root->lexeme = ""; //No lexeme
        root->op = "-"; //Assign -
        if((leftExpr.root->data == scalar) & (rightExpr.root->data == scalar)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else if((leftExpr.root->data == arraytype) & (rightExpr.root->data == arraytype)) //Valid case
        {
            root->data = arraytype; //Assign arraytype
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = leftExpr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr*expr") //E->E*E
    {
        struct stackNode t; //Expression node to return
        struct stackNode leftExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop *
        struct stackNode rightExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = leftExpr.root; //Assign left expression tree to left node
        root->center = NULL; //Nullify unused nodes
        root->right = rightExpr.root; //Assign right expression tree to right node
        root->lexeme = ""; //No lexeme
        root->op = "*"; //Assign *
        if((leftExpr.root->data == scalar) & (rightExpr.root->data == scalar)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else if((leftExpr.root->data == arraytype) & (rightExpr.root->data == arraytype)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = leftExpr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else if(evaluate == "expr/expr") //E->E/E
    {
        struct stackNode t; //Expression node to return
        struct stackNode leftExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        reductionStack.pop(); //Pop /
        struct stackNode rightExpr = reductionStack.top(); //Get expression node
        reductionStack.pop(); //Pop E
        struct treeNode* root = new treeNode; //Instantiate tree for expression
        root->left = leftExpr.root; //Assign left expression tree to left node
        root->center = NULL; //Nullify unused nodes
        root->right = rightExpr.root; //Assign right expression tree to right node
        root->lexeme = ""; //No lexeme
        root->op = "/"; //Assign /
        if((leftExpr.root->data == scalar) & (rightExpr.root->data == scalar)) //Valid case
        {
            root->data = scalar; //Assign scalar
        }
        else //Error case
        {
            root->data = error; //Assign error
        }
        root->line = leftExpr.root->line; //Assign line num
        t.type = EXPR; //Assign node type
        t.root = root; //Assign tree
        return t; //Return expression
    }
    else //Error case
    {
        struct stackNode invalid; //Instantiate invalid node
        invalid.type = TERM; //Mark as term
        invalid.root = NULL; //Nullify tree
        return invalid; //Return invalid node
    }
}

/*
 * This function prints the abstract syntax tree produced on the first assignment
 */
void Parser::printTree() {
    if ((errCount == 0) & (first != NULL)) //Valid tree-print case
    {
        queue<struct treeNode *> bfsQueue; //Queue for tree nodes
        bfsQueue.push(first); //Insert syntax tree root
        while (!bfsQueue.empty()) //BFS print
        {
            struct treeNode *current = bfsQueue.front(); //Get front element
            if (current->left != NULL) //Valid left case
            {
                bfsQueue.push(current->left); //Insert left to be printed
            }
            if (current->center != NULL) //Valid center case
            {
                bfsQueue.push(current->center); //Insert center to be printed
            }
            if (current->right != NULL) //Valid right case
            {
                bfsQueue.push(current->right); //Insert right to be printed
            }
            bfsQueue.pop(); //Remove current from queue
            cout << current->op << " ";
            if (current->lexeme != "") //Lexeme case
            {
                cout << current->lexeme << " "; //Print lexeme
            }
        }
        cout << endl; //New line to terminate
    }
    return; //Return from function
}

/*
 * This function displays type checking
 */
void Parser::typeCheck()
{
    if(errCount == 0) //Type check case
    {
        if(!expressionErrors.empty()) //Expression errors case
        {
            cout << "Expression type error :(\n\n"; //Print error indicator
            for(int line : expressionErrors) //Print lines
            {
                cout << "Line " << line << endl; //Print error line
            }
        }
        else if(!assignmentErrors.empty()) //Assignment errors case
        {
            cout << "Invalid assignment :(\n\n"; //Print error indicator
            for(int line : assignmentErrors) //Print lines
            {
                cout << "Line " << line << endl; //Print error line
            }
        }
        else //No error case
        {
            cout << "No type errors here :)\n"; //Print success
        }
    }
    return; //Return from function
}