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
    lastChar = nexChar(file, position);
  }

  // Keyword
  if (isalpha(lastChar)) {
    
    // Get the rest of the keyword.
    while(isalnum(lastChar)) {
      word += lastChar;
      lastChar = nexChar(file, position);
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
    } else {
      return IDEN;
    }
  }

  // Integers.
  if (isdigit(lastChar)) {
    string numberString;
    do {
      numberString += lastChar;
      lastChar = nexChar(file, position);
    } while (isdigit(lastChar));
    number = atoi(numberString.c_str());
    return NUM;
  }

  // Comments.
  if (lastChar == '/') {
    lastChar = nexChar(file, position);
    if (lastChar == '/') {
      do {
	lastChar = nexChar(file, position);
      } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

      if (lastChar != EOF) {
	int nextToken = getToken(file, position);
	return nextToken;
      }
    }

    // End of file.
    if (lastChar == '\n') {
      return EOF_TOKEN;
    }
  }

  // Other characters.
  int thisChar = lastChar;
  lastChar = nexChar(file, position);
  return thisChar;

}

static int nexChar(string file, int *position) {
  int character = file[*position];
  *position = *position + 1;
  return character;
}
