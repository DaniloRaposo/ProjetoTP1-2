#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <stdexcept>

#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

int main(){

  CntrAAutenticacao *cntra;
  CntrAUsuario *cntru;
  StubSAutenticacao *stub;

  cntru = new CntrAUsuario();
  cntra = new CntrAAutenticacao();
  stub = new StubSAutenticacao();

  cntra->setCSAutenticacao(stub);
  cntra->setCAUsuario(cntru);
  cntra->executar();

  delete cntra;
  delete cntru;
  delete stub;

  return 0;
}
