/*
 * main.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: kannoth
 */

#include <systemc.h>
#include "alu16.h"
#include "alu16_tb.h"

int sc_main(int argc, char* argv[]){

	sc_set_time_resolution(1, SC_NS);

	sc_signal< sc_logic> clk;
	sc_signal< sc_uint<3> > op_sel;
	sc_signal< sc_logic > reset;
	sc_signal < sc_int<16> > sdata1;
	sc_signal < sc_int<16> > sdata2;
	sc_signal <sc_int<16> > acc ;
	sc_signal < sc_bv <8> > stat;

	ALU* alu;
	ALU_TB* alu_tb;

	alu = new ALU("ALU16");
	alu->clk(clk);
	alu->op_sel(op_sel);
	alu->reset(reset);
	alu->data1(sdata1);
	alu->data2(sdata2);
	alu->acc(acc);
	alu->stat(stat);


	alu_tb = new ALU_TB("ALU16_TB");
	alu_tb->clk_out(clk);
	alu_tb->op_sel(op_sel);
	alu_tb->reset(reset);
	alu_tb->data1(sdata1);
	alu_tb->data2(sdata2);
	alu_tb->acc(acc);
	alu_tb->stat(stat);

 	sc_trace_file *fp;
 	fp=sc_create_vcd_trace_file("ALU16");

 	sc_trace(fp ,clk	,"clk"		);
 	sc_trace(fp ,op_sel	,"op_sel"	);
    sc_trace(fp ,reset	,"reset"	);
    sc_trace(fp ,sdata1	,"data1"	);
    sc_trace(fp ,sdata2	,"data2"	);
    sc_trace(fp ,acc	,"acc"		);
    sc_trace(fp ,stat	,"stat"		);

	sc_start();
	sc_close_vcd_trace_file(fp);
	sc_stop();

	delete(alu);
	delete(alu_tb);

	return 0;
}
