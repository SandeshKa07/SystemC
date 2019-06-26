#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

  sc_port<ext_bus_if,1> initiator_port;
  sc_event start_process;

  unsigned start_addr1;
  unsigned start_addr2;
  unsigned start_addr3;
  unsigned block_size;
  int status;

  unsigned id;
  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );
  void process(void);

  SC_HAS_PROCESS(Adapter);
  Adapter( sc_module_name mn, unsigned id) : sc_module(mn)
  {
    this->id = id;
    status = 0;
    SC_THREAD(process);
    return; // alternative: export the bus_if here
  }

};

#endif
