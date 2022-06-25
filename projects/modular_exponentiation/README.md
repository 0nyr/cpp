# Finding the modular multiplicative inverse of a modulo n

### Useful links

[Modular Multiplicative Inverse | Wikipedia](https://en.wikipedia.org/wiki/Modular_multiplicative_inverse#Computation)

[Extended Euclidean Algorithm | Wikipedia](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm) contains useful pseudo-code

[How to find Multiplicative Inverse of a number modulo M?](https://www.rookieslab.com/posts/how-to-find-multiplicative-inverse-of-a-number-modulo-m-in-python-cpp) ⭐️

### cpp

[Converting char* to long](https://linux.die.net/man/3/strtoll)


## Notes

Pseudo-code for the function allowing to compute the Modular Multiplicative Inverse, to be used to compute the modular exponentiation used in RSA and Diffie-Hellman cryptographyc algorithms.

```
 function inverse(a, n)
    t := 0;     newt := 1
    r := n;     newr := a

    while newr ≠ 0 do
        quotient := r div newr
        (t, newt) := (newt, t − quotient × newt) 
        (r, newr) := (newr, r − quotient × newr)

    if r > 1 then
        return "a is not invertible"
    if t < 0 then
        t := t + n

    return t
```


## Using the program

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ modular_exponentiation❯❯ ./bin/main 79 3220
a = 79
n = 3220
modular multiplicative inverse t of a modulo m = 1019
```
