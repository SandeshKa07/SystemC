#ifndef _MASTER_NEW_H_
#define _MASTER_NEW_H_

#include "bus_if.h"

SC_MODULE( Master_new )
{
  sc_port<bus_if,1> initiator_port;
  void action();
  unsigned start, end, id;
  SC_HAS_PROCESS(Master_new);
  Master_new( sc_module_name mn, unsigned id = 0 )
  : sc_module( mn )
  {
    SC_THREAD(action);
    this->id = id;
  }
};

#endif
