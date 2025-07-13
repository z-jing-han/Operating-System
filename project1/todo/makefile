CXX	= g++
CFLAGS	= -Wall -g

PROGS	= shell

all: $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $<

clean:
	rm -f *~ $(PROGS)