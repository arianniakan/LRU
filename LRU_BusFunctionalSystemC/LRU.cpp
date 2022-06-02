#include "LRU.h"


void LRU::Update()
{
	if (clk.event() && clk == SC_LOGIC_1 && completed == SC_LOGIC_1)
	{
		for (int i = 0; i < 16; i++)
		{
			if (Regs[i] == NewPage.read().to_uint())
			{
				for (int j = i; j > 0; j--) {
					Regs[j] = Regs[j - 1];
				}
				Regs[0] = NewPage;
				break;
			}
		}
	}
}
