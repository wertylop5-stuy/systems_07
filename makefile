rand: main.o
	gcc -o rand main.o
	make clean

main.o:
	gcc -c main.c

clean:
	rm *.o

run:
	./rand
