# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = shapestest

# Source files
SOURCES = shapestest.cpp \
          Canvas.cpp \
          Storage.cpp \
          ShapeFactory.cpp \
          SquareFactory.cpp \
          RectangleFactory.cpp \
          TextboxFactory.cpp \
          Shape.cpp \
          Square.cpp \
          Rectangle.cpp \
          Textbox.cpp

# Object files (derived from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Header dependencies (add your .h files here)
HEADERS = Canvas.h \
          Storage.h \
          ShapeFactory.h \
          SquareFactory.h \
          RectangleFactory.h \
          TextboxFactory.h \
          Shape.h \
          Square.h \
          Rectangle.h \
          Textbox.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug version with AddressSanitizer
debug: CXXFLAGS += -fsanitize=address -fsanitize=undefined
debug: $(TARGET)

# Run debug version
run-debug: debug
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Clear (alias for clean)
clear: clean

# Force rebuild
rebuild: clean all

# Install dependencies (if needed)
install:
	@echo "No external dependencies to install"

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build the program (default)"
	@echo "  run        - Build and run the program"
	@echo "  debug      - Build with debugging symbols and sanitizers"
	@echo "  run-debug  - Build and run debug version"
	@echo "  clean      - Remove all generated files"
	@echo "  clear      - Alias for clean"
	@echo "  rebuild    - Clean and build"
	@echo "  help       - Show this help message"

# Phony targets (not real files)
.PHONY: all run debug run-debug clean clear rebuild install help