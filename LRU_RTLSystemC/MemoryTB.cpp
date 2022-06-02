#include "MemoryTB.h"


void MemoryTB::inputing()
{
	address = "0010";
	Datain = "0110";
	wait(10, SC_NS);
	MemWrite = SC_LOGIC_1;
	wait(600, SC_NS);
	MemWrite = SC_LOGIC_0;
	wait(20, SC_NS);
	MemRead = SC_LOGIC_1;
	wait(20, SC_NS);
	address = "1111";
	wait(1000, SC_NS);
}

void MemoryTB::clocking()
{
	int i;
	clk = SC_LOGIC_1;
	for (i = 0;i <= 200;i++)
	{
		clk = SC_LOGIC_0;
		wait(5, SC_NS);
		clk = SC_LOGIC_1;
		wait(5, SC_NS);
	}
}