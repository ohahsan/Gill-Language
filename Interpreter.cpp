#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Interpreter.h"
#include "Compiler.h"

using namespace std;

// Guif statements.

static void parseGuif(vector<TokenClass> tokens);
static void evalGuif(Expression condition,
		     vector<Expression> trues);

// Expressions.

static Expression parseExpr(vector<TokenClass> tokens);
static Expression parseParenExpr(vector<TokenClass> tokens);
static int evalExpr(Expression expression);

unsigned int position = 0;

/* interpret -

   Takes a vector of tokens and parses and evaluates them. */

void interpret(vector<TokenClass> tokens) {
  for (position = 0; position < tokens.size(); position++) {
    TokenClass curTok = tokens[position];
    int token = curTok.tok;
    // string id = curTok.id;
    // int num = curTok.num;
    
    if (token == GUIF) {
      parseGuif(tokens);
    }  else if (token != EOF_TOKEN) {
      evalExpr(parseExpr(tokens));
    }
    
  }
}

/* parseExpr -
   
   Parses an expression and sends it to be evaluated. */

static Expression parseExpr(vector<TokenClass> tokens) {
  vector<TokenClass> exp;
  while (tokens[position].tok != ';') {
    if (tokens[position].tok  == '(') {
      Expression temp = parseParenExpr(tokens);
      TokenClass token = TokenClass(NUM, "", evalExpr(temp));
      exp.push_back(token);
    } else {
      exp.push_back(tokens[position]);
    }
    position++;
  }
  Expression expression = Expression(exp);
  return expression;
}

/* parseParenExpr -
   
   Parses an expression that is inside parenthesis. */

static Expression parseParenExpr(vector<TokenClass> tokens) {
  vector<TokenClass> exp;
  position++; // Ignore the '('
  while (tokens[position].tok != ')') {
    if (tokens[position].tok == '(') {
      Expression temp = parseParenExpr(tokens);
      TokenClass token = TokenClass(NUM, "", evalExpr(temp));
      exp.push_back(token);
    } else {
      exp.push_back(tokens[position]);
    }
    position++;
  }
  Expression expression = Expression(exp);
  return expression;
}

/* evalExpr -

  Evaluates an expression given as a vector of tokens.
  FOR NOW...very basic expressions. */

static int evalExpr(Expression expression) {

  // TODO...
  // MAKE THIS WITH A REAL INFIX PARSING THING!!
  
  vector<TokenClass> exp = expression.tokens;

  if (exp.size() == 1) {
    return exp[0].num;
  } else {

    if (exp[0].tok == GRINT) {
      cout << exp[1].num << endl;
      return 0;
    } else {

      int op = exp[1].tok;
      int a = exp[0].num;
      int b = exp[2].num;
      int ans;
      
      // All operators handled here.
      
      if (op == '+') {
	ans = a+b;
      } else if (op == '-') {
	ans = a-b;
      }
      
      return ans;
    }

  }
  return 0;
}

/* parseGuif -

   Organizes the tokens into the condition and the
   statements to evaluate. */

static void parseGuif(vector<TokenClass> tokens) {
  vector<Expression> exps;
  position++; // Ignore the 'guif'
  Expression cond = parseParenExpr(tokens);
  position++; // Ignore the ')'
  position++; // Ignore the '{'
  while (tokens[position].tok != '}') {
    exps.push_back(parseExpr(tokens));
    position++; // Ignore the ';'
  }
  evalGuif(cond, exps);
}

/* evalGuif -

   Evaluates the guif statement. 
   If <condition> = 0 then false, else true. */

static void evalGuif(Expression condition, vector<Expression> exps) {
  int res = evalExpr(condition);
  if (res != 0) {
    for (unsigned int i = 0; i < exps.size(); i++) {
      evalExpr(exps[i]);
    }
  }
}
