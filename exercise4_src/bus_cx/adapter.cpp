#include "adapter.h"

void Adapter::write( unsigned addr, unsigned  data )
{
  if(addr == start)
	x = (int)data;
  else if(addr == start + 1)
	y = (int)data;
  else if(addr == start + 2)
	cout << "Error 1026 is read only" << endl;
  else 
	cout << "ERROR !!!! Address not in range" << endl;
}

void Adapter::read(  unsigned addr, unsigned &data )
{
  if(addr == start)
	data = x;
  else if(addr == start + 1)
	data = y;
  else if(addr == start + 2)
	data = s;
  else
	cout << "ERROR !!!! Address not in range" << endl;
}
  

