#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Interpreter.h"
#include "Compiler.h"

using namespace std;



static void parseGuif(vector<TokenClass> tokens);
static void evalGuif(vector<TokenClass> conditions,
		     vector<TokenClass> trues);

static void parseExpr(vector<TokenClass> tokens);
static int evalExpr(vector<TokenClass> expression);

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
    } else if (token != EOF_TOKEN) {
      parseExpr(tokens);
    }
    
  }
}

/* parseExpr -
   
   Parses an expression and sends it to be evaluated. */

static void parseExpr(vector<TokenClass> tokens) {
  vector<TokenClass> expression;
  while (tokens[position].tok != ';') {
    expression.push_back(tokens[position]);
    position++;
  }
  cout << ">> " << evalExpr(expression) << endl;
}

/* evalExpr -

  Evaluates an expression given as a vector of tokens.
  FOR NOW...very basic expressions. */

static int evalExpr(vector<TokenClass> expression) {

  // TODO...
  // MAKE THIS WITH A REAL INFIX PARSING THING!!

  int op = expression[1].tok;
  int a = expression[0].num;
  int b = expression[2].num;
  if (op == '+') {
    return a+b;
  } else if (op == '-') {
    return a-b;
  }
  return 0;
}

/* parseGuif -

   Organizes the tokens into the condition and the
   statements to evaluate. */

static void parseGuif(vector<TokenClass> tokens) {
  vector<TokenClass> statement;
  vector<TokenClass> trues;
  position++; // Ignore the 'guif'
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
  evalGuif(statement, trues);
}

/* evalGuif -

   Evaluates the guif statement. 
   If <condition> = 0 then false, else true. */

static void evalGuif(vector<TokenClass> condition, vector<TokenClass> trues) {
  int res = evalExpr(condition);
  if (res != 0) {
    cout << ">> " << evalExpr(trues) << endl;
  }
}
