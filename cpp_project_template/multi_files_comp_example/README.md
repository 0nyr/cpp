# Cpp small project

### Useful links

[Est (good) const vs West (bad) const](https://hackingcpp.com/cpp/design/east_vs_west_const.html)

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
