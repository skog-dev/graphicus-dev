main: main.o
	g++ -o main main.o

main.o: main.cpp vector.h 
	g++ -c main.cpp

dev:
	make
	./main

clean:
	rm -f *.o
	rm -f main