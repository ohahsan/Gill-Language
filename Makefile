CC = g++
FLAGS = -ansi -pedantic-errors -Wall -Werror

.PHONY: all clean

all: guocc

Compiler.o: Parser.h Compiler.cpp
	$(CC) $(FLAGS) -c Compiler.cpp

Lexer.o: Lexer.h Lexer.cpp
	$(CC) $(FLAGS) -c Lexer.cpp

Parser.o: Lexer.h Parser.h Parser.cpp
	$(CC) $(FLAGS) -c Parser.cpp

guocc: Compiler.o Lexer.o Parser.o
	$(CC) -o guocc Compiler.o Lexer.o Parser.o

clean: 
	del *.o *~