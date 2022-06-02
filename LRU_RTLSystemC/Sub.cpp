#include "Sub.h"

void sub::subing()
{
	//sc_lv<4> res;
	//res = ain.read().to_int() - bin.read().to_int();
	////out = res;
	//sign = res[3];
	
	if (sc_uint<4> (ain) < sc_uint<4> (bin))
		sign = SC_LOGIC_1;
	else sign = SC_LOGIC_0;
}