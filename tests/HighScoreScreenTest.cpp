
#include <gtest/gtest.h>

#include <HighScoreScreen.hpp>

TEST(HighScoreScreenTest, can_be_created_without_blowing_up)
{
   HighScoreScreen high_score_screen;
}

TEST(HighScoreScreenTest, run__returns_the_expected_response)
{
   HighScoreScreen high_score_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, high_score_screen.run());
}
