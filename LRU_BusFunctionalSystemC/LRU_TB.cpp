#include "LRU_TB.h"

void LRU_TB::inputing()
{
	completed = SC_LOGIC_1;
	NewPage = "0111";
	wait(20, SC_NS);
	completed = SC_LOGIC_1;
	wait(20, SC_NS);
	completed = SC_LOGIC_0;
	//NewPage = '0110';
	wait(7000, SC_NS);
	completed = SC_LOGIC_1;
	wait(20, SC_NS);
	completed = SC_LOGIC_0;
	NewPage = "1111";
	wait(700, SC_NS);
	completed = SC_LOGIC_1;
	wait(20, SC_NS);
	completed = SC_LOGIC_0;

}

void LRU_TB::clocking()
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