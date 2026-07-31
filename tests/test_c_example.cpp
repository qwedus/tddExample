#include <gtest/gtest.h>

extern "C" {
#include "c_example.h"
}

TEST(CExampleTest, AddInts) {
  EXPECT_EQ(add_ints(2, 3), 5);
}

TEST(CExampleTest, MultiplyInts) {
  EXPECT_EQ(multiply_ints(4, 5), 20);
}

TEST(FizzBuzz,testFizz)
{
    ASSERT_EQ(fizzbuzz(3), 300);
}

TEST(FizzBuzz,testBuzz)
{
    ASSERT_EQ(fizzbuzz(5), 500);
}
TEST(FizzBuzzTest, TestFizzBuzz)
{
    ASSERT_EQ(fizzbuzz(15), 15000); // Fizz takes precedence
}