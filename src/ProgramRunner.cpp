

#include <ProgramRunner.hpp>
#include <iostream>
#include <string>
#include <ApplicationController.hpp>




ProgramRunner::ProgramRunner()
{
}


ProgramRunner::~ProgramRunner()
{
}


std::string ProgramRunner::run()
{
   ApplicationController application_controller;
   application_controller.run_program();
   return "Hello World!";
}


