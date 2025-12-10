# Makefile for Harlington Bank Management System
# Author: Your Name
# Date: December 2025

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Target executable
TARGET = bank_system

# Source files
SOURCES = src/The_Bank.cpp src/utilities.cpp src/main.cpp

# Object files
OBJECTS = The_Bank.o utilities.o main.o

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile The_Bank.cpp
The_Bank.o: src/The_Bank.cpp include/The_Bank.h
	$(CXX) $(CXXFLAGS) -c src/The_Bank.cpp

# Compile utilities.cpp
utilities.o: src/utilities.cpp include/The_Bank.h
	$(CXX) $(CXXFLAGS) -c src/utilities.cpp

# Compile main.cpp
main.o: src/main.cpp include/The_Bank.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Cleaned up build files"

# Clean and rebuild
rebuild: clean all

# Create necessary directories
setup:
	mkdir -p include src data docs
	@echo "Directory structure created"

# Display help
help:
	@echo "Harlington Bank Management System - Makefile"
	@echo "=============================================="
	@echo "Available targets:"
	@echo "  make          - Compile the program"
	@echo "  make run      - Compile and run the program"
	@echo "  make clean    - Remove compiled files"
	@echo "  make rebuild  - Clean and recompile"
	@echo "  make setup    - Create directory structure"
	@echo "  make help     - Display this help message"

.PHONY: all run clean rebuild setup help