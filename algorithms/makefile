CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
LDFLAGS= -lcurl
EXENAME= generateFiles

default: main.o DoublyLL.o Node.o Case.o
	$(CC) main.o DoublyLL.o Node.o Case.o -o $(EXENAME) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp

Case.o: Case.cpp
	$(CC) $(CFLAGS) Case.cpp

clean:
	rm -f *.o $(EXENAME)

run:
	./$(EXENAME)

