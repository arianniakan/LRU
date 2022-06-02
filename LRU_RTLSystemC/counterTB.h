#include "counter.h"

SC_MODULE(counterTB) {
	sc_signal<sc_logic> clk, cen, cout, countrst;
	sc_signal<sc_lv<4>> count;

	counter* counter1;
	SC_CTOR(counterTB) {
		counter1 = new counter("CounterTestUnit");
		counter1->clk(clk);
		counter1->cen(cen);
		counter1->cout(cout);
		counter1->count(count);
		counter1->countrst(countrst);

		SC_THREAD(inputing);
		SC_THREAD(clocking);
	}
	void inputing();
	void clocking();

};