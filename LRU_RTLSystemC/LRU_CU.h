#include <systemc.h>

SC_MODULE(LRU_CU) {
	sc_in <sc_logic> clk, completed, cout, sign;
	sc_in <sc_lv<4>> count;
	sc_out <sc_logic> Free, Ldnew, Countrst, LdCurr, Addsel, MemRead, Cen, Ldupd, MemWrite, WriteSel;
	sc_out <sc_lv<4>> control_address;
	enum states { Idle, init, ReadTag, UpdateCheck, Update, UpdateNew, Wait};
	sc_signal <states> ps, ns;
	SC_CTOR(LRU_CU)
	{
		SC_METHOD(comb_S);
		sensitive << completed << cout << ps << sign;
		SC_METHOD(comb_O);
		sensitive << ps;
		SC_THREAD(seq);
		sensitive << clk;
		SC_METHOD(assign);
		sensitive << count;

	}
	void comb_S();
	void comb_O();
	void seq();
	void assign();

};