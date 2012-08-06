CC = g++
FLAGS = -ansi -pedantic-errors -Wall -Werror

.PHONY: all clean

all: guocc

Lexer.o: Lexer.cpp Lexer.h
	$(CC) $(FLAGS) -c Lexer.cpp

Compiler.o: Compiler.cpp Lexer.h
	$(CC) $(FLAGS) -c Compiler.cpp

guocc: Lexer.o Compiler.o
	$(CC) -o guocc Lexer.o Compiler.o

clean: 
	del *.o *~