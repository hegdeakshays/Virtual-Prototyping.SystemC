/*
 * alu16_tb.cpp
 *
 *  Created on: Jun 30, 2015
 *      Author: kannoth
 */

#include "miscmacros.h"
#include "alu16_tb.h"
/*
*/

void ALU_TB::ALU_TB_test(void){

	cout<<endl<<"............................................................."<<endl<<endl;
	//local for assert
	sc_int<16> tmp = 0;

	//System reset
	reset = (SC_LOGIC_0);
	reset = (SC_LOGIC_1);

	//ADD Normal
	data1.write(1500);
	data2.write(2100);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//ADD Normal with overflow
	data1.write(16384);
	data2.write(16384);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//ADD Normal with underflow
	data1.write(-18432);
	data2.write(-30720);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//ADD with carry
	data1.write(-8192);
	data2.write(-8192);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//ADD with carry
	data1.write(-16384);
	data2.write(24576);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//ADD with carry
	data1.write(24576);
	data2.write(-16383);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(ADD);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 3600 );
	PrintConsole(1,(char*)"ADD",0);

	//MUL Normal
	data1.write(2);
	data2.write(3);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(MUL);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == 6);
	PrintConsole(1,(char*)"MUL",0);

	//MUL Overflow
	data1.write(-16384);
	data2.write(-2);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(MUL);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 6);
	PrintConsole(1,(char*)"MUL",0);

	//MUL Underflow
	data1.write(-16384);
	data2.write(3);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(MUL);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == 6);
	PrintConsole(1,(char*)"MUL",0);

	//DIV Normal
	data1.write(512);
	data2.write(-8);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(DIV);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == (-64));
	PrintConsole(1,(char*)"DIV",0);

	//DIV Normal
	data1.write(1024);
	data2.write(4);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(DIV);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == (-64));
	PrintConsole(1,(char*)"DIV",0);

	//DIV by zero = Overflow
	data1.write(1024);
	data2.write(0);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(DIV);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	//assert (acc.read() == (-64));
	PrintConsole(1,(char*)"DIV",0);

	//ROL Normal
	data1.write(16384); //0100 0000 0000 0000 b
	tmp = 16384;
	op_sel.write(ROL);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (data1.read() == -32768 ); //1000 0000 0000 0000 b
	PrintConsole(2,(char*)"ROL",tmp);

	//ROL with carry
	data1.write(-16384); //1100 0000 0000 0000 b
	tmp = -16384;
	op_sel.write(ROL);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (data1.read() == -32767 ); //1000 0000 0000 0001 b
	PrintConsole(2,(char*)"ROL",tmp);

	//ROR normal
	data1.write(2); //0000 0000 0000 0010 b
	tmp = 2;
	op_sel.write(ROR);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (data1.read() == 1);
	PrintConsole(2,(char*)"ROR",tmp);

	//ROR with carry
	data1.write(3); //0000 0000 0000 0011 b
	tmp = 3;
	op_sel.write(ROR);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (data1.read() == -32767);
	PrintConsole(2,(char*)"ROR",tmp);


	//AND
	data1.write(43689);				//1101010101010100b
	data2.write(21845);				//0101010101010101b
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(AND);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == 21844);   //0101010101010100b
	PrintConsole(3,(char*)"AND",0);


	//OR
	data1.write(43689);				//1010101010101001b
	data2.write(21845);				//0101010101010101b
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(OR);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == -3);		//1111111111111101b
	PrintConsole(3,(char*)"OR",0);

	//XOR
	data1.write(43689);				//1010101010101001b
	data2.write(21845);				//0101010101010101b
	WAIT_FOR_A_CLOCK_NS(clk_out);
	op_sel.write(XOR);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	assert (acc.read() == -4);		//1111111111111100b
	PrintConsole(3,(char*)"XOR",0);

	reset = (SC_LOGIC_0);
	WAIT_FOR_A_CLOCK_NS(clk_out);
	reset = (SC_LOGIC_1);
	WAIT_FOR_A_CLOCK_NS(clk_out);


}

void ALU_TB::PrintConsole(int bi, char* opname, sc_bv<16> tmp){

	if (bi == 1){
		cout<<sc_time_stamp()<<"\t:"<<opname<<"("<<data1.read()<<","<<data2.read()<<")="<<acc.read()<<" ,STAT[X,X,X,UF,OF,S,C,Z] = "<<stat<<endl;
	}
	else if(bi == 2)
	{
		cout<<sc_time_stamp()<<"\t:"<<opname<<"("<<(sc_bv<16>)tmp<<")="<<(sc_bv<16>)data1.read()<<" ,STAT[X,X,X,UF,OF,S,C,Z] = "<<stat<<endl;
	}
	else if(bi==3){
		cout<<sc_time_stamp()<<"\t:"<<opname<<"("<<(sc_bv<16>)data1.read()<<","<<(sc_bv<16>)data2.read()<<")="<<(sc_bv<16>)acc.read()<<" ,STAT[X,X,X,UF,OF,S,C,Z] = "<<stat<<endl;
	}
	else{;}

}

