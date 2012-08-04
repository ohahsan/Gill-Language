#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
  string file;
  getline(cin, file); 
  int pos = 0;
  while (pos < file.length()) {
    cout << getToken(file, &pos) << endl;
  }
  return 0;
}
