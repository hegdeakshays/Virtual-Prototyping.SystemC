// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#ifndef POLYINT_TB_H
#define POLYINT_TB_H   
#include "systemc.h"

// TODO: Define your Testbench Module here


/* TestBench module */
SC_MODULE(polyIntegral_TB){

    sc_in<bool> Clk;
    sc_out<double> lower_lim;
    sc_out<double> upper_lim;
    sc_in<double> F;
    // Handshake ports
    sc_out<bool> valid;
    sc_in<bool>  ready;
    sc_out<bool> oReady;
    sc_in<bool> oValid;
    
    void initializeModule(void);
    double evaluatePolyIntegral(double lLim, double ulim);
    void stimulus(void);

    SC_CTOR(polyIntegral_TB){

        SC_THREAD(stimulus);
        sensitive<<Clk.pos();

    }

};

#endif // POLYINT_TB_H
