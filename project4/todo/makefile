all: dep
	gcc -c *c
	gcc -o queue mm.o list.o list_ptr.o queue.o queue_ptr.o main_queue.o

dep:
	gcc -MM *c > depend

clean:
	rm -f *o queue depend
