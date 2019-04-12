__start__: a.out
	./a.out

a.out: main.o algorytmy.o
	g++ main.o algorytmy.o

main.o: main.cpp algorytmy.hh
	g++ -c -Wall -pedantic main.cpp

algorytmy.o: algorytmy.hh algorytmy.cpp
	g++ -c -Wall -pedantic algorytmy.cpp
