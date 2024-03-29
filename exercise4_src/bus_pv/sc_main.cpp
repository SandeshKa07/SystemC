#include "master.h"
#include "ram.h"
#include "bus_pv.h"
#include <ostream>

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);
  Bus_pv bus("bus");
  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);
  sc_start();

  ofstream ram1file ("ram1_dump.txt");
  ram1.dump(ram1file);
  ofstream ram2file ("ram2_dump.txt");
  ram2.dump(ram2file);
  return 0;
}
