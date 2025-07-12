all: *.c dep
	gcc -c *.c
	gcc -o read read.o
	gcc -o write write.o
dep:
	gcc -MM *.c > depend
clean:
	rm -f read write depend *.o
