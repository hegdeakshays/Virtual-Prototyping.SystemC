/*
 * alu.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: kannoth
 */

#include <systemc.h>
#include "alu16.h"
#include "miscmacros.h"

sc_int<16> accu;
sc_int<16> tmpDatrRot;
sc_int<16> tmpDatlRot;
sc_logic divOF;

void ALU::ALUmain(void){
	if(reset.read() == SC_LOGIC_1){
		AluOp(op_sel);
	}
	else{
		AluInitialize();
	}
}

void ALU::AluOp(sc_uint <3> opcode){
	switch(opcode.to_uint()){
		case(AND):{
			AluOpConjn();
			break;
		}
		case(OR):{
			AluOpDisjn();
			break;
		}
		case(XOR):{
			AluOpExclOR();
			break;
		}
		case(ROR):{
			AluOpROR();
			break;
		}
		case(ROL):{
			AluOpROL();
			break;
		}
		case(ADD):{
			AluOpSum();
			break;
		}
		case(MUL):{
			AluOpMult();
			break;
		}
		case(DIV):{
			AluOpDiv();
			break;
		}
		default:break;

	}
}

void ALU::AluOpConjn(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	accu = d1 & d2;
	acc.write( accu );
	ALUSetstat(AND);
}

void ALU::AluOpDisjn(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	accu = d1 | d2;
	acc.write( accu );
	ALUSetstat(OR);
}

void ALU::AluOpExclOR(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	accu = d1 ^ d2;
	acc.write( accu );
	ALUSetstat(XOR);
}

void ALU::AluOpROR(void){
	sc_bv<DATAWIDTH> d1;
	ALUSetstat(ROR);// Keep a copy of LSbit to CF
	d1 = (sc_bv<DATAWIDTH>)data1.read();
	d1.rrotate(1);
	tmpDatrRot = d1;
	data1.write((sc_int<DATAWIDTH>)d1);

}

void ALU::AluOpROL(void){
	sc_bv<DATAWIDTH> d1;
	ALUSetstat(ROL);// Keep a copy of MSbit to CF
	d1 = (sc_bv<DATAWIDTH>)data1.read();
	d1.lrotate(1);
	tmpDatlRot = d1;
	data1.write((sc_int<DATAWIDTH>)d1);
}

void ALU::AluOpSum(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	accu = d1+d2;
	acc.write( accu );
	ALUSetstat(ADD);
}

void ALU::AluOpMult(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	accu = d1*d2;
	acc.write( accu );
	ALUSetstat(MUL);
}

void ALU::AluOpDiv(void){
	sc_int<DATAWIDTH> d1;
	sc_int<DATAWIDTH> d2;
	d1 = data1.read();
	d2 = data2.read();
	if(d2 != 0){
		accu = d1/d2;
		acc.write( accu );
		divOF = SC_LOGIC_0;
		ALUSetstat(DIV);
	}
	else{
		divOF = SC_LOGIC_1;
		ALUSetstat(DIV);// Explicit Overflow for n/0
	}
}

void ALU::ALUSetstat(sc_uint<3> opsel){
	sc_bv<8> status;

	switch( opsel.to_uint()){
		case(OR):{
			status[0] = ALUSetZFlag();
			status[1] = SC_LOGIC_0;
			status[2] = Sign(accu);
			status[3] = SC_LOGIC_0;
			status[4] = SC_LOGIC_0;
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;

			break;
		}
		case(AND):{
			status[0] = ALUSetZFlag();
			status[1] = SC_LOGIC_0;
			status[2] = Sign(accu);
			status[3] = SC_LOGIC_0;
			status[4] = SC_LOGIC_0;
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		case(ROR):{
			status[0] = ALUSetZFlag();
			status[1] = ALUSetCFlag(ROR);
			status[2] = Sign(tmpDatrRot);
			status[3] = SC_LOGIC_0;
			status[4] = SC_LOGIC_0;
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		case(ROL):{
			status[0] = ALUSetZFlag();
			status[1] = ALUSetCFlag(ROL);
			status[2] = Sign(tmpDatlRot);
			status[3] = SC_LOGIC_0;
			status[4] = SC_LOGIC_0;
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		case(ADD):{
			status[0] = ALUSetZFlag();
			status[1] = ALUSetCFlag(opsel);
			status[2] = Sign(accu);
			status[3] = ALUReportUnderflow(opsel);
			status[4] = ALUReportOverflow(opsel);
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		case(MUL):{
			status[0] = ALUSetZFlag();
			status[1] = ALUSetCFlag(opsel);
			status[2] = Sign(accu);
			status[3] = ALUReportUnderflow(opsel);
			status[4] = ALUReportOverflow(opsel);
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		case(DIV):{
			status[0] = ALUSetZFlag();
			status[1] = SC_LOGIC_0;
			status[2] = Sign(accu);
			status[3] = ALUReportOverflow(opsel);
			status[4] = SC_LOGIC_0;
			status[5] = SC_LOGIC_0;
			status[6] = SC_LOGIC_0;
			status[7] = SC_LOGIC_0;

			stat = status;
			break;
		}
		default:break;
	}
}

/*
 *
 */
sc_logic ALU::ALUReportUnderflow(sc_uint<3> opsel){

	sc_logic ret = SC_LOGIC_0;
	sc_int<DATAWIDTH> a = data1.read();
	sc_int<DATAWIDTH> b = data2.read();
	sc_int<DATAWIDTH> res = acc.read();

	switch(opsel){
		case (ADD):{
			ret = ((Sign(a) == NEG) & (Sign(b)== NEG) & (Sign(res)== POS)) ? SC_LOGIC_1 : SC_LOGIC_0;
			break;
		}
		case (MUL):{
			ret = (((Sign(a) == POS) & (Sign(b) == NEG) & (Sign(res) == POS))
										|
				  ((Sign(a) == NEG) & (Sign(b) == POS ) & (Sign(res)== POS )))
										?
						 SC_LOGIC_1 : SC_LOGIC_0;
			break;
		}
		case( DIV):{

			ret = SC_LOGIC_0;
			break;
		}
		default:break;

	}
	return ret;

}
/*
 *
 */
sc_logic ALU::ALUReportOverflow(sc_uint<3> opsel){

	sc_logic ret = SC_LOGIC_0;
	sc_int<DATAWIDTH> a = data1.read();
	sc_int<DATAWIDTH> b = data2.read();
	sc_int<DATAWIDTH> res = acc.read();

	switch(opsel.to_uint()){
		case (ADD):{
			ret = ((Sign(a) == POS) & (Sign(b)== POS) & (Sign(res)== NEG)) ? SC_LOGIC_1 : SC_LOGIC_0;
			break;
		}
		case (MUL):{
			ret = (((Sign(a) == POS) & (Sign(b) == POS) & (Sign(res) == NEG))
										|
				  ((Sign(a) == NEG) & (Sign(b) == NEG ) & (Sign(res)== NEG )))
										?
						 SC_LOGIC_1 : SC_LOGIC_0;
			break;
		}
		case( DIV):{
			ret = divOF;
		}
		default:break;

	}
	return ret;
}

/*
*
*/
sc_logic ALU::ALUSetZFlag(void){

	return ((accu == 0) ? SC_LOGIC_1 : SC_LOGIC_0);
}

/*
 *
 */
sc_logic ALU::ALUSetCFlag(sc_uint<3> opsel){

	sc_logic ret = SC_LOGIC_0;
	sc_int<DATAWIDTH> a = data1.read();
	sc_int<DATAWIDTH> b = data2.read();
	sc_int<DATAWIDTH> res = accu;

	switch(opsel){

		case ADD:{
			ret = (((Sign(a) == NEG) & (Sign(b) == NEG) & (Sign(res) == NEG))
						|
				  ((Sign(a) == NEG) & (Sign(b) == POS) & (Sign(res) == POS))
						|
				  ((Sign(a) == POS) & (Sign(b) == NEG) & (Sign(res) == POS)));
					break;
		}
		case ROR:{
			ret = (((sc_bv<DATAWIDTH>)a[0]).to_uint() ? NEG : POS);
			break;
		}
		case ROL:{
			ret = (((sc_bv<DATAWIDTH>)a[DATAWIDTH-1]).to_uint() ? NEG : POS);
			break;
		}
		case MUL:{
				ret = ((((Sign(a) == POS) & (Sign(b) == POS) & (Sign(res) == NEG))| // Overflow
				  ((Sign(a) == NEG) & (Sign(b) == NEG ) & (Sign(res)== NEG )))
				  	  	  	  	  	  	  |
				  (((Sign(a) == POS) & (Sign(b) == NEG) & (Sign(res) == POS))// |
				  	  	  	  	  										|
				  ((Sign(a) == NEG) & (Sign(b) == POS ) & (Sign(res)== POS ))));//Underflow
				break;
		}
		default: break;
	}

	return ret;
}

/*
 *
 */
sc_logic ALU::Sign(sc_int<DATAWIDTH> var){

	 return (((sc_bv<DATAWIDTH>)var[DATAWIDTH-1]).to_uint() ? NEG : POS);

}

/*
 *
 */
void ALU::AluInitialize(void){

	data1.write(0);
	data2.write(0);
	acc.write(0) ;
	stat.write(0);
}
