#include <systemc.h>
#include "adder.h"
#include "Sub.h"
#include "Registers.h"
#include "mux.h"


SC_MODULE(LRU_DP)
{
public:
	sc_in<sc_logic> clk, LdCurr, Ldupd, Ldnew, WriteSel,Add_sel;
	sc_in<sc_lv<4>> DataRead, NewPage, control_address;
	sc_out<sc_logic> sign;
	sc_out<sc_lv<4>> DataWrite, DataAdress;

	sc_signal <sc_lv<4>> adder_out;
	sc_signal <sc_lv<4>> Mux1in1;
	sc_signal <sc_lv<4>> Mux2in0;
	sc_signal <sc_lv<4>> sub_in2;
	//sc_signal <sc_lv<4>> sub_in1;
	sc_signal <sc_lv<4>>  zero;

	incrementer4bit* adder1;
	sub* suber1;
	dRegister* curr;
	dRegister* NewPagereg;
	dRegister* update;



	mux* MUX1;
	mux* MUX2;


	SC_CTOR(LRU_DP)
	{
		zero = sc_lv<4>("0000");
		curr = new dRegister("CurrRegister");
			curr->clk(clk);
			curr->ld(LdCurr);
			curr->regin(DataRead);
			curr->regout(sub_in2);
		NewPagereg = new dRegister("NewPageAddressRegister");
			NewPagereg->clk(clk);
			NewPagereg->ld(Ldnew);
			NewPagereg->regin(NewPage);
			NewPagereg->regout(Mux1in1);
		update = new dRegister("UpdatedRegister");
			update->clk(clk);
			update->ld(Ldupd);
			update->regin(adder_out);
			update->regout(Mux2in0);
		adder1 = new incrementer4bit("incremenrer");
			adder1->ain(DataRead);
			adder1->out(adder_out);
		suber1 = new sub("subtractor");
			suber1->ain(DataRead);
			suber1->bin(sub_in2);
			suber1->sign(sign);
		MUX1 = new mux("AddressMUX");
			MUX1->ain(control_address);
			MUX1->bin(Mux1in1);
			MUX1->out(DataAdress);
			MUX1->sel(Add_sel);
		MUX2 = new mux("DataMux");
			MUX2->ain(Mux2in0);
			MUX2->bin(zero);
			MUX2->sel(WriteSel);
			MUX2->out(DataWrite);

	}
	void assign();
};




