

#include <ApplicationController.hpp>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>




ApplicationController::ApplicationController()
   : display(nullptr)
   , event_queue(nullptr)
   , primary_timer(nullptr)
   , user_event_source()
   , shutdown_program(false)
{
}


ApplicationController::~ApplicationController()
{
}


void ApplicationController::initialize_allegro_config_display_event_queue_and_timer()
{
   if (!al_init()) std::cerr << "al_init() failed" << std::endl;
   if (!al_init_font_addon()) std::cerr << "al_init_font_addon() failed" << std::endl;
   if (!al_init_ttf_addon()) std::cerr << "al_init_ttf_addon() failed" << std::endl;
   if (!al_init_primitives_addon()) std::cerr << "al_init_primitives_addon() failed" << std::endl;
   if (!al_init_image_addon()) std::cerr << "al_init_image_addon() failed" << std::endl;
   if (!al_install_keyboard()) std::cerr << "al_install_keyboard() failed" << std::endl;
   if (!al_install_mouse()) std::cerr << "al_install_mouse() failed" << std::endl;

   // config.initialize();

   al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
   al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
   al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
   al_set_new_display_flags(ALLEGRO_RESIZABLE);
   al_set_new_display_flags(ALLEGRO_NOFRAME);
   al_set_new_display_flags(ALLEGRO_NOFRAME | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
   al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
   //if (config.is_fullscreen()) al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

   al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
   //al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
   //display = al_create_display(
   //   config.get_initial_display_width(),
   //   config.get_initial_display_height());
   display = al_create_display(1920, 1080);
   if (!display) std::cerr << "al_create_display() failed" << std::endl;
   al_set_window_title(display, "Peri");

   int display_width = al_get_display_width(display);
   int display_height = al_get_display_height(display);

   event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_mouse_event_source());
   al_register_event_source(event_queue, al_get_display_event_source(display));

   primary_timer = al_create_timer(1.0/60.0);
   al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
   al_start_timer(primary_timer);

   al_init_user_event_source(&user_event_source);
   al_register_event_source(event_queue, &user_event_source);
}

void ApplicationController::initialize()
{
   initialize_allegro_config_display_event_queue_and_timer();
   //verify_presence_of_temp_files_and_assign_to_global_constants();

   //system = new System(display, config, motion);
   //system->initialize();
}

void ApplicationController::shutdown()
{
   al_destroy_event_queue(event_queue);
   al_destroy_display(display);
   //delete system;
   //al_uninstall_system();
}

void ApplicationController::emit_user_event(ALLEGRO_EVENT user_event)
{
   al_emit_user_event(&user_event_source, &user_event, NULL);
   return;
}

void ApplicationController::run_program()
{
   initialize();

   //AllegroFlare::FontBin font_bin;
   //font_bin.set_full_path("/Users/markoates/Repos/hexagon/bin/programs/data/fonts");
   //Hexagon::TitleScreen title_screen(&font_bin);
   //title_screen.initialize();
   //title_screen.draw_hexagon_logo_and_wait_for_keypress();
   //font_bin.clear();

   run_event_loop();
   shutdown();
}

void ApplicationController::run_event_loop()
{
   bool mouse_event_occurred_and_requires_screen_refresh = false;
   static int mouse_event_skip = 0;
   while(!shutdown_program)
   {
      ALLEGRO_EVENT this_event;
      al_wait_for_event(event_queue, &this_event);
      //global::profiler.clear();

      //system->process_event(this_event);

      bool refresh = true;

      switch(this_event.type)
      {
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
         shutdown_program = true;
         break;
      case ALLEGRO_EVENT_DISPLAY_RESIZE:
         al_acknowledge_resize(display);
         //system->acknowledge_display_resize(display);
         //note that each rezie will cause the display to reload, and will be a bit laggy
         //refresh = false;
         break;
      case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
         //system->acknowledge_display_switch_out(display);
         break;
      case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
         //system->acknowledge_display_switch_in(display);
         break;
      case ALLEGRO_EVENT_TIMER:
         //motion.update(al_get_time());
         ////refresh = true;
         //static int previous_num_active_animations = 0;
         //if (previous_num_active_animations == 0 && motion.get_num_active_animations() == 0)
         //   refresh = false;
         //previous_num_active_animations = motion.get_num_active_animations();
         //if (mouse_event_occurred_and_requires_screen_refresh) refresh = true;
         break;
      case ALLEGRO_EVENT_MOUSE_AXES:
      case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
      case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
         refresh = false;
         mouse_event_skip++;
         if (mouse_event_skip >= 10)
         {
            mouse_event_skip = 0;
            mouse_event_occurred_and_requires_screen_refresh = true;
         }
         break;
      }

      if (refresh)
      {
         //ALLEGRO_COLOR backfill_color = //config.get_backfill_color();
         //al_clear_to_color(backfill_color);

         //Hexagon::System::Renderer renderer(system, display, &backfill_color);
         //renderer.render();

         al_flip_display();

         bool drop_backed_up_primary_timer_events = true;
         if (drop_backed_up_primary_timer_events)
         {
            ALLEGRO_EVENT next_event;
            while (al_peek_next_event(event_queue, &next_event)
                 && next_event.type == ALLEGRO_EVENT_TIMER
                 && next_event.timer.source == primary_timer)
              al_drop_next_event(event_queue);
         }

         mouse_event_occurred_and_requires_screen_refresh = false;
      }
   }
   return;
}


