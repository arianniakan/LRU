//#include "counterTB.h"
#include "LRU_TB.h"
//#include "MemoryTB.h"

//int sc_main(int argc, char** argv) {
//	counterTB uut("testbench1");
//	sc_trace_file* vcdfile;
//	vcdfile = sc_create_vcd_trace_file("counter_test");
//	sc_trace(vcdfile, uut.clk, "clk");
//	sc_trace(vcdfile, uut.cen, "cen");
//	sc_trace(vcdfile, uut.cout, "cout");
//	sc_trace(vcdfile, uut.countrst, "countrst");
//	sc_trace(vcdfile, uut.count, "count");
//
//	sc_start(12000, SC_NS);
//	return 0;
//
//}
//
 

int sc_main(int argc, char** argv) {
	LRU_TB lru("testbench2");
	sc_trace_file* vcdfile1;
	vcdfile1 = sc_create_vcd_trace_file("LRU_test");
	//sc_trace(vcdfile1, lru.clk, "clk");
	//sc_trace(vcdfile1, lru.completed, "completed");
	sc_trace(vcdfile1, lru.DataRead, "DataRead");
	sc_trace(vcdfile1, lru.NewPage, "newpage");
	//sc_trace(vcdfile1, lru.read, "read");
	//sc_trace(vcdfile1, lru.write, "write");
	//sc_trace(vcdfile1, lru.Free, "Free");
	sc_trace(vcdfile1, lru.DataWrite, "DataWrite");
	sc_trace(vcdfile1, lru.lru->DP->adder_out, "adderout");
	sc_trace(vcdfile1, lru.lru->DP->adder1->ain, "adderin1");
	sc_trace(vcdfile1, lru.lru->DP->Mux2in0, "UPDATEreg");
	sc_trace(vcdfile1, lru.lru->CU->clk, "clk");
	sc_trace(vcdfile1, lru.lru->CU->completed, "completed");
	sc_trace(vcdfile1, lru.lru->CU->cout, "cout");
	sc_trace(vcdfile1, lru.lru->CU->sign, "sign");
	sc_trace(vcdfile1, lru.lru->CU->count, "count");
	sc_trace(vcdfile1, lru.lru->CU->Free, "Free");
	sc_trace(vcdfile1, lru.lru->CU->Ldnew, "Ldnew");
	sc_trace(vcdfile1, lru.lru->CU->Countrst, "Countrst");
	sc_trace(vcdfile1, lru.lru->CU->LdCurr, "LdCurr");
	sc_trace(vcdfile1, lru.lru->CU->Addsel, "Addsel");
	sc_trace(vcdfile1, lru.lru->CU->MemRead, "MemRead");
	sc_trace(vcdfile1, lru.lru->CU->Cen, "Cen");
	sc_trace(vcdfile1, lru.lru->CU->Ldupd, "Ldupd");
	sc_trace(vcdfile1, lru.lru->CU->MemWrite, "MemWrite");
	sc_trace(vcdfile1, lru.lru->CU->WriteSel, "WriteSel");
	sc_trace(vcdfile1, lru.lru->DP->DataAdress, "DATAAddress");
	sc_trace(vcdfile1, lru.lru->DP->control_address, "control_address");


	sc_trace(vcdfile1, lru.mem1->mem[0], "mem0");
	sc_trace(vcdfile1, lru.mem1->mem[1], "mem1");
	sc_trace(vcdfile1, lru.mem1->mem[2], "mem2");
	sc_trace(vcdfile1, lru.mem1->mem[3], "mem3");
	sc_trace(vcdfile1, lru.mem1->mem[4], "mem4");
	sc_trace(vcdfile1, lru.mem1->mem[5], "mem5");
	sc_trace(vcdfile1, lru.mem1->mem[6], "mem6");
	sc_trace(vcdfile1, lru.mem1->mem[7], "mem7");
	sc_trace(vcdfile1, lru.mem1->mem[8], "mem8");
	sc_trace(vcdfile1, lru.mem1->mem[9], "mem9");
	sc_trace(vcdfile1, lru.mem1->mem[10], "mem10");
	sc_trace(vcdfile1, lru.mem1->mem[11], "mem11");
	sc_trace(vcdfile1, lru.mem1->mem[12], "mem12");
	sc_trace(vcdfile1, lru.mem1->mem[13], "mem13");
	sc_trace(vcdfile1, lru.mem1->mem[14], "mem14");
	sc_trace(vcdfile1, lru.mem1->mem[15], "mem15");




	sc_start(150000, SC_NS);
	return 0;

}


//int sc_main(int argc, char** argv) {
//	MemoryTB mem("testbench3");
//	sc_trace_file* vcdfile2;
//	vcdfile2 = sc_create_vcd_trace_file("memory_test");
//	sc_trace(vcdfile2, mem.clk, "clk");
//	sc_trace(vcdfile2, mem.address, "address");
//	sc_trace(vcdfile2, mem.Datain, "Datain");
//	sc_trace(vcdfile2, mem.MemWrite, "MemWrite");
//	sc_trace(vcdfile2, mem.MemRead, "MemRead");
//	sc_trace(vcdfile2, mem.Dataout, "Dataout");
//
//	sc_trace(vcdfile2, mem.mem1->mem[0], "mem0");
//	sc_trace(vcdfile2, mem.mem1->mem[1], "mem1");
//	sc_trace(vcdfile2, mem.mem1->mem[2], "mem2");
//	sc_trace(vcdfile2, mem.mem1->mem[3], "mem3");
//	sc_trace(vcdfile2, mem.mem1->mem[4], "mem4");
//	sc_trace(vcdfile2, mem.mem1->mem[5], "mem5");
//	sc_trace(vcdfile2, mem.mem1->mem[6], "mem6");
//	sc_trace(vcdfile2, mem.mem1->mem[7], "mem7");
//	sc_trace(vcdfile2, mem.mem1->mem[8], "mem8");
//	sc_trace(vcdfile2, mem.mem1->mem[9], "mem9");
//	sc_trace(vcdfile2, mem.mem1->mem[10], "mem10");
//	sc_trace(vcdfile2, mem.mem1->mem[11], "mem11");
//	sc_trace(vcdfile2, mem.mem1->mem[12], "mem12");
//	sc_trace(vcdfile2, mem.mem1->mem[13], "mem13");
//	sc_trace(vcdfile2, mem.mem1->mem[14], "mem14");
//	sc_trace(vcdfile2, mem.mem1->mem[15], "mem15");
//	sc_start(12000, SC_NS);
//	return 0;
//
//}