#include "Memory.h"

SC_MODULE(MemoryTB) {
	sc_signal<sc_lv<4>> address, Datain;
	sc_signal<sc_logic> clk, MemWrite, MemRead;
	sc_signal<sc_lv<4>> Dataout;
	memory* mem1;
	SC_CTOR(MemoryTB) {
		mem1 = new memory("MemoryTestUnit");
		mem1->clk(clk);
		mem1->address(address);
		mem1->Datain(Datain);
		mem1->MemWrite(MemWrite);
		mem1->MemRead(MemRead);
		mem1->Dataout(Dataout);

		SC_THREAD(inputing);
		SC_THREAD(clocking);
	}
	void inputing();
	void clocking();

};