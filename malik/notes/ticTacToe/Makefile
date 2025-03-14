CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

TARGET = ticTacToe
SRCS = main.cc ticTacToe.cc
OBJS = $(SRCS:.cc=.o)
DEPS = ticTacToe.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
