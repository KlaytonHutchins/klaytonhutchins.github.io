CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
LDFLAGS= -lcurl
EXENAME= generateFiles

default: main.o Case.o
	$(CC) main.o Case.o -o $(EXENAME) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Case.o: Case.cpp
	$(CC) $(CFLAGS) Case.cpp

clean:
	rm -f *.o $(EXENAME)

run:
	./$(EXENAME)

