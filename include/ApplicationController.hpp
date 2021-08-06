#pragma once


#include <allegro5/allegro.h>


class ApplicationController
{
private:
   ALLEGRO_DISPLAY* display;
   ALLEGRO_EVENT_QUEUE* event_queue;
   ALLEGRO_TIMER* primary_timer;
   ALLEGRO_EVENT_SOURCE user_event_source;
   bool shutdown_program;

public:
   ApplicationController();
   ~ApplicationController();

   void initialize_allegro_config_display_event_queue_and_timer();
   void initialize();
   void shutdown();
   void emit_user_event(ALLEGRO_EVENT user_event={});
   void run_program();
   void run_event_loop();
};



