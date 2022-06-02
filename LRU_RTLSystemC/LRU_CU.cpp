#include "LRU_CU.h"
void LRU_CU::comb_O()
{
	Free = SC_LOGIC_0;
	Ldnew = SC_LOGIC_0;
	Countrst = SC_LOGIC_0;
	LdCurr = SC_LOGIC_0;
	Addsel = SC_LOGIC_0;
	MemRead = SC_LOGIC_0;
	Cen = SC_LOGIC_0;
	MemRead = SC_LOGIC_0;
	Ldupd = SC_LOGIC_0;
	MemWrite = SC_LOGIC_0;
	WriteSel = SC_LOGIC_0;
	switch (ps)
	{
		case Idle:
			Free = SC_LOGIC_1;
			break;
		case init:
			Ldnew = SC_LOGIC_1;
			Countrst = SC_LOGIC_1;
			break;
		case ReadTag:
			LdCurr = SC_LOGIC_1;
			Addsel = SC_LOGIC_1;
			MemRead = SC_LOGIC_1;
			break;
		case UpdateCheck:
			Cen = SC_LOGIC_1;
			MemRead = SC_LOGIC_1;
			Ldupd = SC_LOGIC_1;
			break;
		case Update:
			MemWrite = SC_LOGIC_1;
			break;
		case Wait:
			MemWrite = SC_LOGIC_0;
			Addsel = SC_LOGIC_1;
			WriteSel = SC_LOGIC_1;
			break;
		case UpdateNew:
			MemWrite = SC_LOGIC_1;
			Addsel = SC_LOGIC_1;
			WriteSel = SC_LOGIC_1;
			break;
	default:
		Free = SC_LOGIC_0;
		Ldnew = SC_LOGIC_0;
		Countrst = SC_LOGIC_0;
		LdCurr = SC_LOGIC_0;
		Addsel = SC_LOGIC_0;
		MemRead = SC_LOGIC_0;
		Cen = SC_LOGIC_0;
		MemRead = SC_LOGIC_0;
		Ldupd = SC_LOGIC_0;
		MemWrite = SC_LOGIC_0;
		WriteSel = SC_LOGIC_0;
		break;
	}
}

void LRU_CU::comb_S()
{
	ns = Idle;
	switch (ps)
	{
		case Idle:
			if (completed == '1') ns = init;
			else if (completed == '0') ns = Idle;
			break;
		case init:
			if (completed == '0') ns = ReadTag;
			else if (completed == '1') ns = init;
			break;
		case ReadTag:
			ns = UpdateCheck;
			break;
		case UpdateCheck:
			if ((sign.read() == SC_LOGIC_0) && (cout.read() == SC_LOGIC_0))
				ns = UpdateCheck;
			else if ((sign.read() == SC_LOGIC_1) && (cout.read() == SC_LOGIC_0))
				ns = Update;
			else if (cout.read() == SC_LOGIC_1)
				ns = Wait;
			break;
		case Update:
			ns = UpdateCheck;
			break;
		case Wait:
			ns = UpdateNew;
			break;
		case UpdateNew:
			ns = Idle;
			break;
		default:
			ns = Idle;
			break;
	}
}
void LRU_CU::seq()
{
	while (1)
	{
		if (clk->event() && clk == '1')
			ps = ns;
		wait();
	}
}

void LRU_CU::assign()
{
	control_address = count;
}