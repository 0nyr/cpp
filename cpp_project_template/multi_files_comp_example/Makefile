BIN=bin/main
INCLUDE=inc/

CC=g++
CFLAGS=-I $(INCLUDE) -march=native -O3 -D MAP -D NDEBUG
LDLIBS=
LDFLAGS=--ansi --pedantic -Wall --std=c++11

SRCS=$(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJS=$(SRCS:src/%.cpp=obj/%.o)

# targets
# set default target : https://stackoverflow.com/questions/2057689/how-does-make-app-know-default-target-to-build-if-no-target-is-specified
.DEFAULT_GOAL := default
.PHONY: default build clean run rebuild dirs all

default: build

build: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CFLAGS)

obj/model/%.o: src/model/%.cpp
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rf bin/* obj/*

run: $(BIN)
	./$(BIN)


# Determine this makefile's path.
# Be sure to place this BEFORE `include` directives, if any.
THIS_FILE := $(lastword $(MAKEFILE_LIST))

rebuild:
	@$(MAKE) -f $(THIS_FILE) clean
	@$(MAKE) -f $(THIS_FILE) build

all: 
	@$(MAKE) -f $(THIS_FILE) clean
	@$(MAKE) -f $(THIS_FILE) build
	@$(MAKE) -f $(THIS_FILE) run


dirs:
	mkdir -p bin/
	mkdir -p obj/
	mkdir -p lib/
	mkdir -p src/
	mkdir -p inc/
