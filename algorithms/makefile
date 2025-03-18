CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
LDFLAGS= -lcurl
EXENAME= generateFiles

default: main.o DoublyLL.o Nodes.o
	$(CC) main.o DoublyLL.o Nodes.o -o $(EXENAME) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Nodes.o: Nodes.cpp
	$(CC) $(CFLAGS) Nodes.cpp

clean:
	rm -f *.o $(EXENAME)

run:
	./$(EXENAME)

