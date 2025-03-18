CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++11
OBJECTS = BigInt.o
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJECTS) test.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) test.o $(OBJECTS)

BigInt.o: BigInt.cc BigInt.h
	$(CXX) $(CXXFLAGS) -c BigInt.cc

test.o: test.cc BigInt.h
	$(CXX) $(CXXFLAGS) -c test.cc

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
