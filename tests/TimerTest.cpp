
#include <gtest/gtest.h>

#include <Timer.hpp>

TEST(TimerTest, can_be_created_without_blowing_up)
{
   Timer timer;
}

TEST(TimerTest, run__returns_the_expected_response)
{
   Timer timer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, timer.run());
}
