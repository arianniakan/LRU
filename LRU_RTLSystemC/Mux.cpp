#include "Mux.h"

void mux::choosing()
{

	if (sel.read() == SC_LOGIC_1)
		out = bin;
	else if (sel.read() == SC_LOGIC_0)
		out = ain;
}