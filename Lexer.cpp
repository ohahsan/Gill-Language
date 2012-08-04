#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Lexer.h"

using namespace std;

static string word = "";
static int number;

int getToken() {
  static int lastChar = ' ';

  // Ignore spaces.
  while (isspace(lastChar)) {
    lastChar = getchar();
  }

  // Keyword
  if (isalpha(lastChar)) {
    
    // Get the rest of the keyword.
    while(isalnum(lastChar)) {
      word += lastChar;
      lastChar = getchar();
    }

    // Match the keyword to a token.
    if (word == "func") {
      return FUNC;
    } else if (word == "var") {
      return VAR;
    } else if (word == "gint") {
      return GINT;
    } else if (word == "guif") {
      return GUIF;
    } else if (word == "elif") {
      return ELIF;
    } else if (word == "guolse") {
      return GUOLSE;
    }
  }

  // Integers.
  if (isdigit(lastChar)) {
    string numberString;
    do {
      numberString += lastChar;
      lastChar = getchar();
    } while (isdigit(lastChar));
    number = atoi(numberString.c_str());
    return NUM;
  }

  // Comments.
  if (lastChar == '/') {
    lastChar = getchar();
    if (lastChar == '/') {
      do {
	lastChar = getchar();
      } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

      if (lastChar != EOF) {
	int nextToken = getToken();
	return nextToken;
      }
    }

    // End of file.
    if (lastChar == EOF) {
      return EOF_TOKEN;
    }
  }

  // Other characters.
  int thisChar = lastChar;
  lastChar = getchar();
  return thisChar;

}
