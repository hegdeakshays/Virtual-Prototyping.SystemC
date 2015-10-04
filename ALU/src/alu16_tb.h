/*
 * alu16_tb.h
 *
 *  Created on: Jun 30, 2015
 *      Author: kannoth
 */

#ifndef ALU16_TB_H_
#define ALU16_TB_H_

#include<systemc.h>
#include "miscmacros.h"

SC_MODULE(ALU_TB){

	sc_out< sc_logic> clk_out;
	sc_out< sc_uint<3> > op_sel;
	sc_out< sc_logic > reset;
	sc_inout < sc_int<16> > data1;
	sc_inout < sc_int<16> > data2;
	sc_in <sc_int<16> > acc ;
	sc_in < sc_bv <8> > stat;

	void ALU_TB_test();
	void PrintConsole(int bi, char* opname, sc_bv<16> tmp);

	SC_CTOR (ALU_TB) {
		SC_THREAD(ALU_TB_test);
	}
};


#endif /* ALU16_TB_H_ */
