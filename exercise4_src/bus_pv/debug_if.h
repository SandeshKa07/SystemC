#ifndef _DEBUG_IF_H_
#define _DEBUG_IF_H_

#include "systemc.h"
#include <iostream>

class debug_if : virtual public sc_interface
{
public:
  virtual void dump( ostream &os ) = 0;
};

#endif
