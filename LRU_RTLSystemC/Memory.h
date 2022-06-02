#include "systemc.h"
#include <iostream>


SC_MODULE(memory)
{
public:
	sc_in<sc_lv<4>> address, Datain;
	sc_in<sc_logic> clk, MemWrite, MemRead;
	sc_out<sc_lv<4>> Dataout;
	sc_uint<4>* mem;
	SC_CTOR(memory)
	{
		mem = new sc_uint<4>[16];
		for (int i = 0; i<16; i++)
			mem[i] = i;
		SC_METHOD(reading);
		sensitive << address << MemRead;
		SC_METHOD(writing);
		sensitive << clk << address<< Datain << MemWrite;
	}
	void reading();
	void writing();

};



