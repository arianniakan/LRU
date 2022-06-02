#include "systemc.h"

SC_MODULE(incrementer4bit)
{
public:

	sc_in<sc_lv<4>> ain;
	sc_out<sc_lv<4>> out;
	SC_CTOR(incrementer4bit)
	{
		SC_METHOD(adding);
		sensitive << ain;
	}
	void adding();
};
