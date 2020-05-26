CC =	g++


sudoku: sudoku.o functions.o 
	$(CC) sudoku.o functions.o -o sudoku

sudoku.o: sudoku.cpp
	g++ -c sudoku.cpp

functions.o: functions.cpp functions.hpp
	$(CC) -c functions.cpp

clean: 
	rm -r functions.o sudoku.o