CPP = g++
FLAGS = -ansi -pedantic-errors -Wall -Werror

.PHONY: all clean

all: guocc

Compiler.o: Parser.h Compiler.cpp
	$(CPP) $(FLAGS) -c Compiler.cpp

Lexer.o: Lexer.h Lexer.cpp
	$(CPP) $(FLAGS) -c Lexer.cpp

Parser.o: Parser.h Parser.cpp
	$(CPP) $(FLAGS) -c Parser.cpp

guocc: Compiler.o Lexer.o Parser.o
	$(CPP) -o guocc Compiler.o Lexer.o Parser.o

clean: 
	del *.o *~
