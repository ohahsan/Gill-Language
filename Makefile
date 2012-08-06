CC = g++
FLAGS = -ansi -pedantic-errors -Wall -Werror

.PHONY: all clean

all: guocc

Lexer.o: Lexer.cpp Lexer.h
	$(CC) $(FLAGS) -c Lexer.cpp

LexerDriver.o: LexerDriver.cpp Lexer.h
	$(CC) $(FLAGS) -c LexerDriver.cpp

guocc: Lexer.h Lexer.o LexerDriver.o
	$(CC) -o guocc Lexer.o LexerDriver.o

clean: 
	del *.o *~