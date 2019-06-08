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

  CntrAAutenticacao cntra;
  CntrAUsuario cntru;
  CntrAEventos cntre;
  StubSAutenticacao stuba;
  StubSUsuario stubu;
  StubSEventos stube;

  cntra.setCSAutenticacao(&stuba);
  cntra.setCAUsuario(&cntru);
  cntru.setCSUsuario(&stubu);
  cntru.setCAEventos(&cntre);
  cntre.setCSEventos(&stube);
  cntra.executar();

  return 0;
}
