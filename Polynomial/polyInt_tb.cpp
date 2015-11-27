// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt_tb.h"
#include <poly.h>

/********************************************************************************/
double polyIntegral_TB::evaluatePolyIntegral(double lLim, double uLim){

	double result_a = 0.0;
    	double result_b = 0.0;
	for ( int i = 0; i <= int( poly_degree) ; i ++ ) {
		result_a = result_a + ( poly_coeff[i] * ((pow(uLim, i + 1))/(i+1)));
	}
	for ( int i = 0; i <= int( poly_degree) ; i ++ ) {
		result_b = result_b + ( poly_coeff[i] * ((pow(lLim, i + 1))/(i+1)));
	}

	return ( result_a - result_b);
}
/********************************************************************************/
/********************************************************************************/
void polyIntegral_TB::stimulus(void){
	double a = -5;
	double b = +5;
	double i = a;
	double result_TB = 0.0;
	double result_module = 0.0;
	
	initializeModule();

	/* Generate the Stimulus */
	while(  i <= b ){
		
		valid.write(1);
		oReady.write(1);
		result_TB = evaluatePolyIntegral ( i, b);
		/* Write generted test values to outpur ports */
		lower_lim.write(i);
		upper_lim.write(b);

		do{
			wait();	
		}while(ready.read()== 0);
		
		valid.write(0);
		
		do{
			wait();
		}while(oValid.read() == 0);
		
		result_module = F.read();
		oReady.write(0);

		cout <<"t = "<<sc_time_stamp()<<"\t, limits("
		     << i <<" ," <<b<<" )\t"<<" , Correct result = " 
		     <<result_TB << "\tCalculated Result : "
                       << result_module << "\t Relative Error = "
                       <<(result_TB - result_module )<< endl;

		i = i + 0.25;
		wait();
	}
	sc_stop();
}
/********************************************************************************/
/********************************************************************************/
void polyIntegral_TB::initializeModule(void){
	valid.write(0);
	oReady.write(0);
}
/********************************************************************************/
