#include "Memory.h"

void memory::reading()
{
	sc_uint<4> i = address->read().to_int();

	cout << i;
	if (MemRead == '1') {
		Dataout = mem[i];
	}
}

void memory::writing()
{
	sc_uint<4> i = address->read().to_int();

	cout << i;
	//if (clk->event() && clk == '1')
	{
		if (MemWrite == '1') mem[i] = Datain.read().to_uint();
	}
}
