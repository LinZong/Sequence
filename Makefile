build.out : main.o Sequence.o
	g++ main.o Sequence.o -o build.out -std=gnu++11

main.o : main.cpp Sequence.h
	g++ -c main.cpp  Sequence.h -std=gnu++11


Sequence.o : Sequence.cpp  Sequence.h
	g++ -c Sequence.cpp Sequence.h -std=gnu++11
