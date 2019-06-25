#include "adapter.h"

void Adapter::write(unsigned addr, unsigned  data) {
  switch(addr) {
  case 1024 :
    start_addr1 = data;
    break;
  case 1025 :
    start_addr2 = data;
    break;
  case 1026 :
    start_addr3 = data;
    break;
  case 1027 :
    block_size = data;
    break;
  case 1028 :
    status = 0;
    if(data != 0){
      //Start Computation
      status = data;
      start_process.notify();
    }
    break;
  default :
    cout << "Adapter: write to invalid address" << endl;
  }
}

void Adapter::read( unsigned addr, unsigned &data) {
  switch(addr) {
  case 1024 :
    data = start_addr1;
    break;
  case 1025 :
    data = start_addr2;
    break;
  case 1026 :
    data = start_addr3;
    break;
  case 1027 :
    data = block_size;
    break;
  case 1028 :
    data = status;
    break;
  default :
    cout << "Adapter: read from invalid address" << endl;
  }
}

void Adapter::process(){
  unsigned data;
  while(1){
    wait(start_process);
    for(int i = 0; i<block_size; i++){
      initiator_port->read((start_addr1+i),data,id);
      x.write(data);

      initiator_port->read((start_addr2+i),data,id);
      y.write(data);

      wait(5, SC_NS);

      data = s.read();
      initiator_port->write((start_addr3+i),data, id);
    }
    status = 0;
  }
}
