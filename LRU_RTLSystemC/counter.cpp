#include "counter.h"

void counter::counting()
{
	cout = SC_LOGIC_0;
	if (count.read().to_uint() == 15)
		cout = SC_LOGIC_1;
	if (clk->event() && clk == "1") {
		if (countrst == '1')
			count = '0000';
		if (cen == '1')
			if (countrst == '1')
				count = '0000';
			else
				count = count.read().to_int() + 1;
	}
}
