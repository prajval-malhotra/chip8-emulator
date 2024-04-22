CC = g++
CFLAGS = -I src/include
LDFLAGS = -L src/lib
LIBS = -lmingw32 -lSDL2main -lSDL2

# List all your source files
SRCS = main.cpp

# Derive object files from source files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = main

# Compilation rule to build object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Phony target to clean up object files and the executable
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
