#include <systemc.h>

SC_MODULE(dRegister)
{
public:
	sc_in  <sc_logic> clk, ld;
	sc_in  <sc_lv<4>> regin;
	sc_out <sc_lv<4>> regout;
	SC_CTOR(dRegister)
	{
		SC_METHOD(registering);
		sensitive << clk ;
	}
	void registering();

};