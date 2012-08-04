CC = g++

Test: Lexer.cpp Lexer.h LexerDriver.cpp
	$(CC) -o Test Lexer.cpp LexerDriver.cpp