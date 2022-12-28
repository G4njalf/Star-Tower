all: main
main: Main.cpp
all: main
main: Main.cpp
	g++ -std=c++11 Main.cpp -lncurses -o test -pthread

clean:
	rm -rf *.o