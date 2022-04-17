#include "sieve.h"

#include <vector>

#include <CppUTest/CommandLineTestRunner.h>

TEST_GROUP(TestGroup)
{
};

TEST(TestGroup, BasicSieve)
{
   std::vector<int> result = sieve(20);
   std::vector<int> expected = { 2, 3, 5, 7, 11, 13, 17, 19 };
   CHECK(result == expected);
}

TEST(TestGroup, BasicSlicedSieve)
{
   std::vector<int> result = sliced_sieve(10, 20);
   std::vector<int> expected = { 13, 17, 19 };
   CHECK(result == expected);
}

int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}
