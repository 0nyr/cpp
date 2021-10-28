# Custom Game of life

> Validated 🌟

### Useful links

[URL | codingame](https://www.codingame.com/training/easy/custom-game-of-life)

##### basic code

[Pass a 2D array to a function in C++](https://www.tutorialspoint.com/Passing-two-dimensional-array-to-a-Cplusplus-function)

[Delete (unnalloc) 2D array](https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array)

[Different methods for instantiating an object in C++](https://stackoverflow.com/questions/677632/different-methods-for-instantiating-an-object-in-c)

##### std

### TODOs

* [X] Finish the run function, that does the computations nessary to pass from a state i to state i+1. Need to implement if/switch cases for every rules
* [X] Fix the neighbour count function, it's currently broken

## Notes

##### pass a 2D array to a function

```cpp
void processArr(int **a) {
   // Do Something
}
// When calling:
int **array;
array = new int *[10];
for(int i = 0; i <10; i++)
   array[i] = new int[10];
processArr(array);
```

##### instatiate objects in C++

The `new` operator returns a pointer to the object it creates, so the expression `Myclass object = new Myclass();` is invalid.

```cpp
Myclass *object = new Myclass(); //object has dynamic storage duration (usually is on the heap)
Myclass object; //object has automatic storage duration (usually is on the stack)
```
