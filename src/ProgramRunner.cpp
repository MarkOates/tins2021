

#include <ProgramRunner.hpp>
#include <iostream>
#include <string>




ProgramRunner::ProgramRunner()
{
}


ProgramRunner::~ProgramRunner()
{
}


std::string ProgramRunner::run()
{
   std::string text_to_output = "Hello World!";
   std::cout << text_to_output << std::endl;
   return text_to_output;
}


