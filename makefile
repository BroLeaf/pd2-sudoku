Sudoku:main.o Sudoku.o giveQuestion.o solve.o transform.o
	g++ -o Sudoku main.o Sudoku.o giveQuestion.o solve.o transform.o

Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

giveQuestion.o:giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp

solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp

transform.o:transform.cpp Sudoku.h
	g++ -c transform.cpp

main.o:main.cpp Sudoku.h
	g++ -c main.cpp

clean:
	rm Sudoku*.o giveQuestion*.o solve*.o transform*.o
