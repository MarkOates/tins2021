
#include <gtest/gtest.h>

#include <TitleScreen.hpp>

TEST(TitleScreenTest, can_be_created_without_blowing_up)
{
   TitleScreen title_screen;
}

TEST(TitleScreenTest, run__returns_the_expected_response)
{
   TitleScreen title_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, title_screen.run());
}
