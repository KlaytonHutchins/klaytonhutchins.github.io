CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
LDFLAGS= -lcurl -framework CoreFoundation -framework SystemConfiguration
EXENAME= kryptos

default: main.o
	$(CC) main.o -o $(EXENAME) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o $(EXENAME)

run:
	./$(EXENAME)

