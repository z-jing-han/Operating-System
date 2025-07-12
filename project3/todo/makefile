CXX = g++
CXXFLAGS = -g -Wall -pthread
TARGET = philosopher
OBJS = philosopher.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

dep:
	$(CXX) -MM *.cpp > depend

clean:
	rm -f $(TARGET) depend *.o
