# makefile Project Analise empirica

all:
	mkdir -p bin
	g++ -Wall src/main.cpp src/searchAlgorithm.cpp -o bin/main

run:
	./bin/main
