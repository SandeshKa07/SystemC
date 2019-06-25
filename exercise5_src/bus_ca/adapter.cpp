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
