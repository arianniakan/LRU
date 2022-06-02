#include "counterTB.h"

void counterTB::inputing()
{
	cen = SC_LOGIC_0;
	countrst = SC_LOGIC_0;
	wait(10, SC_NS);
	cen = SC_LOGIC_1;
	wait(600, SC_NS);
	countrst = SC_LOGIC_1;
	wait(20, SC_NS);
	countrst = SC_LOGIC_0;
	wait(1000, SC_NS);
}

void counterTB::clocking()
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