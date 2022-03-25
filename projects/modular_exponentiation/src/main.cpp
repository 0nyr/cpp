#include <iostream>
#include <exception>

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

struct NotInvertibleException : public std::exception {
	const char * what () const throw () {
    	return "a is not invertible";
    }
};

/**
 * @brief Compute the modular multiplicative inverse of a modulo m
 * 
 * @param a the number to invert
 * @return double the modular multiplicative inverse of a modulo m
 */
long inverse(long a, long n) {
    long t = 0;
    long newt = 1;
    long r = n;
    long newr = a;

    while (newr != 0) {
        long q = r/newr; // WARN: integer division !!!

        long tmp_newt = newt;
        newt = t - q*newt;
        t = tmp_newt;

        long tmp_newr = newr;
        newr = r - q*newr;
        r = tmp_newr;
    }

    if (r > 1) {
        throw NotInvertibleException();
    }

    if (t < 0) {
        t += n;
    }
    return t;
}

int main(int argc, char** argv)
{
    int base = 10;
    char *endptr;

    // check arguments
    if (argc < 3) {
        std::cout << "Use program: ./main a n" << std::endl;
        std::cout << "a is the number that we want to get it modular multiplicative inverse" << std::endl;
        std::cout << "n is the modulo" << std::endl;
        return EXIT_FAILURE;
    }

    // compute modular multiplicative inverse t of a modulo n
    // using strol for char* to long conversion : https://linux.die.net/man/3/strtoll
    long a = strtol(argv[1], &endptr, base);
    long n = strtol(argv[2], &endptr, base);
    std::cout << "a = " << a << std::endl;
    std::cout << "n = " << n << std::endl;

    long t = inverse(a, n);
    std::cout << "modular multiplicative inverse t of a modulo m = " << t << std::endl;

    return 0;
}