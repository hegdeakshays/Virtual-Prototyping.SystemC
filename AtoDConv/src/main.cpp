/*
 * main.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#include <iostream>
#include <systemc>
#include <systemc-ams>
#include <bitset>

#include "ADC_REGISTERS_MAP.h"
#include "SIGNAL_SOURCE.h"
#include "tuv_ams_library.h"
#include "conv_tdf_sc.h"
#include "GLOBAL_SHARED_CONSTS.h"
#include "CHANNEL_BYPASS.h"
#include "ADC_USER_CONFIG.h"
#include "TLM_COMM_CONTROL.h"
#include "ADC_CH_GAIN_OFFSET.h"
#include "SrvBitLib.h"
#include "modules.h"
#include "testBench.h"


using namespace std;
using namespace TUV_ams_lib::bb;

SCA_TDF_MODULE(drain) {
	sca_tdf::sca_in<sc_bv<ADC_BV_LEN> > in;
	SCA_CTOR(drain){
	}
};


int sc_main(int argc, char* arcv[]){


	ADC_CONTROL_REGISTERS_t* AdcConfReg = new ADC_CONTROL_REGISTERS_t();

	sc_set_time_resolution(1, SC_NS);	// setting the time resolution
	channelBypass* bypass;
	bypass = new channelBypass("bypass");
	bypass->AdcConfReg = AdcConfReg;

	TestBench* tb = new TestBench(AdcConfReg, sc_time_stamp());
	adcUsrConf* adcConfig;
	adcConfig = new adcUsrConf(AdcConfReg);

	/* Clock generation of ADC based on PRESCAL : Resolution = 1uS  */
	sc_clock adcClk("adcClk", (1000000)/(adcConfig->ADCClock), SC_US);

	AdcGainOffSet_t* adcGainOffset		= new AdcGainOffSet(AdcConfReg,ADCVREF);
	CommControl* com;
	glbClkTick* glbCktk;
	com = new CommControl("com");
	glbCktk = new glbClkTick();
	com->initiater->clk(adcClk);
	com->initiater->PVCmd = 1;
	com->initiater->adcReg=AdcConfReg;
	com->initiater->glbCktk = glbCktk;
	com->memory->glbCktk = glbCktk;
	com->memory->adcReg=AdcConfReg;

	sca_tdf::sca_signal<double>sig_in0 ; sca_tdf::sca_signal<double>sig_in_amp0 ;sca_tdf::sca_signal<double>sig_in_offset0 ;
	sca_tdf::sca_signal<double>sig_in1 ; sca_tdf::sca_signal<double>sig_in_amp1 ;sca_tdf::sca_signal<double>sig_in_offset1 ;
	sca_tdf::sca_signal<double>sig_in2 ; sca_tdf::sca_signal<double>sig_in_amp2 ;sca_tdf::sca_signal<double>sig_in_offset2 ;
	sca_tdf::sca_signal<double>sig_in3 ; sca_tdf::sca_signal<double>sig_in_amp3 ;sca_tdf::sca_signal<double>sig_in_offset3 ;
	sca_tdf::sca_signal<double>sig_in4 ; sca_tdf::sca_signal<double>sig_in_amp4 ;sca_tdf::sca_signal<double>sig_in_offset4 ;
	sca_tdf::sca_signal<double>sig_in5 ; sca_tdf::sca_signal<double>sig_in_amp5 ;sca_tdf::sca_signal<double>sig_in_offset5 ;
	sca_tdf::sca_signal<double>sig_in6 ; sca_tdf::sca_signal<double>sig_in_amp6 ;sca_tdf::sca_signal<double>sig_in_offset6 ;
	sca_tdf::sca_signal<double>sig_in7 ; sca_tdf::sca_signal<double>sig_in_amp7 ;sca_tdf::sca_signal<double>sig_in_offset7 ;
	sca_tdf::sca_signal<double>sig_in8 ; sca_tdf::sca_signal<double>sig_in_amp8 ;sca_tdf::sca_signal<double>sig_in_offset8 ;
	sca_tdf::sca_signal<double>sig_in9 ; sca_tdf::sca_signal<double>sig_in_amp9 ;sca_tdf::sca_signal<double>sig_in_offset9 ;
	sca_tdf::sca_signal<double>sig_in10; sca_tdf::sca_signal<double>sig_in_amp10;sca_tdf::sca_signal<double>sig_in_offset10;
	sca_tdf::sca_signal<double>sig_in11; sca_tdf::sca_signal<double>sig_in_amp11;sca_tdf::sca_signal<double>sig_in_offset11;
	sca_tdf::sca_signal<double>sig_in12; sca_tdf::sca_signal<double>sig_in_amp12;sca_tdf::sca_signal<double>sig_in_offset12;
	sca_tdf::sca_signal<double>sig_in13; sca_tdf::sca_signal<double>sig_in_amp13;sca_tdf::sca_signal<double>sig_in_offset13;
	sca_tdf::sca_signal<double>sig_in14; sca_tdf::sca_signal<double>sig_in_amp14;sca_tdf::sca_signal<double>sig_in_offset14;
	sca_tdf::sca_signal<double>sig_in15; sca_tdf::sca_signal<double>sig_in_amp15;sca_tdf::sca_signal<double>sig_in_offset15;

	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out0 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out0 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out1 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out1 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out2 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out2 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out3 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out3 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out4 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out4 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out5 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out5 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out6 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out6 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out7 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out7 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out8 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out8 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out9 ;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out9 ;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out10;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out10;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out11;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out11;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out12;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out12;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out13;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out13;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out14;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out14;
	sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> >	 sig_out15;sca_tdf::sca_signal<sc_bv<ADC_BV_LEN> > sig_byp_out15;

	/* Sine and Cosine source*/
	signal_source* source;
	source = new signal_source("source");
	/* Sawtooth source 		*/
	saw_gen* saw;
	saw = new saw_gen("saw",SIGNAL_SAW_FREQUENCY,SAW_AMPL,0.0,1);
	 /*Noise source is instanciated for the open channels*/
	 noise_gauss noise_0("noise_0"),noise_1("noise_1"),noise_2("noise_2"),noise_4("noise_4"),noise_6("noise_6"),
				noise_8("noise_8"),noise_9("noise_9"),noise_10("noise_10"),noise_11("noise_11"),noise_12("noise_12"),
				noise_13("noise_13"),noise_14("noise_14"),noise_15("noise_15");

	 /* PGA instances for each channedl*/
	amp<double> ampl0 ("ampl0" ,adcGainOffset->adcGain[0 ]);add_offset<double> offset0 ("offset0" ,adcGainOffset->adcOffset[0 ]);
	amp<double> ampl1 ("ampl1" ,adcGainOffset->adcGain[1 ]);add_offset<double> offset1 ("offset1" ,adcGainOffset->adcOffset[1 ]);
	amp<double> ampl2 ("ampl2" ,adcGainOffset->adcGain[2 ]);add_offset<double> offset2 ("offset2" ,adcGainOffset->adcOffset[2 ]);
	amp<double> ampl3 ("ampl3" ,adcGainOffset->adcGain[3 ]);add_offset<double> offset3 ("offset3" ,adcGainOffset->adcOffset[3 ]);
	amp<double> ampl4 ("ampl4" ,adcGainOffset->adcGain[4 ]);add_offset<double> offset4 ("offset4" ,adcGainOffset->adcOffset[4 ]);
	amp<double> ampl5 ("ampl5" ,adcGainOffset->adcGain[5 ]);add_offset<double> offset5 ("offset5" ,adcGainOffset->adcOffset[5 ]);
	amp<double> ampl6 ("ampl6" ,adcGainOffset->adcGain[6 ]);add_offset<double> offset6 ("offset6" ,adcGainOffset->adcOffset[6 ]);
	amp<double> ampl7 ("ampl7" ,adcGainOffset->adcGain[7 ]);add_offset<double> offset7 ("offset7" ,adcGainOffset->adcOffset[7 ]);
	amp<double> ampl8 ("ampl8" ,adcGainOffset->adcGain[8 ]);add_offset<double> offset8 ("offset8" ,adcGainOffset->adcOffset[8 ]);
	amp<double> ampl9 ("ampl9" ,adcGainOffset->adcGain[9 ]);add_offset<double> offset9 ("offset9" ,adcGainOffset->adcOffset[9 ]);
	amp<double> ampl10("ampl10",adcGainOffset->adcGain[10]);add_offset<double> offset10("offset10",adcGainOffset->adcOffset[10]);
	amp<double> ampl11("ampl11",adcGainOffset->adcGain[11]);add_offset<double> offset11("offset11",adcGainOffset->adcOffset[11]);
	amp<double> ampl12("ampl12",adcGainOffset->adcGain[12]);add_offset<double> offset12("offset12",adcGainOffset->adcOffset[12]);
	amp<double> ampl13("ampl13",adcGainOffset->adcGain[13]);add_offset<double> offset13("offset13",adcGainOffset->adcOffset[13]);
	amp<double> ampl14("ampl14",adcGainOffset->adcGain[14]);add_offset<double> offset14("offset14",adcGainOffset->adcOffset[14]);
	amp<double> ampl15("ampl15",adcGainOffset->adcGain[15]);add_offset<double> offset15("offset15",adcGainOffset->adcOffset[15]);


	/*	ADC instances for each channel				 */
	adc<ADC_BV_LEN> adc_ch0("adc_ch0", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch1("adc_ch1", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch2("adc_ch2", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch3("adc_ch3", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch4("adc_ch4", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch5("adc_ch5", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch6("adc_ch6", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch7("adc_ch7", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch8("adc_ch8", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch9("adc_ch9", 	ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch10("adc_ch10",ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch11("adc_ch11",ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch12("adc_ch12",ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch13("adc_ch13",ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch14("adc_ch14",ADCVREF, 0.0, 0.0);
	adc<ADC_BV_LEN> adc_ch15("adc_ch15",ADCVREF, 0.0, 0.0);

	/* Signal source intances        */
	source->sin_out(sig_in3);
	source->cos_out(sig_in5);
	saw->out(sig_in7);
    saw->set_timestep(10, sc_core::SC_NS);
	noise_0.out (sig_in0 ); noise_0 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_1.out (sig_in1 ); noise_1 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_2.out (sig_in2 ); noise_2 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_4.out (sig_in4 ); noise_4 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_6.out (sig_in6 ); noise_6 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_8.out (sig_in8 ); noise_8 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_9.out (sig_in9 ); noise_9 .set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_10.out(sig_in10); noise_10.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_11.out(sig_in11); noise_11.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_12.out(sig_in12); noise_12.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_13.out(sig_in13); noise_13.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_14.out(sig_in14); noise_14.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);
	noise_15.out(sig_in15); noise_15.set_timestep(T_SAMPLE_GLB, sc_core::SC_NS);

	ampl0 .in(sig_in0 );ampl0 .out(sig_in_amp0 );offset0 .in(sig_in_amp0 );offset0 .out(sig_in_offset0 );
	ampl1 .in(sig_in1 );ampl1 .out(sig_in_amp1 );offset1 .in(sig_in_amp1 );offset1 .out(sig_in_offset1 );
	ampl2 .in(sig_in2 );ampl2 .out(sig_in_amp2 );offset2 .in(sig_in_amp2 );offset2 .out(sig_in_offset2 );
	ampl3 .in(sig_in3 );ampl3 .out(sig_in_amp3 );offset3 .in(sig_in_amp3 );offset3 .out(sig_in_offset3 );
	ampl4 .in(sig_in4 );ampl4 .out(sig_in_amp4 );offset4 .in(sig_in_amp4 );offset4 .out(sig_in_offset4 );
	ampl5 .in(sig_in5 );ampl5 .out(sig_in_amp5 );offset5 .in(sig_in_amp5 );offset5 .out(sig_in_offset5 );
	ampl6 .in(sig_in6 );ampl6 .out(sig_in_amp6 );offset6 .in(sig_in_amp6 );offset6 .out(sig_in_offset6 );
	ampl7 .in(sig_in7 );ampl7 .out(sig_in_amp7 );offset7 .in(sig_in_amp7 );offset7 .out(sig_in_offset7 );
	ampl8 .in(sig_in8 );ampl8 .out(sig_in_amp8 );offset8 .in(sig_in_amp8 );offset8 .out(sig_in_offset8 );
	ampl9 .in(sig_in9 );ampl9 .out(sig_in_amp9 );offset9 .in(sig_in_amp9 );offset9 .out(sig_in_offset9 );
	ampl10.in(sig_in10);ampl10.out(sig_in_amp10);offset10.in(sig_in_amp10);offset10.out(sig_in_offset10);
	ampl11.in(sig_in11);ampl11.out(sig_in_amp11);offset11.in(sig_in_amp11);offset11.out(sig_in_offset11);
	ampl12.in(sig_in12);ampl12.out(sig_in_amp12);offset12.in(sig_in_amp12);offset12.out(sig_in_offset12);
	ampl13.in(sig_in13);ampl13.out(sig_in_amp13);offset13.in(sig_in_amp13);offset13.out(sig_in_offset13);
	ampl14.in(sig_in14);ampl14.out(sig_in_amp14);offset14.in(sig_in_amp14);offset14.out(sig_in_offset14);
	ampl15.in(sig_in15);ampl15.out(sig_in_amp15);offset15.in(sig_in_amp15);offset15.out(sig_in_offset15);


	////////////////////////////////////////
	/* Signal source to ADC interface     */
	/* Unused channels are connected with */
	/* noise signals                      */
	////////////////////////////////////////
	// ADC in
	adc_ch0 .in(sig_in_offset0 );	// NOT USED
	adc_ch1 .in(sig_in_offset1 );	// NOT USED
	adc_ch2 .in(sig_in_offset2 );	// NOT USED*/
	adc_ch3 .in(sig_in_offset3 );	// USED - connected to Sine
	adc_ch4 .in(sig_in_offset4 );	// NOT USED
	adc_ch5 .in(sig_in_offset5 );	// USED - connected to Cosine
	adc_ch6 .in(sig_in_offset6 );	// NOT USED
	adc_ch7 .in(sig_in_offset7 );	// USED - connected to Sawtooth
	adc_ch8 .in(sig_in_offset8 );	// NOT USED
	adc_ch9 .in(sig_in_offset9 );	// NOT USED
	adc_ch10.in(sig_in_offset10);// NOT USED
	adc_ch11.in(sig_in_offset11);// NOT USED
	adc_ch12.in(sig_in_offset12);// NOT USED
	adc_ch13.in(sig_in_offset13);// NOT USED
	adc_ch14.in(sig_in_offset14);// NOT USED*/
	adc_ch15.in(sig_in_offset15);// NOT USED*/
	// ADC out
	adc_ch0.out(sig_out0);  // NOT USED
	adc_ch1.out(sig_out1);  // NOT USED
	adc_ch2.out(sig_out2);  // NOT USED*/
	adc_ch3.out(sig_out3); // USED - connected to Sine
	adc_ch4.out(sig_out4);  // NOT USED
	adc_ch5.out(sig_out5); // USED - connected to Cosine
	adc_ch6.out(sig_out6);  // NOT USED
	adc_ch7.out(sig_out7); // USED - connected to Sawtooth
	adc_ch8.out(sig_out8);  // NOT USED
	adc_ch9.out(sig_out9);  // NOT USED
	adc_ch10.out(sig_out10);// NOT USED
	adc_ch11.out(sig_out11);// NOT USED
	adc_ch12.out(sig_out12);// NOT USED
	adc_ch13.out(sig_out13);// NOT USED
	adc_ch14.out(sig_out14);// NOT USED*/
	adc_ch15.out(sig_out15);// NOT USED*/

	drain drn_0("drn_0")  ;drn_0.in (sig_out0 );
	drain drn_1("drn_1")  ;drn_1.in (sig_out1 );
	drain drn_2("drn_2")  ;drn_2.in (sig_out2 );
	drain drn_3("drn_3")  ;drn_3.in (sig_out3 );
	drain drn_4("drn_4")  ;drn_4.in (sig_out4 );
	drain drn_5("drn_5")  ;drn_5.in (sig_out5 );
	drain drn_6("drn_6")  ;drn_6.in (sig_out6 );
	drain drn_7("drn_7")  ;drn_7.in (sig_out7 );
	drain drn_8("drn_8")  ;drn_8.in (sig_out8 );
	drain drn_9("drn_9")  ;drn_9.in (sig_out9 );
	drain drn_10("drn_10");drn_10.in(sig_out10);
	drain drn_11("drn_11");drn_11.in(sig_out11);
	drain drn_12("drn_12");drn_12.in(sig_out12);
	drain drn_13("drn_13");drn_13.in(sig_out13);
	drain drn_14("drn_14");drn_14.in(sig_out14);
	drain drn_15("drn_15");drn_15.in(sig_out15);

	/* Bypassing converted signals for applying register configuration */
	bypass->in0 (sig_out0 ); bypass->out0 (sig_byp_out0 );
	bypass->in1 (sig_out1 ); bypass->out1 (sig_byp_out1 );
	bypass->in2 (sig_out2 ); bypass->out2 (sig_byp_out2 );
	bypass->in3 (sig_out3 ); bypass->out3 (sig_byp_out3 );
	bypass->in4 (sig_out4 ); bypass->out4 (sig_byp_out4 );
	bypass->in5 (sig_out5 ); bypass->out5 (sig_byp_out5 );
	bypass->in6 (sig_out6 ); bypass->out6 (sig_byp_out6 );
	bypass->in7 (sig_out7 ); bypass->out7 (sig_byp_out7 );
	bypass->in8 (sig_out8 ); bypass->out8 (sig_byp_out8 );
	bypass->in9 (sig_out9 ); bypass->out9 (sig_byp_out9 );
	bypass->in10(sig_out10); bypass->out10(sig_byp_out10);
	bypass->in11(sig_out11); bypass->out11(sig_byp_out11);
	bypass->in12(sig_out12); bypass->out12(sig_byp_out12);
	bypass->in13(sig_out13); bypass->out13(sig_byp_out13);
	bypass->in14(sig_out14); bypass->out14(sig_byp_out14);
	bypass->in15(sig_out15); bypass->out15(sig_byp_out15);

	/* Interfacing  channel-0 to TLM slave ports                                         */
	/* This is necessary for transporting the converted data from TLM Slave to TLM Master*/
	/* Refer TLM_MASTER_INITIATER and TLM_SLAVE_TARGET files for details                 */
	sc_core::sc_signal<bool> dummych0;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh0;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch0;
	slv2MstrInfch0 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch0");
	slv2MstrInfch0->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch0->inTDF(sig_byp_out0);
	slv2MstrInfch0->outDE(prtCh0);
	slv2MstrInfch0->EOC(dummych0);
		com->memory->prtCh0DE(prtCh0);
	// Interfacing  channel-1 to TLM slave ports
	sc_core::sc_signal<bool> dummych1;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh1;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch1;
	slv2MstrInfch1 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch1");
	slv2MstrInfch1->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch1->inTDF(sig_byp_out1);
	slv2MstrInfch1->outDE(prtCh1);
	slv2MstrInfch1->EOC(dummych1);
		com->memory->prtCh1DE(prtCh1);
	// Interfacing  channel-2 to TLM slave ports
	sc_core::sc_signal<bool> dummych2;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh2;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch2;
	slv2MstrInfch2 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch2");
	slv2MstrInfch2->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch2->inTDF(sig_byp_out1);
	slv2MstrInfch2->outDE(prtCh2);
	slv2MstrInfch2->EOC(dummych2);
		com->memory->prtCh2DE(prtCh2);
	// Interfacing  channel-3 to TLM slave ports
	sc_core::sc_signal<bool> dummych3;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh3;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch3;
	slv2MstrInfch3 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch3");
	slv2MstrInfch3->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch3->inTDF(sig_byp_out3);
	slv2MstrInfch3->outDE(prtCh3);
	slv2MstrInfch3->EOC(dummych3);
		com->memory->prtCh3DE(prtCh3);
	// Interfacing  channel-4 to TLM slave ports
	sc_core::sc_signal<bool> dummych4;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh4;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch4;
	slv2MstrInfch4 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch4");
	slv2MstrInfch4->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch4->inTDF(sig_byp_out4);
	slv2MstrInfch4->outDE(prtCh4);
	slv2MstrInfch4->EOC(dummych4);
		com->memory->prtCh4DE(prtCh4);
	// Interfacing  channel-5 to TLM slave ports
	sc_core::sc_signal<bool> dummych5;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh5;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch5;
	slv2MstrInfch5 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch5");
	slv2MstrInfch5->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch5->inTDF(sig_byp_out5);
	slv2MstrInfch5->outDE(prtCh5);
	slv2MstrInfch5->EOC(dummych5);
		com->memory->prtCh5DE(prtCh5);

	// Interfacing  channel-6 to TLM slave ports
	sc_core::sc_signal<bool> dummych6;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh6;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch6;
	slv2MstrInfch6 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch6");
	slv2MstrInfch6->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch6->inTDF(sig_byp_out6);
	slv2MstrInfch6->outDE(prtCh6);
	slv2MstrInfch6->EOC(dummych6);
		com->memory->prtCh6DE(prtCh6);
	// Interfacing  channel-7 to TLM slave ports
	sc_core::sc_signal<bool> dummych7;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh7;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch7;
	slv2MstrInfch7 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch7");
	slv2MstrInfch7->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch7->inTDF(sig_byp_out7);
	slv2MstrInfch7->outDE(prtCh7);
	slv2MstrInfch7->EOC(dummych7);
		com->memory->prtCh7DE(prtCh7);
	// Interfacing  channel-8 to TLM slave ports
	sc_core::sc_signal<bool> dummych8;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh8;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch8;
	slv2MstrInfch8 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch8");
	slv2MstrInfch8->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch8->inTDF(sig_byp_out8);
	slv2MstrInfch8->outDE(prtCh8);
	slv2MstrInfch8->EOC(dummych8);
		com->memory->prtCh8DE(prtCh8);
	// Interfacing  channel-9 to TLM slave ports
	sc_core::sc_signal<bool> dummych9;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh9;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch9;
	slv2MstrInfch9 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch9");
	slv2MstrInfch9->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch9->inTDF(sig_byp_out9);
	slv2MstrInfch9->outDE(prtCh9);
	slv2MstrInfch9->EOC(dummych9);
		com->memory->prtCh9DE(prtCh9);
	// Interfacing  channel-10 to TLM slave ports
	sc_core::sc_signal<bool> dummych10;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh10;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch10;
	slv2MstrInfch10 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch10");
	slv2MstrInfch10->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch10->inTDF(sig_byp_out10);
	slv2MstrInfch10->outDE(prtCh10);
	slv2MstrInfch10->EOC(dummych10);
		com->memory->prtCh10DE(prtCh10);
	// Interfacing  channel-11 to TLM slave ports
	sc_core::sc_signal<bool> dummych11;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh11;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch11;
	slv2MstrInfch11 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch11");
	slv2MstrInfch11->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch11->inTDF(sig_byp_out11);
	slv2MstrInfch11->outDE(prtCh11);
	slv2MstrInfch11->EOC(dummych11);
		com->memory->prtCh11DE(prtCh11);
	// Interfacing  channel-12 to TLM slave ports
	sc_core::sc_signal<bool> dummych12;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh12;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch12;
	slv2MstrInfch12 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch12");
	slv2MstrInfch12->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch12->inTDF(sig_byp_out12);
	slv2MstrInfch12->outDE(prtCh12);
	slv2MstrInfch12->EOC(dummych12);
		com->memory->prtCh12DE(prtCh12);
	// Interfacing  channel-13 to TLM slave ports
	sc_core::sc_signal<bool> dummych13;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh13;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch13;
	slv2MstrInfch13 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch13");
	slv2MstrInfch13->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch13->inTDF(sig_byp_out13);
	slv2MstrInfch13->outDE(prtCh13);
	slv2MstrInfch13->EOC(dummych13);
		com->memory->prtCh13DE(prtCh13);
	// Interfacing  channel-14 to TLM slave ports
	sc_core::sc_signal<bool> dummych14;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh14;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch14;
	slv2MstrInfch14 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch14");
	slv2MstrInfch14->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch14->inTDF(sig_byp_out14);
	slv2MstrInfch14->outDE(prtCh14);
	slv2MstrInfch14->EOC(dummych14);
		com->memory->prtCh14DE(prtCh14);
	// Interfacing  channel-15 to TLM slave ports
	sc_core::sc_signal<bool> dummych15;
	sc_core::sc_signal<sc_bv<ADC_BV_LEN> > prtCh15;
	conv_tdf_sc<ADC_BV_LEN>* slv2MstrInfch15;
	slv2MstrInfch15 = new conv_tdf_sc<ADC_BV_LEN>("slv2MstrInfch15");
	slv2MstrInfch15->set_timestep(10, sc_core::SC_NS);
	slv2MstrInfch15->inTDF(sig_byp_out15);
	slv2MstrInfch15->outDE(prtCh15);
	slv2MstrInfch15->EOC(dummych15);
		com->memory->prtCh15DE(prtCh15);

/*////////////////////////////////////////////////////////////////////
 *  All the TDF and DE tracings are done below
////////////////////////////////////////////////////////////////////*/
	AdcFileLogger* adc_converted_trc_file = new AdcFileLogger("logAdcConv_at_master.dat","%t(ns)\tsin(t)\tcos(t)\tsaw(t)\tstartConv");
	com->initiater->logg= adc_converted_trc_file;
	sc_trace_file* fp=sc_create_vcd_trace_file("logVcd");
	sca_trace_file* tfp = sca_create_tabular_trace_file("logInputs");
	sca_trace(tfp, sig_in3, "sin");
	sca_trace(tfp, sig_in_amp3, "sin_amp");
	sca_trace(tfp, sig_in_offset3, "sin_amp_offset");
	sca_trace(tfp, sig_in5, "cos");
	sca_trace(tfp, sig_in_amp5, "cos_amp");
	sca_trace(tfp, sig_in_offset5, "cos_amp_offset");
	sca_trace(tfp, sig_in7, "saw");
	sca_trace(tfp, sig_in_amp7, "saw_amp");
	sca_trace(tfp, sig_in_offset7, "saw_amp_offset");
	sca_trace(tfp, sig_byp_out3, "sin_adc_out_BV");
	sca_trace(tfp, sig_byp_out5, "cos_adc_out_BV");
	sca_trace(tfp, sig_byp_out7, "saw_adc_out_BV");

	sc_core::sc_trace(fp,adcClk, "adcClk");
	sc_core::sc_trace(fp,prtCh3,"sin_BV");
	sc_core::sc_trace(fp,prtCh5,"cos_BV");
	sc_core::sc_trace(fp,prtCh7,"saw_BV");

	sc_start(1000, SC_US);
	sca_close_tabular_trace_file(tfp);
	sc_close_vcd_trace_file(fp);

	tb->ADC_GetStatus(AdcConfReg, sc_time_stamp());
	tb->ADC_GetData(AdcConfReg, sc_time_stamp());
	cout<<"................................................................................................................................."<<endl;
	cout<<"INFO : Refer the logAdcConv_at_master.dat file (Plott using gaw) to verify the converted data in Channel 3,5 and 7"<< endl;
	cout<<"INFO : Refer the logInputs.dat file (Plott using gaw) to verify the input values, gain, offset and converted binary vectors of Channel 3,5 and 7"<< endl;
	cout<<"INFO : Refer the logVcd.dat file (Plott using GtkWave) to verify the converted binary vectors of Channel 3,5 and 7"<< endl;
	cout<<"INFO : All the other channels than 3,5,7 are not enabled, so the values can be ignored"<< endl;
	cout<<"................................................................................................................................."<<endl;

	/* All the destructors for the created instances */
	delete(com			  );
	delete(AdcConfReg     );
	delete(adcGainOffset  );
	delete(bypass         );
	delete(source         );
	delete(saw			  );
	delete(slv2MstrInfch0 );
	delete(slv2MstrInfch1 );
	delete(slv2MstrInfch2 );
	delete(slv2MstrInfch3 );
	delete(slv2MstrInfch4 );
	delete(slv2MstrInfch5 );
	delete(slv2MstrInfch6 );
	delete(slv2MstrInfch7 );
	delete(slv2MstrInfch8 );
	delete(slv2MstrInfch9 );
	delete(slv2MstrInfch10);
	delete(slv2MstrInfch11);
	delete(slv2MstrInfch12);
	delete(slv2MstrInfch13);
	delete(slv2MstrInfch14);
	delete(slv2MstrInfch15);
	delete(adc_converted_trc_file);
	delete(tb);

	return 0;
}
