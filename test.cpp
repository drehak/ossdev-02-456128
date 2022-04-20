// Copyright 2022 Dominik Rehak

#include <vector>

#define CUT_MAIN
#include "./cut.h"
#include "./sieve.h"

TEST(basic_sieve) {
    std::vector<int> result = sieve(20);
    std::vector<int> expected = { 2, 3, 5, 7, 11, 13, 17, 19 };
    ASSERT(result == expected);
}

TEST(basic_sliced_sieve) {
    std::vector<int> result = sliced_sieve(10, 20);
    std::vector<int> expected = { 11, 13, 17, 19 };
    ASSERT(result == expected);
}

TEST(basic_sliced_sieve_empty) {
    std::vector<int> result = sliced_sieve(20, 10);
    std::vector<int> expected = { };
    ASSERT(result == expected);
}

#define main sieve_main
#include "./main.cpp"
#undef main

TEST(sieve_correct) {
    // https://stackoverflow.com/a/29338386
    char argv0[] = "./sieve";
    char *argv[] = { argv0, NULL };
    INPUT_STRING(
        "10\n"
        "20\n");

    int ret = sieve_main(1, argv);

    ASSERT(ret == 0);
    ASSERT_FILE(stdout,
        "11\n"
        "13\n"
        "17\n"
        "19\n");
}

TEST(sieve_help_short) {
    char argv0[] = "./sieve";
    char argv1[] = "-h";
    char *argv[] = { argv0, argv1, NULL };

    int ret = sieve_main(2, argv);

    ASSERT(ret == 0);
}

TEST(sieve_help_long) {
    char argv0[] = "./sieve";
    char argv1[] = "--help";
    char *argv[] = { argv0, argv1, NULL };

    int ret = sieve_main(2, argv);

    ASSERT(ret == 0);
}

TEST(sieve_wrong_arguments_1) {
    char argv0[] = "./sieve";
    char argv1[] = "--foo";
    char *argv[] = { argv0, argv1, NULL };

    int ret = sieve_main(2, argv);

    ASSERT(ret != 0);
    ASSERT_FILE(stderr,
        "Unrecognized arguments\n");
}

TEST(sieve_wrong_arguments_2) {
    char argv0[] = "./sieve";
    char argv1[] = "10";
    char argv2[] = "20";
    char *argv[] = { argv0, argv1, argv2, NULL };

    int ret = sieve_main(3, argv);

    ASSERT(ret != 0);
    ASSERT_FILE(stderr,
        "Unrecognized arguments\n");
}

TEST(sieve_wrong_input_1) {
    char argv0[] = "./sieve";
    char *argv[] = { argv0, NULL };
    INPUT_STRING(
        "10\n");

    int ret = sieve_main(1, argv);

    ASSERT(ret != 0);
    ASSERT_FILE(stderr,
        "Input error\n");
}
