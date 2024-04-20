# Makefile for compiling C++ program

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -g

# Files
SOURCES = main.cpp parser.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = parser

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

# Declare non-file targets
.PHONY: all clean
