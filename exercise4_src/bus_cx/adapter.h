#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_export<bus_if> target_export;

  sc_out<int> x;
  sc_out<int> y;
  sc_in<int> s;

  unsigned start;
  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );

  Adapter( sc_module_name mn, unsigned start_addr  )
  : sc_module(mn)
  {
    target_export.bind(*this);
    this->start = start_addr;
  }
};

#endif
