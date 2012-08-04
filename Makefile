.PHONY: all clean

all: Test

Lexer.o: Lexer.cpp Lexer.h
	g++ -c Lexer.cpp

LexerDriver.o: LexerDriver.cpp Lexer.h
	g++ -c LexerDriver.cpp

Test: Lexer.h Lexer.o LexerDriver.o
	g++ -o Test Lexer.o LexerDriver.o

clean: 
	del *.o *~