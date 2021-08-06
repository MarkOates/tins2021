
#include <gtest/gtest.h>

#include <GameplayScreen.hpp>

TEST(GameplayScreenTest, can_be_created_without_blowing_up)
{
   GameplayScreen gameplay_screen;
}

TEST(GameplayScreenTest, run__returns_the_expected_response)
{
   GameplayScreen gameplay_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, gameplay_screen.run());
}
