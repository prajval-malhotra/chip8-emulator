CC = g++
CFLAGS = -I SDL/include -I include/
LDFLAGS = -L SDL/lib
LIBS = -lmingw32 -lSDL2main -lSDL2

# Source directory
SRC_DIR = src
# Build directory
BUILD_DIR = build

# List all your source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Derive object files from source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Derive dependency files from source files
DEPS = $(OBJS:.o=.d)

# Target executable
TARGET = run

# Compilation rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Rule to build the target executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Create build directory
$(BUILD_DIR):
	mkdir -p $@

# Phony target to clean up object files and the executable
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEPS)
