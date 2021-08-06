
#include <gtest/gtest.h>

#include <ProgramRunner.hpp>

TEST(ProgramRunnerTest, can_be_created_without_blowing_up)
{
   ProgramRunner program_runner;
}

TEST(ProgramRunnerTest, run__returns_the_expected_response)
{
   ProgramRunner program_runner;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, program_runner.run());
}
