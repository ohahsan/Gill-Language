#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "Compiler.h"

using namespace std;

static void parseGuif(vector<TokenClass> tokens);
static void evalGuif(vector<TokenClass> conditions
		     , vector<TokenClass> trues);

unsigned int position = 0;

/* parse -

   Uses the lexer to generate tokens and then parses them. */


void parse(vector<TokenClass> tokens) {
  for (position = 0; position < tokens.size(); position++) {
    TokenClass curTok = tokens[position];
    int token = curTok.tok;
    // string id = curTok.id;
    // int num = curTok.num;
    
    if (token == GUIF) {
      parseGuif(tokens);
    }

  }
}

/* parseGuif -

   Organizes the tokens into the condition and the
   statements to evaluate. */

void parseGuif(vector<TokenClass> tokens) {
  cout << "Parsing an if!" << endl;
  vector<TokenClass> statement;
  vector<TokenClass> trues;
  position++;
  position++; // Ignore the '('
  while (tokens[position].tok != ')') {
    statement.push_back(tokens[position]);
    position++;
  }
  position++; // Ignore the ')'
  position++; // Ignore the '{'
  while (tokens[position].tok != '}') {
    trues.push_back(tokens[position]);
    position++;
  }
  position++; // Ignore the '}'
  evalGuif(statement, trues);
}

/* evalGuif -

   Evaluates the guif statement. 
   NOT started... */

void evalGuif(vector<TokenClass> condition, vector<TokenClass> trues) {
  cout << "Condition: " << endl;
  printTokens(condition);
  cout << "If true: " << endl;
  printTokens(trues);
}
