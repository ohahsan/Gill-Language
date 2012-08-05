#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
  // If filename is not included.
  if (argc < 2) {
    cerr << "Error: guocc takes 2 arguments." << endl;
    return -1;
  }

  // Setup of file streams.
  ifstream inFile;
  ofstream outFile;
  ostringstream lines(ostringstream::out);
  inFile.open(argv[1]);
  string text = "", temp = "";

  // Read the code from the file.
  while (inFile.is_open() && !inFile.eof()) {
    getline(inFile, temp);
    lines << temp << endl;
  }
  text = lines.str();
  inFile.close();

  // Send code to lexer and put tokens in another file.
  int pos = 0;
  string outName(argv[1]);
  outName +=  "-tokens";
  outFile.open(outName.c_str());

  int token;
  while (token != EOF_TOKEN) {
    token = getToken(text, &pos);
    outFile << token << endl;
  }
  outFile.close();
  return 0;
}
