// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#pragma once

#include "systemc.h"
#include <math.h>
#include <iostream>
#include "poly.h"

SC_MODULE(mon_polynom)
{
  sc_in<double> X, Y;
  sc_in<bool> Clk;

  void monitor_polynom()
  {
    // cout << sc_time_stamp()  << "\t" << X << "\t" << Y <<endl;
    // check result
    double epsi = 0.00001;
    double correct;

    {
      int i;
      double res = 0.0;
     
      for(i=poly_degree; i >= 0; i--)
      {
        res = res * X + poly_coeff[i];
      }
      correct = res;
    }// source: http://rosettacode.org/wiki/Horner%27s_rule_for_polynomial_evaluation#C

    if( abs(correct-Y) > epsi )
        cout << endl << "ERROR: Wrong Result for X = " << X 
        << " (Calculated Result: " << Y 
        << ", Correct Result: " << correct 
        << ", Difference: " << (correct - Y) << ")" 
      << std::endl;
    else
      cout << "Correct result for X = " << X << std::endl;
    // else cout << "Correct Result at " << sc_time_stamp() << ", ";

  }
  SC_CTOR(mon_polynom)
  {
    cout << endl <<  "Simulation started" << endl;
    SC_METHOD(monitor_polynom);
    sensitive << Clk.pos();
    dont_initialize();
    // cout << endl <<  "Simulation finished after " << sc_time_stamp() << endl;
  }
};
