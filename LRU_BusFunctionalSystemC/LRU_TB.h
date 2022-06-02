#include "LRU.h"

SC_MODULE(LRU_TB) {
	sc_signal <sc_logic> clk, completed;
	sc_signal <sc_lv<4>>NewPage;


	LRU* lru;

	SC_CTOR(LRU_TB) {
		lru = new LRU("LRU_TestUnit");
		lru->clk(clk);
		lru->completed(completed);
		lru->NewPage(NewPage);
		SC_THREAD(inputing);
		SC_THREAD(clocking);
	}
	void inputing();
	void clocking();

};