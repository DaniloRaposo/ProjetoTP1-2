#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <stdexcept>
#include <vector>

#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

int main(){

  ControladoraSistema cntr;
  CntrAAutenticacao cntra;
  CntrAUsuario cntru;
  CntrAEventos cntre;
  CntrAVendas cntrv;
  StubSAutenticacao stuba;
  StubSUsuario stubu;
  StubSEventos stube;
  StubSVendas stubv;

  cntr.setCAAutenticacao(&cntra);
  cntr.setCAUsuario(&cntru);
  cntr.setCAEventos(&cntre);
  cntra.setCSAutenticacao(&stuba);
  cntra.setCAUsuario(&cntru);
  cntru.setCSUsuario(&stubu);
  cntru.setCAEventos(&cntre);
  cntru.setCAVendas(&cntrv);
  cntre.setCSEventos(&stube);
  cntrv.setCSVendas(&stubv);
  cntr.executar();

  return 0;
}
