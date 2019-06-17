#include "master.h"
#include "ram.h"
#include "bus_cx.h"
#include "adapter.h"
#include "adder.h"
#include "master_new.h"

int sc_main(int argc, char *argv[])
{

  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);
  Master_new master3("master_new", 2);
  Ram    ram3("ram3", 64,16);
  Bus_cx bus("bus", 10,  SC_NS);
  Adapter adapter("adapter", 1024);
  Adder adder("adder");

  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  master3.initiator_port(bus.bus_export);


  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);
  bus.bus_port(ram3.target_export);
  bus.bus_port(adapter.target_export);

  sc_signal<int> sig_x;
  sc_signal<int> sig_y;
  sc_signal<int> sig_s;

  adder.x(sig_x);
  adapter.x(sig_x);
 
  adder.y(sig_y);
  adapter.y(sig_y);

  adder.s(sig_s);
  adapter.s(sig_s);

  sc_start();
  return 0;
}
