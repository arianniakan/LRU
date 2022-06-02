#include "systemc.h"

SC_MODULE(mux)
{
public:
	sc_in<sc_lv<4>> ain, bin;
	sc_in<sc_logic> sel;
	sc_out<sc_lv<4>> out;
	SC_CTOR(mux)
	{
		SC_METHOD(choosing);
		sensitive << ain << bin << sel;
	}
	void choosing();
};


