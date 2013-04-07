#ifndef LEXER_H
#define LEXER_H

enum Token {
  // End of file.
  EOF_TOKEN = -1,

  // Function or variable.
  FUNC = -11, VAR = -12, IDEN = -13,

  // Variable types.
  GINT = -21, NUM = -22,

  // Control flow.
  GUIF = -31, GUOLSE = -32, GUOTURN = -33,

  // Built-ins
  GRINT = -41

};

class TokenClass {
 public:
  int tok;
  std::string id;
  int num;

  TokenClass(int t, std::string i, int n) {
    tok = t;
    id = i;
    num = n;
  }
};

std::vector<TokenClass> lex(std::string file, int *position);

#endif
