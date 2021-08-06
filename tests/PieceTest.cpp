
#include <gtest/gtest.h>

#include <Piece.hpp>

TEST(PieceTest, can_be_created_without_blowing_up)
{
   Piece piece;
}

TEST(PieceTest, run__returns_the_expected_response)
{
   Piece piece;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, piece.run());
}
