CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
LDFLAGS= -lcurl
EXENAME= generateFiles

default: main.o DoublyLL.o Nodes.o newClasses.o
	$(CC) main.o -o DoublyLL.o Nodes.o newClasses.o -o $(EXENAME) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

DoublyLL.o: DoublyLL.cpp
	$(CC) $(CFLAGS) DoublyLL.cpp

Nodes.o: Nodes.cpp
	$(CC) $(CFLAGS) Nodes.cpp

newClasses.o: newClasses.cpp
	$(CC) $(CFLAGS) newClasses.cpp

clean:
	rm -f *.o $(EXENAME)

run:
	./$(EXENAME)

