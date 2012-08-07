#ifndef PARSER_H
#define PARSER_H

/* East (Expression Abstract Syntax Tree) - 
   Base class for expressions. */
/*
class East {
 public:
  virtual ~East();
};
*/

// NumberEast - For numeric integers.
/*
class NumberEast : public East {
  int value;
 public:
  NumberEast(int val) {
    value = val;
  }
};
*/

// VariableEast - For referencing a variable.
/*
class VariableEast : public East {
  std::string name;
 public:
  VariableEast(std::string n) {
    name = n;
  }
};
*/

// BinaryEast - Binary expressions.
/*
class BinaryEast : public East {
  char operator;
  East *left, *right;
 public:
  BinaryEast(char op, East *l, East *r) {
    operator = op;
    left = l;
    right = r;
  }
};
*/

// CallEast - For function calls.
/*
class CallEast : public East {
  std::string callee;
  std::vector<East *> arguments;
 public:
  CallEast(std::string call, std::vector<East *> args) {
    callee = call;
    arguments = args;
  }
};
*/

void parse(std::string code);

#endif
