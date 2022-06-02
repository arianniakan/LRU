#include "LRU_TB.h"

int sc_main(int argc, char** argv) {
	LRU_TB lru("testbench2");
	sc_trace_file* vcdfile1;
	vcdfile1 = sc_create_vcd_trace_file("LRU_BF_test");
	sc_trace(vcdfile1, lru.clk, "clk");
	sc_trace(vcdfile1, lru.completed, "completed");
	sc_trace(vcdfile1, lru.NewPage, "NewPage");


	sc_trace(vcdfile1, lru.lru->Regs[0], "Reg0");
	sc_trace(vcdfile1, lru.lru->Regs[1], "Reg1");
	sc_trace(vcdfile1, lru.lru->Regs[2], "Reg2");
	sc_trace(vcdfile1, lru.lru->Regs[3], "Reg3");
	sc_trace(vcdfile1, lru.lru->Regs[4], "Reg4");
	sc_trace(vcdfile1, lru.lru->Regs[5], "Reg5");
	sc_trace(vcdfile1, lru.lru->Regs[6], "Reg6");
	sc_trace(vcdfile1, lru.lru->Regs[7], "Reg7");
	sc_trace(vcdfile1, lru.lru->Regs[8], "Reg8");
	sc_trace(vcdfile1, lru.lru->Regs[9], "Reg9");
	sc_trace(vcdfile1, lru.lru->Regs[10], "Reg10");
	sc_trace(vcdfile1, lru.lru->Regs[11], "Reg11");
	sc_trace(vcdfile1, lru.lru->Regs[12], "Reg12");
	sc_trace(vcdfile1, lru.lru->Regs[13], "Reg13");
	sc_trace(vcdfile1, lru.lru->Regs[14], "Reg14");
	sc_trace(vcdfile1, lru.lru->Regs[15], "Reg15");






	sc_start(15000, SC_NS);
	return 0;

}
