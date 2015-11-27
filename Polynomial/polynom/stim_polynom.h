// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

// #pragma once

#include "systemc.h"
SC_MODULE(stim_polynom)
{
  sc_out<double> X;
  sc_in<bool> Clk;

  void StimGen_polynom()
  {
    // calculate values in range [a, b)
    double a = -5; // begin of range
    double b = 5;  // end of range 
    int c = 20;

    double incr = (b-a)/c;
    
    // assign v values and let evaluator run
    for(int i=0; i<c; i++)
    {
      double v = a + i*incr;

      X.write(v);
      wait();
    }
    // simulation end
    sc_stop();
  }

  // create module
  SC_CTOR(stim_polynom)
  {
    SC_THREAD(StimGen_polynom);
    sensitive << Clk.pos();
  }
};
