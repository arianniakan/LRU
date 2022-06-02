#include "adder.h"

void incrementer4bit::adding()
{
	sc_uint<4> res;
	res = ain.read().to_int() + 1;
	out = res;
}