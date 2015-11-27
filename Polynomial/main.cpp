// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
// 
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
// 
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "polyInt.h"
#include "polyInt_tb.h"

using namespace std;

/*
         (Testbench)             (clk)        (Poly Integral module)   (Polynomial evaluation module)
	 -----------              |                -----------           ----------
	|           |             |               |           |         |          |
	|       clk |<--------------------------->| clk      X|-------->| X        |
	|           |                             |           |         |          |
	|       lLim|---------------------------->| lLim      |         |          |
	|           |                             |          F|<--------| F        |
	|       uLim|---------------------------->| uLim      |         |          |
	|           |                             |           |          ----------
	| (Result)F |<----------------------------| F( Result)|
	|           |                             |           |
	|      valid|---------------------------->|valid      | 
	|           |                             |           |
	|      ready|<----------------------------|ready      |
	|           |                             |           |
	|     oReady|---------------------------->|oReady     |
	|           |                             |           |
	|     oValid|<----------------------------|oValid     |
	|           |                             |           |	
	 -----------                               ----------- 
	
*/

int sc_main(int argc, char* argv[])
{
  sc_signal<double> ASig, BSig, ResSig;
  sc_signal<bool> StartSig, FinishSig, Ovalid, Oready;

// a clock that has a positive edge only at 10 ns 
  sc_clock TestClk("TestClock", 10, SC_NS,0.5, 10, SC_NS);

	/* Instanciate module */
	polyIntegral* polyn;
	polyn = new polyIntegral("polyn");
	/* Instanciate TestBench */	
	polyIntegral_TB* polyTB;
	polyTB = new polyIntegral_TB("polyTB");
	
	/* Connect the instances */	
	polyn->Clk(TestClk);
	polyn->lower_lim(ASig);
	polyn->upper_lim(BSig);
	polyn->F(ResSig);
	polyn->valid(StartSig);
	polyn->ready(FinishSig);
	polyn->oValid(Ovalid);
	polyn->oReady(Oready);
	polyTB->Clk(TestClk);
	polyTB->lower_lim(ASig);
	polyTB->upper_lim(BSig);
	polyTB->F(ResSig);
	polyTB->valid(StartSig);
	polyTB->ready(FinishSig);
	polyTB->oValid(Ovalid);
	polyTB->oReady(Oready);

  sc_start();  // run forever

  /* Destoy objects */	
  delete(polyn);
  delete(polyTB);

  return 0;

}
