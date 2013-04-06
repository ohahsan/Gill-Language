CPP = g++
FLAGS = -ansi -pedantic-errors -Wall -Werror

.PHONY: all clean

all: guocc

Compiler.o: Interpreter.h Compiler.cpp
	$(CPP) $(FLAGS) -c Compiler.cpp

Lexer.o: Lexer.h Lexer.cpp
	$(CPP) $(FLAGS) -c Lexer.cpp

Interpreter.o: Interpreter.h Interpreter.cpp
	$(CPP) $(FLAGS) -c Interpreter.cpp

guocc: Compiler.o Lexer.o Interpreter.o
	$(CPP) -o guocc Compiler.o Lexer.o Interpreter.o

clean: 
	del *.o *~
