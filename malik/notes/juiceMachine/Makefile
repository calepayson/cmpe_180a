CC = g++
CFLAGS = -Wall -g
TARGET = program

# Object files
OBJS = cashRegister.o dispenserType.o main.o sellProduct.o showSelection.o

# Default target
all: $(TARGET)

# Link all object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cc
main.o: main.cc cashRegister.h dispenserType.h sellProduct.h showSelection.h
	$(CC) $(CFLAGS) -c main.cc

# Compile cashRegister.cc
cashRegister.o: cashRegister.cc cashRegister.h
	$(CC) $(CFLAGS) -c cashRegister.cc

# Compile dispenserType.cc
dispenserType.o: dispenserType.cc dispenserType.h
	$(CC) $(CFLAGS) -c dispenserType.cc

# Compile sellProduct.cc with its dependencies
sellProduct.o: sellProduct.cc sellProduct.h cashRegister.h dispenserType.h
	$(CC) $(CFLAGS) -c sellProduct.cc

# Compile showSelection.cc
showSelection.o: showSelection.cc showSelection.h
	$(CC) $(CFLAGS) -c showSelection.cc

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
