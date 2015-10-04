/*
 * sin_source.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */


#include "SIGNAL_SOURCE.h"

#include <cmath>															// for M_PI and std::sin


#define SIN_PORT_TIME_STEP	(SIN_TS_NS)
#define COS_PORT_TIME_STEP	(COS_TS_NS)
#define SAW_PORT_TIME_STEP	(SAW_TS_NS)

void signal_source::set_attributes()										// Set TDF attributes
{
  sin_out.set_timestep(SIN_PORT_TIME_STEP, SC_NS);											// Set time step of output port
  cos_out.set_timestep(COS_PORT_TIME_STEP, SC_NS);
}

void signal_source::processing()        									// Describe time-domain behaviour
{
  double t_1 = sin_out.get_time().to_seconds();								// Get current time of the sample
  double t_2 = cos_out.get_time().to_seconds();
  double x_1 = ampl_sin * std::sin(2.0 * M_PI * freq_sin * t_1);			// Calculate Sine wave
  double x_2 = ampl_cos * std::cos(2.0 * M_PI * freq_cos * t_2);			// Calculate Cosine wave
  sin_out.write(x_1);
  cos_out.write(x_2);
}

