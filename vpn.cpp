#include "vpn.h"
#include <iostream>

VPN::VPN() : m_box1(Gtk::ORIENTATION_VERTICAL), conectar("Connect to the vpn"),  desconectar("Disconnect to the vpn"), 
  frameUsuario("Usuário"), frameSenha("Senha"), frameSenhaAdm("Senha do Administrador"), framePerfil("Perfil do VPNC"){

  set_title("VPNC");
  set_border_width(20);

  // Coloca a caixa principal na Janela
  add(m_box1);

  //Insere frames na Caixa Principal
  m_box1.pack_start(frameSenhaAdm, Gtk::PACK_EXPAND_WIDGET, 10);
  m_box1.pack_start(framePerfil, Gtk::PACK_EXPAND_WIDGET, 10);
  m_box1.pack_start(frameUsuario, Gtk::PACK_EXPAND_WIDGET, 10);
  m_box1.pack_start(frameSenha, Gtk::PACK_EXPAND_WIDGET, 10);
  m_box1.pack_start(frameBotoes, Gtk::PACK_EXPAND_WIDGET, 10);

  //Adiciona os box aos frames
  frameUsuario.add(boxUsuario);
  frameSenha.add(boxSenha);
  frameSenhaAdm.add(boxSenhaAdm);
  framePerfil.add(boxPerfil);
  frameBotoes.add(boxBotoes);

  //Borda dos box
  boxUsuario.set_border_width(10);
  boxSenha.set_border_width(10);
  boxSenhaAdm.set_border_width(10);
  boxPerfil.set_border_width(10);
  boxBotoes.set_border_width(10);

  usuario.set_max_length(50);
  usuario.select_region(0, usuario.get_text_length());
  usuario.set_placeholder_text("Usuário");
  boxUsuario.pack_start(usuario);

  senhaAdm.set_max_length(50);
  senhaAdm.select_region(0, senhaAdm.get_text_length());
  senhaAdm.set_invisible_char('*');
  senhaAdm.set_visibility(false);
  senhaAdm.set_placeholder_text("Senha Administrador");
  boxSenhaAdm.pack_start(senhaAdm);

  perfil.set_max_length(50);
  perfil.select_region(0, perfil.get_text_length());
  perfil.set_placeholder_text("Perfil");
  boxPerfil.pack_start(perfil);

  senha.set_max_length(50);
  senha.set_invisible_char('*');
  senha.set_visibility(false);
  senha.select_region(0, senha.get_text_length());
  senha.set_placeholder_text("Senha");
  boxSenha.pack_start(senha);

  
  conectar.signal_clicked().connect(
    sigc::mem_fun(*this, &VPN::funConectar)
  );
  boxBotoes.pack_start(conectar);

  desconectar.signal_clicked().connect(
    sigc::mem_fun(*this, &VPN::funDesconectar)
  );

  boxBotoes.pack_start(desconectar);


  show_all_children();
}

VPN::~VPN(){
}

void VPN::sudo(){
  char echoSudo[200] = "echo ";
  strcat(echoSudo, senhaAdm.get_text().c_str());
  strcat(echoSudo, " | sudo -S su");
  strcat(echoSudo, " \n");
  system(echoSudo);

}
void VPN::funConectar(){
  VPN::sudo();
  char echo[200] = "echo ";
  strcat(echo, senha.get_text().c_str());
  strcat(echo, " | sudo vpnc ");
  strcat(echo, perfil.get_text().c_str());
  strcat(echo, " --username ");
  strcat(echo, usuario.get_text().c_str());
  strcat(echo, " \n");

  system(echo);
  system("exit");
}
void VPN::funDesconectar(){
  
  VPN::sudo();  

  system("sudo vpnc-disconnect \n");
}
