#include <gtest/gtest.h>

#include "example.h"

TEST(AddTest, HandlesPositiveNumbers) {
  EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, HandlesNegativeNumbers) {
  EXPECT_EQ(add(-2, 5), 3);
}
