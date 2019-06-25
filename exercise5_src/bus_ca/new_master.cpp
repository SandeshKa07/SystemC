#include "new_master.h"

void New_master::action()
{

  wait(1000, SC_NS);

  cout << "master3 writing...." << endl;
  initiator_port->write(1024, 0, id);
  initiator_port->write(1025, 16, id);
  initiator_port->write(1026, 64, id);
  initiator_port->write(1027, 16, id);
  initiator_port->write(1028, 1, id);

  cout << "master3 wait for finishing..." <<endl;
  unsigned status = 1;
  while(status){
    wait(10, SC_NS);
    initiator_port->read(1028, status, id);
  }
}
