main: main.o layer.o shape.o rectangle.o circle.o square.o
	g++ -o main.out main.o layer.o shape.o rectangle.o circle.o square.o

main.o: main.cpp layer.o shape.o rectangle.o circle.o square.o
	g++ -c main.cpp

layer.o: layer.cpp layer.h shape.o 
	g++ -c layer.cpp

rectangle.o: rectangle.cpp rectangle.h shape.o
	g++ -c rectangle.cpp

circle.o: circle.cpp circle.h shape.o
	g++ -c circle.cpp

square.o: square.cpp square.h shape.o rectangle.o 
	g++ -c square.cpp

shape.o: shape.cpp shape.h
	g++ -c shape.cpp

dev:
	make
	./main.out

clean:
	rm -f *.o
	rm -f *.out