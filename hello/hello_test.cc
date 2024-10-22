#include <gtest/gtest.h>
#include "hello.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_EQ(say_hello(), std::string("Hello"));

}