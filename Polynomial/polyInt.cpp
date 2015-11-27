// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt.h"

/********************************************************************************/
void polyIntegral::evaluatePolyIntegral(){

   while(1){
	
	double uLim = 0.0;
	double lLim = 0.0;
	double result = 0.0;
	initializeModule();

	do {
		wait();
	} while ( valid.read() == 0);

	
	lLim = lower_lim.read();
	uLim = upper_lim.read();
	result = simpsonsIntegral( lLim, uLim, INT_RESOLUTION);
	F.write( result );
	ready.write(1);
	wait();
   }
}
/********************************************************************************/


/********************************************************************************/

double polyIntegral::evalPolynomial( double x){
	oValid.write(0);
	X_SIG.write(x);
	do{
		wait();
	}while( oReady.read() == 0);
		oValid.write(1);
	return F_SIG.read();
}


/*********************************************************************************
*    b
*   /                                          
*   | f(x) dx =  ( b - a) . [ f(a) - 4.f (0.5. (a + b ) )  + f(b) ]
*  /               -----                 
* a                  6     
*              
**********************************************************************************/ 
double polyIntegral::simpsonsIntegral(double lLim, double uLim, double approxs) {
    //cout <<"ULim , LLim = "<<lLim<<","<<uLim<<endl;
	double h = (uLim - lLim) / approxs;
	double s1 = evalPolynomial(lLim + h/2.0);
	double s2 = 0.0;
	int i = 0;
	while ( i < approxs) {
		s1 = s1 + evalPolynomial( lLim + h * i + h /2.0);
		s2 = s2 + evalPolynomial(lLim + h * i);
		i++;	
	}
	return (( h / 6) * ( evalPolynomial(lLim) + 
			 evalPolynomial(uLim) + 4 * s1 + 2 * s2));
}

/********************************************************************************/
void polyIntegral::initializeModule(void){
	
	ready.write(0);

}
/********************************************************************************/
