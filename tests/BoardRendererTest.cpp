
#include <gtest/gtest.h>

#include <BoardRenderer.hpp>

TEST(BoardRendererTest, can_be_created_without_blowing_up)
{
   BoardRenderer board_renderer;
}

TEST(BoardRendererTest, run__returns_the_expected_response)
{
   BoardRenderer board_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, board_renderer.run());
}
