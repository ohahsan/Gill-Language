#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Parser.h"

using namespace std;

// correctSuffix method.
static bool correctSuffix(string file);

/* main -

   Takes an input file of code, combines it into
   one string and sends it to the parser. */

int main(int argc, char *argv[]) {
  // If filename is not included.
  if (argc < 2) {
    cerr << "Error: guocc takes 2 arguments." << endl;
    return -1;
  }

  // Setup of file streams.
  ifstream inFile;
  ostringstream lines(ostringstream::out);
  string filename(argv[1]), text = "", temp = "";

  // Check if filename ends with .guo
  if (!correctSuffix(filename)) {
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

  // Send code to parser.
  parse(text);
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
