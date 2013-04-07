#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

void interpret(std::vector<TokenClass> tokens);

class Expression {
 public:
  std::vector<TokenClass> tokens;

  Expression(std::vector<TokenClass> toks) {
    tokens = toks;
  }

};

#endif
