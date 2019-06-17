#include "master_new.h"

void Master_new::action()
{
  unsigned data;
  wait(100, SC_MS);
  int master_1_data=0, master_2_data=0;
  for(int i = 0; i < 16; i++)
  {
    initiator_port->read(i, data);
    initiator_port->write(1024, data);
    cout << name() << " write(" << "1024, " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    master_1_data = data;
    
    initiator_port->read(i+16, data);
    initiator_port->write(1025, data);
    cout << name() << " write(" << "1025, " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    master_2_data = data;

    initiator_port->read(1026, data);
    initiator_port->write(i+64, data);
    cout << name() << " write( Sum of " << master_1_data << " + " << master_2_data << " at "
	<< i+64 << ", is " << data << ")"  << " at " << sc_time_stamp() << endl;
  }
  wait();
}
