// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>


#ifndef POLYMOD_H
#define POLYMOD_H   
#include "systemc.h"
#include "polynom/poly.h"

/* Adjust the integral resoultion for accuracy */
const double INT_RESOLUTION = 1000000.00;

SC_MODULE(polyIntegral){

    sc_in<bool> Clk;
    sc_in<double> lower_lim;
    sc_in<double> upper_lim;
    sc_out<double> F;

    /*Handshake ports */
    sc_in<bool>  valid;
    sc_out<bool>  ready;
    sc_in<bool> oReady;
    sc_out<bool> oValid;
   
 
    sc_signal<double> X_SIG;
    sc_signal<double> F_SIG;

    /* Instanciate polynomial evaluation module 
	Combinational module : Sensitive to input */
    polynom* polyFn;

    void initializeModule(void);
    void evaluatePolyIntegral(void);
    double evalPolynomial( double x);
    double simpsonsIntegral(double lLim, double uLim, double resolution);

    SC_CTOR(polyIntegral){
        polyFn = new polynom("polyFn");
        polyFn->X(X_SIG);
        polyFn->F(F_SIG);
        SC_THREAD(evaluatePolyIntegral);
        sensitive<<Clk.pos();

    }

    ~polyIntegral(){
	delete(polyFn);
     }

};

#endif // POLYMOD_H
