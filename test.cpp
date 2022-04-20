// Copyright 2022 Dominik Rehak

#include <vector>

#define CUT_MAIN
#include "./cut.h"
#include "./sieve.h"

TEST(BasicSieve) {
    std::vector<int> result = sieve(20);
    std::vector<int> expected = { 2, 3, 5, 7, 11, 13, 17, 19 };
    ASSERT(result == expected);
}

TEST(BasicSlicedSieve) {
    std::vector<int> result = sliced_sieve(10, 20);
    std::vector<int> expected = { 11, 13, 17, 19 };
    ASSERT(result == expected);
}

TEST(BasicSlicedSieve_empty) {
    std::vector<int> result = sliced_sieve(20, 10);
    std::vector<int> expected = { };
    ASSERT(result == expected);
}
