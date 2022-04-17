#include <algorithm>
#include <iostream>
#include <iterator>
#include <string.h>
#include <vector>

std::vector<int> sieve(int max) {
    std::vector<int> primes;
    for (int i = 2; i <= max; i++) {
        bool is_prime = true;
        for (int p : primes) {
            if (p * p > i) {
                break;
            }
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
    return primes;
}

std::vector<int> sliced_sieve(int min, int max) {
    std::vector<int> whole_sieve = sieve(max);
    std::vector<int>::const_iterator begin = std::find_if(
        whole_sieve.cbegin(),
        whole_sieve.cend(),
        [min](int i) { return i >= min; }
    );
    std::vector<int> slice;
    std::copy(begin, whole_sieve.cend(), std::back_inserter(slice));
    return slice;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
            std::cerr << "Usage: sieve [-h|--help]" << std::endl;
            std::cerr << "Provide two integers on standard input (one or two lines)." << std::endl;
            return 0;
        }
        std::cerr << "Unrecognized arguments" << std::endl;
        return 1;
    }

    int min, max;
    std::cin >> min;
    std::cin >> max;
    if (!std::cin.good()) {
        std::cerr << "Input error" << std::endl;
        return 1;
    }
    for (int p : sliced_sieve(min, max)) {
        std::cout << p << std::endl;
    }
    return 0;
}
