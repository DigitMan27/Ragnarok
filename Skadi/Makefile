Skadi: Main.o Skadi.o
	g++ Main.o Skadi.o -o Skadi
Main.o: Main.cpp
	g++ -c Main.cpp
Skadi.o: Skadi.cpp Skadi.h
	g++ -c Skadi.cpp
clean:
	rm -f Skadi
	rm -f *.o