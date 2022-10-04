# echo -e colors
# WARN : don't put " and use the echo command, not echo -e
LIGHT_ORANGE_COLOR=\e[38;5;216m
TURQUOISE_COLOR=\e[38;5;43m
LIGHT_BLUE_COLOR=\e[38;5;153m
RED_COLOR=\e[38;5;196m
NO_COLOR=\e[0m

# vars
ECHO = @echo # @echo hides this command in terminal, not its output

BIN=bin/main
INCLUDE=include/

CC=g++
CFLAGS=-I $(INCLUDE) -march=native -O3
LDLIBS=
LDFLAGS=--ansi --pedantic -Wall --std=c++11

SRCS=$(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJS=$(SRCS:src/%.cpp=obj/%.o)

# rules
## src compile rules
default: compile

compile: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

obj/%.o: src/%.cpp 
	$(CC) -o $@ -c $^ $(CFLAGS)


clean:
	rm -rf bin/* obj/*

run: $(BIN)
	$(ECHO) "$(TURQUOISE_COLOR)*** Executing code *** $(NO_COLOR)"
	./$(BIN)

test: $(BIN)
	cat tests/std.in | ./$(BIN)

dirs:
	mkdir -p bin/
	mkdir -p obj/
	mkdir -p lib/
	mkdir -p src/
	mkdir -p include/

.PHONY: clean run dirs default compile
