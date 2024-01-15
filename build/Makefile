# Makefile Variables

Compiler = g++
STD = -std=c++14
C_Flags = -Wall -Wfatal-errors 
SRC = ../src/*.cpp
L_Flags = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 
Output = Demo

# Makefile Rules

build:
	$(Compiler) $(C_Flags) $(STD) $(SRC) $(L_Flags) -o $(Output)

run:
	./$(Output)

clean:
	rm $(Output)