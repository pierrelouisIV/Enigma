run: main
	./main

main: main.o rotors.o tableaux.o
	gcc -Wall -o main main.o rotors.o tableaux.o

rotors.o: rotors.c rotors.h
	gcc -c rotors.c

tableaux.o: tableaux.c tableaux.h
	gcc -c tableaux.c
	
main.o: main.c rotors.h tableaux.h
	gcc -Wall -c main.c

clean:
	rm *.o
	rm main
