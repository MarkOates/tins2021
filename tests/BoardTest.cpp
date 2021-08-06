
#include <gtest/gtest.h>

#include <Board.hpp>

TEST(BoardTest, can_be_created_without_blowing_up)
{
   Board board;
}

TEST(BoardTest, run__returns_the_expected_response)
{
   Board board;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, board.run());
}
