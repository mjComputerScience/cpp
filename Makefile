# Main suffixes for auto compile by dependencies
.SUFFIXES : .cc .o

# Compiler and Compile options
CXX = g++
CXXFLAGS = -std=c++11 -g -W -I$(INCLUDE) 

# Directories' path
INCLUDE = include
#LIBDIR = 
BIN = bin/

# Source & Object files
SRCS = $(wildcard src/*.cc)
OBJS = $(SRCS:.cc=.o)
#LIBS = 

# Make executable file
all: program 

program: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN)$@ $(OBJS)

# User making actions
clean:
	rm $(BIN)* $(OBJS)

new:
	$(MAKE) clean
	$(MAKE)
