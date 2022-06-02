#include "Registers.h"

void dRegister::registering()
{
	if (clk->event() && clk == '1')
	{
		if (ld == '1') regout = regin;
	}
}