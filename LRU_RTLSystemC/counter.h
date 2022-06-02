#include <systemc.h>

SC_MODULE(counter) {
	sc_in <sc_logic> clk, cen, countrst;
	sc_out <sc_logic> cout;
	sc_out <sc_lv<4>> count;

	SC_CTOR(counter)
	{
		SC_METHOD(counting);
		sensitive << clk<<cen<<countrst<<count;
	}
	void counting();
};