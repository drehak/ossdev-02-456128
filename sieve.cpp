// Copyright 2022 Dominik Rehak

#include <algorithm>
#include <iterator>

#include "./sieve.h"

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
        [min](int i) { return i >= min; });
    std::vector<int> slice;
    std::copy(begin, whole_sieve.cend(), std::back_inserter(slice));
    return slice;
}
