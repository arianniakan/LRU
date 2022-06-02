#include <systemc.h>

SC_MODULE(LRU)
{
	sc_in<sc_lv<4>> NewPage;
	sc_in<sc_logic> clk, completed;
	sc_uint<4>* Regs;
	SC_CTOR(LRU)
	{
		Regs = new sc_uint<4>[16];
		for (int i = 0; i < 16; i++)
			Regs[i] = i;
		SC_METHOD(Update);
		sensitive << clk << NewPage << completed;
	}
	void Update();
};
