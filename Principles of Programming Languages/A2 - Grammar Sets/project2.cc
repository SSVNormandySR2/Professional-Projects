/*
 * Vincent Latona
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lexer.h"
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

//Struct for rules
struct rule
{
    string LHS; //LHS symbol of rule
    vector<string> RHS;
};

//Global variables
vector<rule*> givenGrammar;
vector<string> nonterminals;
vector<string> terminals;
map<string, int> firstSetMap;
map<string, int> followSetMap;
vector<set<string>> firstSets;
vector<set<string>> followSets;
int givenRuleCount = 0;
int usefulRuleCount = 0;
LexicalAnalyzer lexer;

//Function forward declarations
Token expect(TokenType expected_type);
void syntax_error();
void readGrammar();
void parseGrammar();
void parseRuleList();
vector<string> parseIDList();
rule* parseRule();
vector<string> parseRHS();
void calculateTerminalsAndNonTerminals();
vector<rule*> removeUselessSymbols();
vector<rule*> calculateGenerating();
vector<rule*> calculateReachable(vector<rule*>);
void calculateFirstSets();
void initializeFirsts();
void calculateFollowSets();
void initializeFollows();
void checkIfGrammarHasPredictiveParser();
void printSymbols();
void printGrammar(vector<rule*>);
void printFirstSets();
void printFollowSets();

/*
 * This function gets a token and determines if valid
 */
Token expect(TokenType expected_type)
{
    Token t = lexer.GetToken(); //Get token
    if(t.token_type != expected_type) //Error case
    {
        syntax_error(); //Print error
    }
    return t; //Return token
}

/*
 * This function prints syntax error for parsing errors
 */
void syntax_error()
{
    cout << "SYNTAX ERROR !!!\n"; //Print syntax error
    exit(1);
}

/*
 * This function starts to parse the input grammar
 */
void readGrammar()
{
    parseGrammar(); //Parse rule
    expect(END_OF_FILE); //Consume token
    return; //Return from function
}

/*
 * This function parses
 */
void parseGrammar()
{
    parseRuleList(); //Parse rule
    expect(HASH); //Consume token
    return; //Return from function
}

/*
 * This function parses a rule list
 */
void parseRuleList()
{
    rule* grammarRule = parseRule(); //Parse rule
    givenGrammar.push_back(grammarRule); //Add grammar rule to list of rules
    givenRuleCount++; //Increment overall rule count
    Token t = lexer.peek(1); //Peek next token
    if(t.token_type == ID) //Check recursive case
    {
        parseRuleList(); //Parse recursive rule
    }
    else if(t.token_type == HASH) //Check follow case
    {
    }
    else //Error case
    {
        syntax_error(); //Print error
    }
    return; //Return from function
}

/*
 * This function parses an id list
 */
vector<string> parseIDList()
{
    Token RHSsymbol = expect(ID); //Consume token
    vector<string> RHSsymbols; //Vector for strings of RHS
    RHSsymbols.push_back(RHSsymbol.lexeme); //Add first string to RHS
    Token t = lexer.peek(1); //Peek next token
    if(t.token_type == ID) //Check recursive case
    {
        vector<string> remainingRHSsymbols = parseIDList(); //Parse recursive rule
        for(string symbol : remainingRHSsymbols) //Iterate through recursive vector
        {
            RHSsymbols.push_back(symbol); //Add recursive symbols to complete vector
        }
    }
    else if(t.token_type == STAR) // Check follow case
    {
    }
    else //Error case
    {
        syntax_error(); //Print error
    }
    return RHSsymbols; //Return symbols of RHS
}

/*
 * This function parses a rule
 */
rule* parseRule()
{
    Token LHS = expect(ID); //Consume token
    expect(ARROW); //Consume token
    vector<string> RHS = parseRHS(); //Parse rule
    expect(STAR); //Consume token
    rule* grammarRule = new rule; //Create rule struct and instantiate data
    grammarRule->LHS = LHS.lexeme;
    grammarRule->RHS = RHS;
    return grammarRule; //Return rule struct
}

/*
 * This function parses a RHS
 */
vector<string> parseRHS()
{
    Token t = lexer.peek(1); //Peek next token
    vector<string> RHS; //Vector for strings of RHS
    if(t.token_type == ID) //Check parse case
    {
        RHS = parseIDList(); //Parse rule
    }
    else if(t.token_type == STAR) //Check follow case
    {
        RHS.push_back("#"); //Add epsilon to RHS
    }
    else //Error case
    {
        syntax_error(); //Print error
    }
    return RHS; //Return RHS of rule
}

/*
 * This function prints the Terminals and Non-Terminals
 */
void calculateTerminalsAndNonTerminals()
{
    vector<string> unsortedNonterminals; //Vector to store nonterminals of first pass
    for(rule* rule : givenGrammar) //First pass of nonterminals, unsorted
    {
        unsortedNonterminals.push_back(rule->LHS); //Add LHS nonterminals to unsorted list
    }
    for(rule* rule : givenGrammar) //Second pass of nonterminals and terminals
    {
        auto it = find(nonterminals.begin(), nonterminals.end(), rule->LHS); //Search for LHS in sorted list
        if(it == nonterminals.end()) //Add case
        {
            nonterminals.push_back(rule->LHS); //Add nonterminal to sorted list
        }
        for(string symbol : rule->RHS) //Iterate through RHS
        {
            auto it1 = find(unsortedNonterminals.begin(), unsortedNonterminals.end(), symbol); //Check if terminal
            auto it2 = find(terminals.begin(), terminals.end(), symbol); //Check if terminal has been added
            auto it3 = find(nonterminals.begin(), nonterminals.end(), symbol); //Check if nonterminal has been added
            if(it1 == unsortedNonterminals.end() && it2 == terminals.end() && symbol != "#") //Terminal addition case
            {
                terminals.push_back(symbol); //Add terminal in order
            }
            else if(it1 != unsortedNonterminals.end() && it3 == nonterminals.end()) //Nonterminal addition case
            {
                nonterminals.push_back(symbol); //Add nonterminal in order
            }
        }
    }
    return; //Return from function
}

/*
 * This function handles the removal of useless symbols
 */
vector<rule*> removeUselessSymbols()
{
    calculateTerminalsAndNonTerminals(); //Calculate sorted lists
    vector<rule*> genGrammar = calculateGenerating(); //Calculate generating grammar
    vector<rule*> usefulGrammar = calculateReachable(genGrammar); //Calculate useful grammar
    return usefulGrammar; //Return useful grammar
}

/*
 * This function calculates the generating grammar from the given grammar
 */
vector<rule*> calculateGenerating()
{
    vector<rule*> genGrammar; //Vector for generating grammar
    set<string> generating; //Set of generating symbols
    generating.insert("#"); //Insert epsilon
    for(string terminal : terminals) //Add terminals to generating set
    {
        generating.insert(terminal); //Add terminal to set
    }
    bool change = true; //Sentinel for loop termination
    while(change) //Iterate over grammar until no change
    {
        change = false; //Set sentinel to terminate
        for(rule* rule : givenGrammar) //Iterate over given grammar
        {
            auto it1 = generating.find(rule->LHS); //Check set for LHS
            if(it1 == generating.end()) //Check RHS case
            {
                bool all = true; //Boolean for RHS generates
                for(string symbol : rule->RHS) //Iterate over RHS of current rule
                {
                    auto it2 = generating.find(symbol); //Check set for symbol
                    if(it2 == generating.end()) //Disjoint case
                    {
                        all = false; //Falsify RHS generates
                        break; //Stop loop
                    }
                }
                if(all && it1 == generating.end()) //RHS generates case
                {
                    generating.insert(rule->LHS); //Add symbol to set
                    change = true; //Set changed, reiterate
                }
            }
        }
    }
    for(rule* rule : givenGrammar) //Add generating rules to generating grammar
    {
        auto it1 = generating.find(rule->LHS); //Check set for LHS
        if(it1 != generating.end()) //Check RHS case
        {
            bool all = true; //Boolean for RHS generates
            for(string symbol : rule->RHS) //Iterate over RHS
            {
                auto it2 = generating.find(symbol); //Check set for symbol
                if(it2 == generating.end()) //Non-generating case
                {
                    all = false; //Falsify RHS generates
                    break; //Stop loop
                }
            }
            if(all) //Rule generates case
            {
                genGrammar.push_back(rule); //Add rule to generating grammar
            }
        }
    }
    return genGrammar; //Return generating grammar
}

/*
 * This function calculates the useful grammar from the generating grammar
 */
vector<rule*> calculateReachable(vector<rule*> genGrammar)
{
    vector<rule*> usefulGrammar; //Vector for useful grammar
    set<string> reachable; //Set of reachable symbols
    reachable.insert(givenGrammar[0]->LHS); //Insert start symbol
    bool change = true; //Sentinel for loop termination
    while(change) //Iterate until no change
    {
        change = false; //Set sentinel to terminate
        for(rule* rule : genGrammar) //Iterate over generating grammar
        {
            auto it1 = reachable.find(rule->LHS); //Check for reachable LHS
            if(it1 != reachable.end()) //Add RHS case
            {
                for(string symbol : rule->RHS) //Iterate over RHS
                {
                    auto it2 = reachable.find(symbol); //Check for already added
                    if(it2 == reachable.end()) //Add RHS case
                    {
                        reachable.insert(symbol); //Add symbol to reachable set
                        change = true; //Set changed, reiterate
                    }
                }
            }
        }
    }
    for(rule* rule : genGrammar) //Create useful grammar from generating grammar
    {
        auto it1 = reachable.find(rule->LHS); //Check rule reachability
        if(it1 != reachable.end()) //Add case
        {
            usefulGrammar.push_back(rule); //Add useful rule
            usefulRuleCount++; //Increment count of useful rules
        }
    }
    return usefulGrammar; //Return useful grammar
}

/*
 * This function calculates first sets of Non-Terminals
 */
void calculateFirstSets()
{
    calculateTerminalsAndNonTerminals(); //Calculate terminals and nonterminals for set uses
    initializeFirsts(); //Initialize first sets of epsilon and terminals
    bool change = true; //Sentinel for loop termination
    while(change) //Iterate until no change
    {
        change = false; //Set sentinel to terminate
        for(rule* rule : givenGrammar) //Apply Rules III, IV, and V
        {
            auto addTo = firstSetMap.find(rule->LHS); //Get index of First(LHS)
            auto symbol = rule->RHS.begin(); //First symbol of RHS
            auto symbolAddr = firstSetMap.find(*symbol); //Get index of First(symbol)
            bool genEp = false; //Boolean for Rule IV
            bool changed = false; //Boolean for set change
            for(string setSymbol : firstSets[symbolAddr->second]) //Apply Rule III
            {
                if(setSymbol == "#") //Epsilon generation case
                {
                    genEp = true; //Apply Rule IV below
                }
                else //Add First(symbol)-epsilon
                {
                    changed = firstSets[addTo->second].insert(setSymbol).second; //Rule III
                    if(changed) //Set changed case
                    {
                        change = changed; //Set changed, reiterate
                    }
                }
            }
            symbol++; //Iterate to next symbol
            if(symbol != rule->RHS.end() && genEp) //Rule IV case
            {
                symbolAddr = firstSetMap.find(*symbol); //Update First(symbol)
                bool allGenEp = true; //Sentinel for loop termination
                while(symbol != rule->RHS.end() && allGenEp) //Apply Rule IV iteratively
                {
                    allGenEp = false; //Set sentinel to terminate
                    for(string setSymbol : firstSets[symbolAddr->second]) //Apply Rule IV
                    {
                        if(setSymbol == "#") //Epsilon generation case
                        {
                            allGenEp = true; //Reiterate
                        }
                        else //Add First(symbol)-epsilon
                        {
                            changed = firstSets[addTo->second].insert(setSymbol).second; //Rule IV
                            if(changed) //Set changed case
                            {
                                change = changed; //Set changed, reiterate
                            }
                        }
                    }
                    if(allGenEp) //Reiterate case
                    {
                        symbol++; //Iterate to next symbol
                        if(symbol != rule->RHS.end()) //Valid symbol case
                        {
                            symbolAddr = firstSetMap.find(*symbol); //Update First(symbol)
                        }
                    }
                }
                if(allGenEp) //Rule V case
                {
                    changed = firstSets[addTo->second].insert("#").second; //Rule V
                    if(changed) //Check if set changed
                    {
                        change = changed; //Set changed, reiterate
                    }
                }
            }
            else if(genEp) //Rule V case
            {
                changed = firstSets[addTo->second].insert("#").second; //Rule V
                if(changed) //Check if set changed
                {
                    change = changed; //Set changed, reiterate
                }
            }
        }
    }
    return; //Return from function
}

/*
 * This function initializes mappings and first sets of terminals and epsilon
 */
void initializeFirsts()
{
    int addr = 0; //Address of set counter
    for(string nonterminal : nonterminals) //Map nonterminals
    {
        firstSetMap.insert(pair<string, int>(nonterminal, addr)); //Add nonterminal to map
        addr++; //Increment set counter
        set<string> firstNT; //First(NT)
        firstSets.push_back(firstNT); //Add First(NT)
    }
    firstSetMap.insert(pair<string, int>("#", addr)); //Add epsilon to map
    addr++; //Increment set counter
    set<string> firstEp; //First(#)
    firstEp.insert("#"); //Rule I - Add # to First(#)
    firstSets.push_back(firstEp); //Add First(#)
    for(string terminal : terminals) //Map terminals
    {
        firstSetMap.insert(pair<string, int>(terminal, addr)); //Add terminal to map
        addr++; //Increment set counter
        set<string> firstT; //First(t)
        firstT.insert(terminal); //Rule II - Add t to First(t)
        firstSets.push_back(firstT); //Add First(t)
    }
    return; //Return from function
}

/*
 * This function calculates the follow sets of the Non-Terminals
 */
void calculateFollowSets()
{
    calculateFirstSets(); //Calculate first sets
    initializeFollows(); //Initialize follow sets of nonterminals
    bool change = true; //Sentinel for loop termination
    while(change) //Iterate until no change
    {
        change = false; //Set sentinel to terminate
        for(rule* rule : givenGrammar) //Apply Rules II and III
        {
            string left = rule->LHS; //Symbol to add follow from
            auto leftAddr = followSetMap.find(left); //Get Follow(left) location
            auto right = rule->RHS.end()-1; //Symbol to add follow to
            auto rightFollowAddr = followSetMap.find(*right); //Get Follow(right) location
            auto rightFirstAddr = firstSetMap.find(*right); //Get First(right) location
            if(rightFollowAddr != followSetMap.end()) //Valid Follow(right) case
            {
                bool changed = false; //Boolean for set change
                for(string setSymbol : followSets[leftAddr->second]) //Apply Rule II
                {
                    changed = followSets[rightFollowAddr->second].insert(setSymbol).second; //Rule II
                    if(changed) //Set change case
                    {
                        change = changed; //Set changed, reiterate
                    }
                }
                auto ep = firstSets[rightFirstAddr->second].find("#"); //Check for epsilon
                if(ep != firstSets[rightFirstAddr->second].end()) //Epsilon case
                {
                    right--; //Go to next symbol
                    bool genEp = true; //Sentinel for loop termination
                    while(genEp) //Apply Rule III
                    {
                        genEp = false; //Set sentinel to terminate
                        if(right != rule->RHS.begin()) //Arbitrary case
                        {
                            rightFollowAddr = followSetMap.find(*right); //Get Follow(right)
                            rightFirstAddr = firstSetMap.find(*right); //Get First(right)
                            if(rightFollowAddr != followSetMap.end()) //Valid case
                            {
                                for(string setSymbol : followSets[leftAddr->second]) //Apply Rule III
                                {
                                    changed = followSets[rightFollowAddr->second].insert(setSymbol).second; //Rule III
                                }
                                ep = firstSets[rightFirstAddr->second].find("#"); //Check for epsilon
                                if(ep != firstSets[rightFirstAddr->second].end()) //Epsilon case
                                {
                                    genEp = true; //Reapply Rule III
                                    right--; //Go to next symbol
                                }
                            }
                        }
                        else //Last symbol case
                        {
                            rightFollowAddr = followSetMap.find(*right); //Get Follow(right)
                            rightFirstAddr = firstSetMap.find(*right); //Get First(right)
                            if(rightFollowAddr != followSetMap.end()) //Valid case
                            {
                                for (string setSymbol: followSets[leftAddr->second]) //Apply Rule III
                                {
                                    changed = followSets[rightFollowAddr->second].insert(setSymbol).second; //Rule III
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return; //Return from function
}

/*
 * This function initializes the follow sets of nonterminals and
 */
void initializeFollows()
{
    int addr = 0; //Address of set counter
    for(string nonterminal : nonterminals) //Map nonterminals
    {
        followSetMap.insert(pair<string, int>(nonterminal, addr)); //Map nonterminal
        addr++; //Increment set counter
        set<string> followNT; //Create Follow(NT)
        followSets.push_back(followNT); //Add Follow(NT)
        if(nonterminal == nonterminals[0]) //Rule I case
        {
            followSets[0].insert("$"); //Rule I
        }
    }
    for(rule* rule : givenGrammar) //Apply Rules IV and V
    {
        auto left = rule->RHS.begin(); //Symbol iterators
        auto right = left+1;
        while(left != rule->RHS.end()) //Apply Rules IV and V to RHS
        {
            if(right == rule->RHS.end()) //Single symbol case
            {
                left = rule->RHS.end(); //Terminate loop
            }
            else //Apply rules case
            {
                auto nonterminal = find(terminals.begin(), terminals.end(), *left); //Check if left is nonterminal
                if(nonterminal == terminals.end()) //Apply rules case
                {
                    auto leftAddr = followSetMap.find(*left); //Get Follow(left) location
                    auto rightAddr = firstSetMap.find(*right); //Get First(right) location
                    bool genEp = false; //Boolean for
                    for(string setSymbol : firstSets[rightAddr->second]) //Apply Rule IV
                    {
                        if(setSymbol == "#") //Epsilon case
                        {
                            genEp = true; //Apply Rule V below
                            right++; //Iterate to next symbol
                        }
                        else //Rule IV case
                        {
                            followSets[leftAddr->second].insert(setSymbol); //Rule IV
                        }
                    }
                    while(genEp && right != rule->RHS.end()) //Apply Rule V
                    {
                        genEp = false; //Set sentinel to terminate
                        rightAddr = firstSetMap.find(*right); //Get First(right)
                        for(string setSymbol : firstSets[rightAddr->second]) //Apply Rule V
                        {
                            if(setSymbol == "#")
                            {
                                genEp = true; //Reapply Rule V
                                right++; //Iterate to next symbol
                            }
                            else //Rule V case
                            {
                                followSets[leftAddr->second].insert(setSymbol); //Rule V
                            }
                        }
                    }
                    left++; //Iterate and reapply rules
                    right = left+1;
                }
                else //Terminal case
                {
                    left++; //Iterate and reapply rules
                    right = left+1;
                }
            }
        }
    }
    return; //Return from function
}

/*
 * This function determines if the input grammar has a predictive parser
 */
void checkIfGrammarHasPredictiveParser()
{
    removeUselessSymbols(); //Determine if grammar is fully useful
    bool predictiveParser = true; //Boolean for predictive parser
    if(givenRuleCount == usefulRuleCount) //Useful grammar
    {
        calculateFollowSets(); //Calculate first and follows
        for(auto rule1 = givenGrammar.begin(); rule1 != givenGrammar.end(); rule1++) //Evaluate condition 1 for all rules
        {
            for(auto rule2 = rule1+1; rule2 != givenGrammar.end(); rule2++) //Compare against all other rules
            {
                if((*rule2)->LHS == (*rule1)->LHS) //Condition 1 case
                {
                    set<string> firstRule1; //Sets for rules 1 and 2
                    set<string> firstRule2;
                    bool allEp = true; //Boolean for epsilon case
                    for(string symbol : (*rule1)->RHS) //Get first of rule1
                    {
                        auto firstAddr1 = firstSetMap.find(symbol); //Get first(symbol) location
                        bool ep = false; //Boolean for adding next first set symbols
                        for(string setSymbol : firstSets[firstAddr1->second]) //Add symbols to first set
                        {
                            if(setSymbol == "#")
                            {
                                ep = true; //Reiterate case
                            }
                            else //Add case
                            {
                                firstRule1.insert(setSymbol); //Add set symbols to set
                            }
                        }
                        if(!ep) //No more elements to add
                        {
                            allEp = false; //No epsilon in this first
                            break; //Stop loop
                        }
                    }
                    if(allEp) //Add epsilon case
                    {
                        firstRule1.insert("#"); //Add epsilon case
                    }
                    allEp = true; //Revaluate for epsilon
                    for(string symbol : (*rule2)->RHS) //Get first of rule2
                    {
                        auto firstAddr2 = firstSetMap.find(symbol); //Get first(symbol) location
                        bool ep = false; //Boolean for adding next first set symbols
                        for(string setSymbol : firstSets[firstAddr2->second]) //Add symbols to first set
                        {
                            if(setSymbol == "#")
                            {
                                ep = true; //Reiterate case
                            }
                            else //Add case
                            {
                                firstRule2.insert(setSymbol); //Add set symbols to set
                            }
                        }
                        if(!ep) //No more elements to add
                        {
                            allEp = false; //No epsilon in this first
                            break; //Stop loop
                        }
                    }
                    if(allEp) //Add epsilon case
                    {
                        firstRule2.insert("#"); //Add epsilon case
                    }
                    for(string setSymbol : firstRule1) //Check condition 1
                    {
                        auto intersection = firstRule2.find(setSymbol); //Check for intersection
                        if(intersection != firstRule2.end()) //Intersection case
                        {
                            predictiveParser = false; //Condition 1 fail
                            break; //Stop loop
                        }
                    }
                }
            }
        }
        for(string nonterminal : nonterminals) //Evaluate condition 2
        {
            auto firstAddr = firstSetMap.find(nonterminal); //Get First(NT)
            auto followAddr = followSetMap.find(nonterminal); //Get Follow(NT)
            auto ep = firstSets[firstAddr->second].find("#"); //Check for epsilon
            if(ep != firstSets[firstAddr->second].end()) //Epsilon case
            {
                for(string setSymbol : firstSets[firstAddr->second]) //Check condition 2
                {
                    auto intersection = followSets[followAddr->second].find(setSymbol); //Check for intersection
                    if(intersection != followSets[followAddr->second].end()) //Intersection case
                    {
                        predictiveParser = false; //Condition 2 fail
                        break; //Stop loop
                    }
                }
            }
        }
    }
    else //Useless symbols case
    {
        predictiveParser = false; //No predictive parser for useless symbols
    }
    if(predictiveParser) //Predictive parser case
    {
        cout << "YES" << endl; //Output yes
    }
    else //No predictive parser case
    {
        cout << "NO" << endl; //Output no
    }
}

/*
 * This function prints the symbols of the given grammar
 */
void printSymbols()
{
    for(string symbol : terminals) //Print terminals
    {
        cout << symbol << " "; //Print terminal
    }
    for(string symbol : nonterminals)
    {
        cout << symbol << " "; //Print nonterminal
    }
    cout << endl << endl; //Newline for next task
}

/*
 * This function prints a given input grammar
 */
void printGrammar(vector<rule*> grammar)
{
    for(rule* rule : grammar) //Print rules
    {
        cout << rule->LHS << " -> "; //Print LHS
        for(string symbol : rule->RHS) //Print RHS symbols
        {
            cout << symbol << " "; //Print symbol
        }
        cout << endl; //Newline for next rule
    }
    cout << endl; //Newline for next task
}

/*
 * This function prints the first sets
 */
void printFirstSets()
{
    for(string nonterminal : nonterminals)
    {
        cout << "FIRST(" << nonterminal << ") = { "; //Print set definition
        int elements = 0; //Element counter for comma placement
        auto firstNT = firstSetMap.find(nonterminal); //Check if valid first set
        if(firstNT != firstSetMap.end()) //Valid first set case
        {
            auto ep = firstSets[firstNT->second].find("#"); //Check if epsilon is in first set
            if(ep != firstSets[firstNT->second].end()) //Print epsilon case
            {
                cout << "#"; //Print epsilon
                elements++; //Increment element count
            }
            for(string symbol : terminals) //Print terminals in first set
            {
                auto terminal = firstSets[firstNT->second].find(symbol); //Check if terminal is in set
                if(terminal != firstSets[firstNT->second].end()) //Print case
                {
                    if(elements > 0) //Check if not first element
                    {
                        cout << ", " << symbol; //Print terminal in first set
                        elements++; //Increment element count
                    }
                    else //First element case
                    {
                        cout << symbol; //Print terminal in first set
                        elements++; //Increment element count
                    }
                }
            }
        }
        cout << " }\n"; //Newline for next first set
    }
    cout << endl; //Newline for next task
}

/*
 * This function prints the follow sets
 */
void printFollowSets()
{
    for(string nonterminal : nonterminals)
    {
        cout << "FOLLOW(" << nonterminal << ") = { "; //Print set definition
        int elements = 0; //Element counter for comma placement
        auto followNT = followSetMap.find(nonterminal); //Check if valid follow set
        if(followNT != followSetMap.end()) //Valid follow set case
        {
            auto eof = followSets[followNT->second].find("$"); //Check if EOF is in follow set
            if(eof != followSets[followNT->second].end()) //Print EOF case
            {
                cout << "$"; //Print EOF
                elements++; //Increment element count
            }
            for(string symbol : terminals) //Print terminals in follow set
            {
                auto terminal = followSets[followNT->second].find(symbol); //Check if terminal is in set
                if(terminal != followSets[followNT->second].end()) //Print case
                {
                    if(elements > 0) //Check if not first element
                    {
                        cout << ", " << symbol; //Print terminal in follow set
                        elements++; //Increment element count
                    }
                    else //First element case
                    {
                        cout << symbol; //Print terminal in follow set
                        elements++; //Increment element count
                    }
                }
            }
        }
        cout << " }\n"; //Newline for next follow set
    }
    cout << endl; //Newline for next task
}

/*
 * This function executes the program
 */
int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);

    readGrammar();  // Reads the input grammar from standard input
    // and represent it internally in data structures
    // ad described in project 2 presentation file

    switch (task) {
        case 1: calculateTerminalsAndNonTerminals();
            printSymbols();
            break;

        case 2: printGrammar(removeUselessSymbols());
            break;

        case 3: calculateFirstSets();
            printFirstSets();
            break;

        case 4: calculateFollowSets();
            printFollowSets();
            break;

        case 5: checkIfGrammarHasPredictiveParser();
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}