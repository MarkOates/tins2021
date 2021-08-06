
#include <gtest/gtest.h>

#include <Player.hpp>

TEST(PlayerTest, can_be_created_without_blowing_up)
{
   Player player;
}

TEST(PlayerTest, run__returns_the_expected_response)
{
   Player player;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, player.run());
}
