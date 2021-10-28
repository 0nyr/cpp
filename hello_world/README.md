# Simple Hello World

#### Direct compilation and linking possible for single file:

`g++ -o hello Hello.cpp`: compile and link

```shell
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ g++ -o hello Hello.cpp 
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ ./hello 
Hello World!
```

#### Separate compilation and linking

`g++ -o Hello.o -c Hello.cpp`: compilation

`g++ -o hello_from_o Hello.o`: linking

```shell
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ g++ -o Hello.o -c Hello.cpp 
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ g++ -o hello_from_o Hello.o 
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ ./hello
hello         hello_from_o  
(base) onyr@aezyr:~/Documents/code/cpp/hello_world$ ./hello_from_o 
Hello World!
```
