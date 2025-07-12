all: *.c dep 
	gcc -c philosopher.c
	gcc -pthread -o philosopher philosopher.o
dep:
	gcc -MM *.c > depend
clean:
	rm -f philosopher depend *.o
