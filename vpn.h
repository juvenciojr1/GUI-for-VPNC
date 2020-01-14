#ifndef GTKMM_VPN_H
#define GTKMM_VPN_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/frame.h>
#include <gtkmm/main.h>

class VPN : public Gtk::Window {
  public: VPN();
  virtual ~VPN();

protected:
  void funConectar();
  void funDesconectar();
  void sudo();

  // Child widgets:
  Gtk::Box m_box1, boxUsuario, boxSenha, boxSenhaAdm, boxPerfil, boxBotoes;
  Gtk::Entry usuario, senha, senhaAdm, perfil;
  Gtk::Button conectar, desconectar;

  Gtk::Frame frameUsuario, frameSenha, frameSenhaAdm, framePerfil, frameBotoes;
};

#endif // GTKMM_VPN_H