# makefile Project Analise empirica

all:
	mkdir -p bin
	g++ -Wall -c src/searchAlgorithm.cpp -o bin/search.o
	g++ -Wall src/main.cpp bin/search.o -o bin/main
run:
	./bin/main
