main: main.o
	g++ -o main.out main.o

main.o: main.cpp vector.h couche.h 
	g++ -c main.cpp

dev:
	make
	./main.out

clean:
	rm -f *.o
	rm -f *.out