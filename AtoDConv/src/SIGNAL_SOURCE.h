/*
 * SIGNAL_SOURCE.h
 *
 *  Created on: Sep 11, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef SIGNAL_SOURCE_H_
#define SIGNAL_SOURCE_H_

#include "GLOBAL_SHARED_CONSTS.h"

#define SIGNAL_SIN_FREQUENCY (SIN_FREQ)
#define SIGNAL_COS_FREQUENCY (COS_FREQ)
#define SIGNAL_SAW_FREQUENCY (SAW_FREQ)
#define SIGNAL_SIN_AMPL	(SIN_AMPL)
#define SIGNAL_COS_AMPL (COS_AMPL)
#define SIGNAL_SAW_AMPl	(SAW_AMPL)
#define SIN_PORT_TIME_STEP	(SIN_TS_NS)
#define SIN_COS_TIME_STEP	(COS_TS_NS)
#define SIN_SAW_TIME_STEP	(SAW_TS_NS)

#include <systemc-ams.h>                   // SystemC AMS header

SCA_TDF_MODULE(signal_source)				// Declare a TDF module
{
  sca_tdf::sca_out<double> sin_out;			// TDF output port For Sine wave
  sca_tdf::sca_out<double> cos_out;			// TDF output port for Cosine wave

  //parameter
  double ampl_sin, ampl_cos; //   amplitude
  double freq_sin, freq_cos; //   frequency

  void set_attributes();					// Set TDF attributes
  void processing();						// Describe time-domain behaviour

  SCA_CTOR(signal_source)					// Constructor of the TDF module
  :sin_out("sin_out"),
   cos_out("cos_out"),
   ampl_sin(SIGNAL_SIN_AMPL),
   ampl_cos(SIGNAL_COS_AMPL),
   freq_sin(SIGNAL_SIN_FREQUENCY),
   freq_cos(SIGNAL_COS_FREQUENCY)
   {}					// Name the port(s)// Initial values for ampl and freq
};

#endif /* SIGNAL_SOURCE_H_ */
