# Cpp small project

### Useful links

[Est (good) const vs West (bad) const](https://hackingcpp.com/cpp/design/east_vs_west_const.html)

## Use this template

This template is made to be used with a single file, as it is often the case for short algorithmic problems such as on online coding challenges and technical interviews.

1. Copy the Makefile at the root of the new project.
2. Run `make dirs` to create compilation directories.
3. Put the code in a `.cpp` file at top level or inside `src/`
4. Run the code with `make all`

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ mono_file_comp_example❯❯ make dirs
mkdir -p bin/
mkdir -p obj/
(base)  ❮ onyr ★  kenzae❯ ❮ mono_file_comp_example❯❯ make all
make[1]: Entering directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
rm -rf bin/* obj/*
make[1]: Leaving directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
make[1]: Entering directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
g++ -o bin/main Main.cpp --ansi --pedantic -Wall --std=c++11 
make[1]: Leaving directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
make[1]: Entering directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
./bin/main
Hello World!
make[1]: Leaving directory '/home/onyr/Documents/code/cpp/cpp_project_template/mono_file_comp_example'
```


## compile and run

### For a simple unique .cpp file

`g++ -o <output name> [list of .cpp files]`: compile using  `gcc` command

Run directly the executable

```shell
(base) onyr@aezyr:~/Documents/code/cpp$ g++ -o Hello Hello.cpp 
(base) onyr@aezyr:~/Documents/code/cpp$ ./Hello 
Hello World!
```

### When multiple .hpp and .cpp files

**Option 1**: Use a makefile to compile .cpp files to .o file, then do the linking a   nd build the executable.

**Option 2**: Do all the compilation and linking manually.

Compilation process:

`g++ -o obj/model/User.o -c src/model/User.cpp -I inc/`

`g++ -o obj/Main.o -c src/Main.cpp -I inc/`

Linking process:

`g++ -o bin/main obj/model/User.o obj/Main.o --std=c++11`
