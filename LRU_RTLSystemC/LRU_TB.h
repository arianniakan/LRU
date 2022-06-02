#include "LRU.h"
#include "Memory.h"


SC_MODULE(LRU_TB) {
	sc_signal <sc_logic> clk, completed;
	sc_signal <sc_lv<4>> DataRead, NewPage;
	sc_signal <sc_logic> read, write, Free;
	sc_signal <sc_lv<4>> DataWrite, DataAdress;


	LRU* lru;
	memory* mem1;

	SC_CTOR(LRU_TB) {
		lru = new LRU("LRU_TestUnit");
			lru->clk(clk);
			lru->completed(completed);
			lru->DataRead(DataRead);
			lru->NewPage(NewPage);
			lru->read(read);
			lru->write(write);
			lru->Free(Free);
			lru->DataWrite(DataWrite);
			lru->DataAdress(DataAdress);
		mem1 = new memory("memory_TestUnit");
			mem1->address(DataAdress);
			mem1->Datain(DataWrite);
			mem1->clk(clk);
			mem1->MemWrite(write);
			mem1->MemRead(read);
			mem1->Dataout(DataRead);


		SC_THREAD(inputing);
		SC_THREAD(clocking);
	}
	void inputing();
	void clocking();

};