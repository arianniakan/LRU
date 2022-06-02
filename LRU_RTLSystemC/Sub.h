#include "systemc.h"

SC_MODULE(sub)
{
public:
	sc_in<sc_lv<4>> ain,bin;
	//sc_out<sc_lv<4>> out;
	sc_out<sc_logic> sign;
	SC_CTOR(sub)
	{
		SC_METHOD(subing);
		sensitive << ain << bin;
	}
	void subing();
};
