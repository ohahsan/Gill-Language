#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Lexer.h"

using namespace std;

// nextChar method.
static int nextChar(string file, int *position);
// getToken method.
static int getToken(string file, int *position);

string word;
int number;

/* lex -

   Takes a string of code and lexes it. */

vector<TokenClass> lex(string file, int *position) {
  vector<TokenClass> tokens;
  int token, num;
  string id;
  do {
    token = getToken(file, position);
    if (token == IDEN) {
      id = word;
      num = -1;
    } else if (token == NUM) {
      num = number;
      id = "";
    } else {
      num = -1;
      id = "";
    }
    TokenClass tok(token, id, num);
    tokens.push_back(tok);
  } while (token != EOF_TOKEN);
  return tokens;
}

/* getToken - 

   Takes a string of code and a position
   of the string to begin reading. */

static int getToken(string file, int *position) {
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

/* nextChar - 

   Returns the next character in the string
   and increments the position by 1. */

static int nextChar(string file, int *position) {
  // End of file.
  if (*position >= (int)file.length()) {
    return -1;
  } 

  int character = file[*position];
  *position = *position + 1;
  return character;
}
