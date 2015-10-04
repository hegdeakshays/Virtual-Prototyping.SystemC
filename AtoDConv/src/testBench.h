/*
 * testBench.h
 *
 *  Created on: Sep 29, 2015
 *      Author: kannoth
 *      Email : s_kannoth14@informatik.uni-kl.de
 */

#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include "ADC_REGISTERS_MAP.h"
#include  <bitset>
#include <systemc>
using namespace std;

class TestBench{
private:
public:
	TestBench				(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time);
	void ADC_Configuration	(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time);
	void ADC_GetStatus		(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time);
	void ADC_GetData		(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time);
	~TestBench();
};

#endif /* TESTBENCH_H_ */
