/*
 * alu.h
 *
 *  Created on: Jun 27, 2015
 *      Author: kannoth
 */

#ifndef ALU16_H_
#define ALU16_H_

#include <systemc.h>
#include "miscmacros.h"


SC_MODULE(ALU){

	sc_in< sc_logic> clk;
	sc_in< sc_uint<3> > op_sel;
	sc_in< sc_logic > reset;
	sc_inout < sc_int<16> > data1;
	sc_inout < sc_int<16> > data2;
	sc_out <sc_int<16> > acc ;
	sc_out < sc_bv <8> > stat;

	void AluOp(sc_uint<3> opcode);
	void ALUmain(void);
	void AluOpConjn(void);
	void AluOpDisjn(void);
	void AluOpExclOR(void);
    void AluOpROR(void);
    void AluOpROL(void);
    void AluOpSum(void);
    void AluOpMult(void);
    void AluOpDiv(void);
    void AluInitialize(void);
    void ALUSetstat(sc_uint<3> opsel);
    sc_logic Sign(sc_int<DATAWIDTH> var);
    sc_logic ALUSetZFlag(void);
    sc_logic ALUSetCFlag(sc_uint<3> opsel);
    sc_logic ALUReportUnderflow(sc_uint<3> op_sel);
    sc_logic ALUReportOverflow(sc_uint<3> op_sel);

	SC_CTOR(ALU){
		SC_METHOD(ALUmain);
			sensitive<<clk.pos();
	}

};


#endif /* ALU_H_ */
