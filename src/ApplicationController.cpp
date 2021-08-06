

#include <ApplicationController.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>




ApplicationController::ApplicationController()
{
}


ApplicationController::~ApplicationController()
{
}


std::string ApplicationController::run_program()
{
   al_init();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   al_clear_to_color(al_color_name("green"));
   al_flip_display();
   sleep(1);
   return "Hello World!";
}


