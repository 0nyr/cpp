COMPILER = g++
ARCHITECTURE_FLAGS = -march=native

COMPILER_FLAGS = -std=c++20 -m64 -Wall -Wfatal-errors -O3 $(ARCHITECTURE_FLAGS)

# flags for debugging
DEBUG_FLAGS = -g -D DEBUG

all: main

main: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) -o main main.cpp

debug: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(DEBUG_FLAGS) -o main main.cpp

clean:
	rm -f main
