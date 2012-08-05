#include <iostream>
#include <fstream>
#include "Lexer.h"

using namespace std;

int main() {
  ifstream file;
  file.open("code.txt");
  string text = "", temp = "";
  while (file.is_open() && !file.eof()) {
    getline(file, temp);
    text += temp;
  }
  file.close();
  int pos = 0;
  while (pos <= text.length()) {
    cout << getToken(text, &pos) << endl;
  }
  return 0;
}
