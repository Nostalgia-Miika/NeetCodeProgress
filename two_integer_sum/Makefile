# Define variables
CXX := g++
CXXFLAGS := -std=c++20
FORMAT := clang-format
FORMAT_STYLE := Microsoft
TARGET := app.out
SRC := *.cpp

# Phony targets
.PHONY: all run main format clean

# Default target
all: run

# Run the application
run: main
	./$(TARGET)

# Build the application
main: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Format the source code
format:
	$(FORMAT) -style=$(FORMAT_STYLE) -i $(SRC)

# Clean up build artifacts
clean:
	rm $(TARGET)