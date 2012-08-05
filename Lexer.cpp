#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Lexer.h"

using namespace std;

static string word = "";
static int number;

int getToken(string file, int *position) {
  static int lastChar = ' ';
  word = "";

  // Ignore spaces.
  while (isspace(lastChar)) {
    lastChar = nextChar(file, position);
  }

  // Keyword
  if (isalpha(lastChar)) {
    
    // Get the rest of the keyword.
    while(isalnum(lastChar)) {
      word += lastChar;
      lastChar = nextChar(file, position);
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
    } else if (word == "guoturn") {
      return GUOTURN;
    } else {
      return IDEN;
    }
  }

  // Integers.
  if (isdigit(lastChar)) {
    string numberString;
    do {
      numberString += lastChar;
      lastChar = nextChar(file, position);
    } while (isdigit(lastChar));
    number = atoi(numberString.c_str());
    return NUM;
  }

  // Comments.
  if (lastChar == '/') {
    lastChar = nextChar(file, position);
    if (lastChar == '/') {
      do {
	lastChar = nextChar(file, position);
      } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

      if (lastChar != -1) {
	int nextToken = getToken(file, position);
	return nextToken;
      } else {
	return EOF_TOKEN;
      }
    }
  }

  // End of file.
  if (lastChar == -1) {
    return EOF_TOKEN;
  }

  // Other characters.
  int thisChar = lastChar;
  lastChar = nextChar(file, position);
  return thisChar;

}

static int nextChar(string file, int *position) {
  // End of file.
  if (*position >= file.length()) {
    return -1;
  } 

  int character = file[*position];
  *position = *position + 1;
  return character;
}
