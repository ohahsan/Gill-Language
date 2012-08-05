.PHONY: all clean

all: guocc

Lexer.o: Lexer.cpp Lexer.h
	g++ -c Lexer.cpp

LexerDriver.o: LexerDriver.cpp Lexer.h
	g++ -c LexerDriver.cpp

guocc: Lexer.h Lexer.o LexerDriver.o
	g++ -o guocc Lexer.o LexerDriver.o

clean: 
	del *.o *~