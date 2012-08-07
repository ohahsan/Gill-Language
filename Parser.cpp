#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"

using namespace std;

extern string word;
extern int number;

/* parse -

   Uses the lexer to generate tokens and then parses them. */

void parse(string code) {
  int token, position = 0;
  while (token != EOF_TOKEN) {
    token = getToken(code, &position);
    cout << token;
    if (token == IDEN) {
      cout << " = " << word;
    } else if (token == NUM) {
      cout << " = " << number;
    }
    cout << endl;
  }
}
