// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include <iostream>
#include "poly.h"

// TODO: implement your function(s) for your Module here
void polynom::evalPolynom(){
    double result = 0.0;

    result = 0.0;
    for( int i= 0; i <=int(poly_degree); i++ )
    {
        result = result + ( poly_coeff[i] * (pow(X, i)));
    }
    F.write(result);
}
