#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Lexer.h"

using namespace std;

// correctSuffix method.
static bool correctSuffix(string file);

/* main -

   Takes an input file of code, generates the tokens 
   with guocc and puts them in an output file. */

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
  string outName(argv[1]), text = "", temp = "";

  // Check if filename ends with .guo
  if (!correctSuffix(outName)) {
    cerr << "Error: .guo file not entered." << endl;
    return -1;
  }

  inFile.open(argv[1]); 

  // Read the code from the file.
  while (inFile.is_open() && !inFile.eof()) {
    getline(inFile, temp);
    lines << temp << endl;
  }
  text = lines.str();
  inFile.close();

  // Send code to lexer and put tokens in another file.
  int pos = 0;
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

/* correctSuffix -

   Returns true if file is a .guo file. */

static bool correctSuffix(string file) {
  if (file.length() < 5) {
    return false;
  }
  return (0 == file.compare(file.length() - 4, 4, ".guo"));
}
