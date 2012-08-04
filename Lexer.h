#ifndef LEXER_H
#define LEXER_H

enum Token {
  // End of file.
  EOF_TOKEN = -1,

  // Function or variable.
  FUNC = -11, VAR = -12,

  // Variable types.
  GINT = -21, NUM = -22,

  // Control flow.
  GUIF = -31, ELIF = -32, GUOLSE = -33,

};

int getToken();

#endif