main:main.o
	g++ -g main.o -o main

main.o:main.cpp
	g++ -g -c main.cpp -o main.o

.PHONY:clean,run
clean:
	-rm main *.o
	clear

run:
	./main
