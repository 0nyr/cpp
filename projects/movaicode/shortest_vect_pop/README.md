# Shortest way to pop an element of a list

Inspired from [this](https://github.com/CoddityTeam/movaicode/issues/172) GitHub issue, for Coddity Movaicode contest.

If we use a `std::vector<> a` to represent our list, which is the common practice, we end up with the following simple C++ lambda:

```cpp
[&]{a.pop_back();}();
```

The `[&]` means the lambda has access to local variable by reference, here `a`. Then we just use the built-in `pop_back()` function from `<vector>`. We add `()` to call the execution of the lambda.

This is a bit long (21 bytes). However the majority of the bytes are taken by the name of the pop function of the vector, taking 8 bytes just for its name.

So we just create a wrapper object, and define a wrapping function with one-letter name in order to decrease the length in byte of our lambda.

```cpp
class VectorWrapper {
    public:
        std::vector<int> vect;
        VectorWrapper() {};
        void p() {
            vect.pop_back();
        }
};
```

Now, we simply correct our lambda:

```cpp
[&]{a.p();}();
```

Now we just have **14 bytes** remaining.
