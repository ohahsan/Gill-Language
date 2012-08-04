#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
  string file = "func gint 345";
  cout << file << endl;
  int pos = 0;
  while (file[pos] != '\n') {
    cout << getToken(file, &pos) << endl;
  }
  return 0;
}