# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
COVERAGE_FLAGS = --coverage -fprofile-arcs -ftest-coverage
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
          Textbox.cpp\
          ExportCanvas.cpp\
          PDFExporter.cpp\
          PNGExporter.cpp

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
          Textbox.h\
          ExportCanvas.h\
          PNGExporter.h\
          PDFExporter.h

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

# Coverage version with gcov support
coverage: CXXFLAGS += $(COVERAGE_FLAGS)
coverage: $(TARGET)

# Run coverage analysis
run-coverage: coverage
	./$(TARGET)
	@echo "\n=== Generating Coverage Report ==="
	gcov $(SOURCES)
	@echo "\nCoverage files generated with .gcov extension"
	@echo "\n=== Coverage Summary ==="
	@for file in *.gcov; do \
		if [ -f "$$file" ]; then \
			echo "----------------------------------------"; \
			echo "File: $$file"; \
			head -3 "$$file" | tail -1; \
			echo "Lines covered:"; \
			grep -c "    [0-9]" "$$file" || echo "0"; \
			echo "Lines not covered:"; \
			grep -c "####" "$$file" || echo "0"; \
		fi \
	done
	@echo "----------------------------------------"

# Generate HTML coverage report (requires lcov)
coverage-html: coverage
	./$(TARGET)
	@echo "=== Generating HTML Coverage Report ==="
	@if command -v lcov >/dev/null 2>&1; then \
		lcov --capture --directory . --output-file coverage.info --quiet; \
		lcov --remove coverage.info '/usr/*' --output-file coverage.info --quiet; \
		genhtml coverage.info --output-directory coverage_html --quiet; \
		echo "✓ HTML coverage report generated in coverage_html/ directory"; \
		echo "✓ Open coverage_html/index.html in your browser"; \
	else \
		echo "❌ lcov not found. Install with:"; \
		echo "   Ubuntu/Debian: sudo apt-get install lcov"; \
		echo "   macOS: brew install lcov"; \
		echo "   Fedora/CentOS: sudo yum install lcov"; \
	fi

# Quick coverage check - just show percentages
coverage-quick: coverage
	./$(TARGET)
	@echo "=== Quick Coverage Summary ==="
	@gcov $(SOURCES) | grep -E "(File|Lines executed)" | paste - - | \
		awk '{gsub(/File ./, "", $$1); gsub(/.cpp.gcov/, "", $$1); printf "%-20s %s\n", $$1":", $$4 " " $$5 " " $$6}'

# Test coverage with different scenarios (if you have test cases)
test-coverage: coverage
	@echo "=== Running Test Coverage ==="
	@if [ -f "test_scenarios.txt" ]; then \
		while read -r scenario; do \
			echo "Testing scenario: $$scenario"; \
			echo "$$scenario" | ./$(TARGET); \
		done < test_scenarios.txt; \
	else \
		echo "Running default test..."; \
		./$(TARGET); \
	fi
	@echo "=== Generating Coverage Report ==="
	gcov $(SOURCES) > coverage_summary.txt
	@echo "Coverage report saved to coverage_summary.txt"

# Clean coverage files
clean-coverage:
	rm -f *.gcov *.gcda *.gcno coverage.info coverage_summary.txt
	rm -rf coverage_html

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Clear (alias for clean)
clear: clean

# Clean everything including coverage files
clean-all: clean clean-coverage

# Force rebuild
rebuild: clean all

# Force rebuild with coverage
rebuild-coverage: clean-all coverage

# Install dependencies (if needed)
install:
	@echo "Checking for coverage dependencies..."
	@if command -v gcov >/dev/null 2>&1; then \
		echo "✓ gcov found"; \
	else \
		echo "❌ gcov not found (should come with gcc)"; \
	fi
	@if command -v lcov >/dev/null 2>&1; then \
		echo "✓ lcov found"; \
	else \
		echo "❌ lcov not found - needed for HTML reports"; \
		echo "Install with: sudo apt-get install lcov (Ubuntu/Debian)"; \
	fi

# Show help
help:
	@echo "Available targets:"
	@echo "  all            - Build the program (default)"
	@echo "  run            - Build and run the program"
	@echo "  debug          - Build with debugging symbols and sanitizers"
	@echo "  run-debug      - Build and run debug version"
	@echo "  coverage       - Build with coverage instrumentation"
	@echo "  run-coverage   - Build and run detailed coverage analysis"
	@echo "  coverage-html  - Generate HTML coverage report (requires lcov)"
	@echo "  coverage-quick - Quick coverage percentage summary"
	@echo "  test-coverage  - Run coverage with test scenarios"
	@echo "  clean          - Remove all generated files"
	@echo "  clear          - Alias for clean"
	@echo "  clean-all      - Clean everything including coverage files"
	@echo "  clean-coverage - Remove only coverage files"
	@echo "  rebuild        - Clean and build"
	@echo "  rebuild-coverage - Clean all and rebuild with coverage"
	@echo "  install        - Check for coverage dependencies"
	@echo "  help           - Show this help message"
	@echo ""
	@echo "Coverage workflow:"
	@echo "  1. make coverage-quick    # Quick percentage overview"
	@echo "  2. make run-coverage      # Detailed text report"
	@echo "  3. make coverage-html     # Beautiful HTML report"

# Phony targets (not real files)
.PHONY: all run debug run-debug coverage run-coverage coverage-html coverage-quick test-coverage clean clear clean-all clean-coverage rebuild rebuild-coverage install help