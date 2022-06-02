#include "LRU_DP.h"
#include "LRU_CU.h"
#include "counter.h"


SC_MODULE(LRU) {
	sc_in<sc_logic> clk, completed;
	sc_in <sc_lv<4>> DataRead, NewPage;
	sc_out <sc_logic> read, write, Free;
	sc_out <sc_lv<4>> DataWrite, DataAdress;

	sc_signal <sc_lv<4>> control_address, count;
	sc_signal <sc_logic> LdCurr, Ldupd, Ldnew, WriteSel, Add_sel, sign;

	sc_signal<sc_logic> cen, countrst, cout;

	LRU_CU* CU;
	LRU_DP* DP;
	counter* counter2;


	SC_CTOR(LRU) {
		DP = new LRU_DP("datapath");
			DP->clk(clk);
			DP->LdCurr(LdCurr);
			DP->Ldupd(Ldupd);
			DP->Ldnew(Ldnew);
			DP->WriteSel(WriteSel);
			DP->Add_sel(Add_sel);
			DP->DataRead(DataRead);
			DP->NewPage(NewPage);
			DP->control_address(control_address);
			DP->sign(sign);
			DP->DataWrite(DataWrite);
			DP->DataAdress(DataAdress);
		CU = new LRU_CU("controlunit");
			CU->clk(clk);
			CU->completed(completed);
			CU->cout(cout);
			CU->sign(sign);
			CU->count(count);
			CU->Free(Free);
			CU->Ldnew(Ldnew);
			CU->Countrst(countrst);
			CU->LdCurr(LdCurr);
			CU->Addsel(Add_sel);
			CU->MemRead(read);
			CU->Cen(cen);
			CU->Ldupd(Ldupd);
			CU->MemWrite(write);
			CU->WriteSel(WriteSel);
			CU->control_address(control_address);
		counter2 = new counter("CounterUnit");
			counter2->clk(clk);
			counter2->cen(cen);
			counter2->countrst(countrst);
			counter2->cout(cout);
			counter2->count(count);
	}
};
