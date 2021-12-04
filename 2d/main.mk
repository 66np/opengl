CC = g++

HPP = shapes.hpp text.hpp

CPP = main.cpp

OBJ = main.o

main: $(OBJ)
	$(CC) $(OBJ) -o main -lglut -lGL -lGL
	
main.o: $(CPP) $(HPP)
	$(CC) -c $(CPP)
	
clean:
	rm *.o main
