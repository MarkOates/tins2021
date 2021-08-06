
#include <gtest/gtest.h>

#include <GameOverScreen.hpp>

TEST(GameOverScreenTest, can_be_created_without_blowing_up)
{
   GameOverScreen game_over_screen;
}

TEST(GameOverScreenTest, run__returns_the_expected_response)
{
   GameOverScreen game_over_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, game_over_screen.run());
}
