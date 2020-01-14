#include "vpn.cpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  VPN vpn;

  //Shows the window and returns when it is closed.
  return app->run(vpn);
}