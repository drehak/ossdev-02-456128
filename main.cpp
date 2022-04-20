// Copyright 2022 Dominik Rehak

#include <string.h>
#include <iostream>
#include <iterator>

#include "./sieve.h"

int main(int argc, char **argv) {
    if (argc > 1) {
        if (argc == 2 && (strcmp(argv[1], "-h") == 0
                || strcmp(argv[1], "--help") == 0)) {
            std::cerr << "Usage: sieve [-h|--help]" << std::endl
                      << "Provide two integers on standard input"
                      << " (one or two lines)." << std::endl;
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
