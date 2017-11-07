all:    Bragi

Bragi:   Bragi.o
	g++ -std=c++11 -o Bragi Bragi.o

Bragi.o: Bragi.cpp Bragi.h
	g++ -std=c++11 -c Bragi.cpp

clean: 
	rm -f Bragi Bragi.o

