#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

using namespace std;

int main() {
  ifstream file;
  ostringstream lines(ostringstream::out);
  file.open("code.txt");
  string text = "", temp = "";
  while (file.is_open() && !file.eof()) {
    getline(file, temp);
    lines << temp << endl;
  }
  text = lines.str();
  file.close();
  int pos = 0;
  cout << "File length: " << text.length() << endl;
  cout << "At 26: " << text[26] << endl;
  while (pos < text.length()) {
    cout << getToken(text, &pos) << endl;
  }
  return 0;
}
