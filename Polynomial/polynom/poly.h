// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#ifndef POLY_H
#define POLY_H
#include "systemc.h"

// simple polynomial for easy debugging
// configurable degree of polynomial
const unsigned int poly_degree = 2;

// configurable coefficients (index equal to associated power of x)
const double poly_coeff[poly_degree + 1] = {
  0,
  0,
  1
};

/*
// more complex polynomial for extensive testing
// configurable degree of polynomial
const unsigned int poly_degree = 7;

// configurable coefficients (index equal to associated power of x)
const double poly_coeff[poly_degree + 1] = {
  8.34,
  20.0,
  1.64,
  -28.73,
  92.429,
  48.902,
  98.902,
  34.565
};
*/


// TODO: define the functions you need for the module here

/* TODO: define your Module here
* The modules task is to calculate the function value of a fixed polynom (defined above) at a variable argument.
* The argument is the input to the module and the function value is the ouput.
* inputs and output type is double (see main.cpp)
* 
* Please use functions to keep this module definition as simple and small as possible.
*/

SC_MODULE(polynom){
    sc_in<double> X;
    sc_out<double> F;

    void evalPolynom(void);

    SC_CTOR(polynom){
        SC_METHOD(evalPolynom);
        sensitive<< X;
        dont_initialize();
    }
};

#endif // POLY_H
