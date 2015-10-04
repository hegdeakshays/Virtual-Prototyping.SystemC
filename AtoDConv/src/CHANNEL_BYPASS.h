/*
 * CHANNEL_BYPASS.h
 *
 *  Created on: Sep 19, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef CHANNEL_BYPASS_H_
#define CHANNEL_BYPASS_H_

#include <systemc-ams.h>
#include "GLOBAL_SHARED_CONSTS.h"
#include "ADC_REGISTERS_MAP.h"
#include "SrvBitLib.h"

#if (ADC_BV_LEN ==12)
	#define ADC_PORT_DEFVAL_BV "000000000000"
#elif (ADC_BV_LEN ==16)
	#define ADC_PORT_DEFVAL_BV "0000000000000000"
#endif

SCA_TDF_MODULE(channelBypass)
{
  public:
	ADC_CONTROL_REGISTERS_t* AdcConfReg;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in0;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in1;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in2;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in3;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in4;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in5;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in6;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in7;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in8;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in9;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in10;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in11;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in12;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in13;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in14;
	sca_tdf::sca_in <sc_bv<ADC_BV_LEN> > in15;

	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out0;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out1;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out2;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out3;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out4;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out5;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out6;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out7;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out8;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out9;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out10;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out11;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out12;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out13;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out14;
	sca_tdf::sca_out <sc_bv<ADC_BV_LEN> > out15;

	//ADC_CONTROL_REGISTERS_t* adcReg;
  private:

    void set_attributes();
    void processing();
  public:

   SCA_CTOR(channelBypass){}
};


#endif

