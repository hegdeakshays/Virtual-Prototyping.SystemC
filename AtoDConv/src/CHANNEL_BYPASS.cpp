/*
 * CHANNEL_BYPASS.cpp
 *
 *  Created on: Sep 19, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */


#include "CHANNEL_BYPASS.h"


void channelBypass::set_attributes(void){
   in0.set_timestep(T_SAMPLE_GLB, SC_NS);
   in1.set_timestep(T_SAMPLE_GLB, SC_NS);
   in2.set_timestep(T_SAMPLE_GLB, SC_NS);
   in3.set_timestep(T_SAMPLE_GLB, SC_NS);
   in4.set_timestep(T_SAMPLE_GLB, SC_NS);
   in5.set_timestep(T_SAMPLE_GLB, SC_NS);
   in6.set_timestep(T_SAMPLE_GLB, SC_NS);
   in7.set_timestep(T_SAMPLE_GLB, SC_NS);
   in8.set_timestep(T_SAMPLE_GLB, SC_NS);
   in9.set_timestep(T_SAMPLE_GLB, SC_NS);
   in10.set_timestep(T_SAMPLE_GLB, SC_NS);
   in11.set_timestep(T_SAMPLE_GLB, SC_NS);
   in12.set_timestep(T_SAMPLE_GLB, SC_NS);
   in13.set_timestep(T_SAMPLE_GLB, SC_NS);
   in14.set_timestep(T_SAMPLE_GLB, SC_NS);
   in15.set_timestep(T_SAMPLE_GLB, SC_NS);
   out0.set_timestep(T_SAMPLE_GLB, SC_NS);
   out1.set_timestep(T_SAMPLE_GLB, SC_NS);
   out2.set_timestep(T_SAMPLE_GLB, SC_NS);
   out3.set_timestep(T_SAMPLE_GLB, SC_NS);
   out4.set_timestep(T_SAMPLE_GLB, SC_NS);
   out5.set_timestep(T_SAMPLE_GLB, SC_NS);
   out6.set_timestep(T_SAMPLE_GLB, SC_NS);
   out7.set_timestep(T_SAMPLE_GLB, SC_NS);
   out8.set_timestep(T_SAMPLE_GLB, SC_NS);
   out9.set_timestep(T_SAMPLE_GLB, SC_NS);
   out10.set_timestep(T_SAMPLE_GLB, SC_NS);
   out11.set_timestep(T_SAMPLE_GLB, SC_NS);
   out12.set_timestep(T_SAMPLE_GLB, SC_NS);
   out13.set_timestep(T_SAMPLE_GLB, SC_NS);
   out14.set_timestep(T_SAMPLE_GLB, SC_NS);
   out15.set_timestep(T_SAMPLE_GLB, SC_NS);
}

void channelBypass::processing(void){

	sc_bv<ADC_BV_LEN>  bypReg0;
	sc_bv<ADC_BV_LEN>  bypReg1;
	sc_bv<ADC_BV_LEN>  bypReg2;
	sc_bv<ADC_BV_LEN>  bypReg3;
	sc_bv<ADC_BV_LEN>  bypReg4;
	sc_bv<ADC_BV_LEN>  bypReg5;
	sc_bv<ADC_BV_LEN>  bypReg6;
	sc_bv<ADC_BV_LEN>  bypReg7;
	sc_bv<ADC_BV_LEN>  bypReg8;
	sc_bv<ADC_BV_LEN>  bypReg9;
	sc_bv<ADC_BV_LEN>  bypReg10;
	sc_bv<ADC_BV_LEN>  bypReg11;
	sc_bv<ADC_BV_LEN>  bypReg12;
	sc_bv<ADC_BV_LEN>  bypReg13;
	sc_bv<ADC_BV_LEN>  bypReg14;
	sc_bv<ADC_BV_LEN>  bypReg15;

	bool ch0En  , ch0Ds, ch0SR;
	bool ch1En  , ch1Ds, ch1SR;
	bool ch2En  , ch2Ds, ch2SR;
	bool ch3En  , ch3Ds, ch3SR;
	bool ch4En  , ch4Ds, ch4SR;
	bool ch5En  , ch5Ds, ch5SR;
	bool ch6En  , ch6Ds, ch6SR;
	bool ch7En  , ch7Ds, ch7SR;
	bool ch8En  , ch8Ds, ch8SR;
	bool ch9En  , ch9Ds, ch9SR;
	bool ch10En ,ch10Ds,ch10SR;
	bool ch11En ,ch11Ds,ch11SR;
	bool ch12En ,ch12Ds,ch12SR;
	bool ch13En ,ch13Ds,ch13SR;
	bool ch14En ,ch14Ds,ch14SR;
	bool ch15En ,ch15Ds,ch15SR;

	/* Get all enabled channels from CHER */
	ch0En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),0);
	ch1En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),1);
	ch2En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),2);
	ch3En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),3);
	ch4En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),4);
	ch5En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),5);
	ch6En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),6);
	ch7En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),7);
	ch8En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),8);
	ch9En  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),9);
	ch10En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),10);
	ch11En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),11);
	ch12En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),12);
	ch13En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),13);
	ch14En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),14);
	ch15En = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038010),15);

	/* Get all disabled channels from CHER */
	ch0Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),0);
	ch1Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),1);
	ch2Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),2);
	ch3Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),3);
	ch4Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),4);
	ch5Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),5);
	ch6Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),6);
	ch7Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),7);
	ch8Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),8);
	ch9Ds  = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),9);
	ch10Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),10);
	ch11Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),11);
	ch12Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),12);
	ch13Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),13);
	ch14Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),14);
	ch15Ds = (bool)LibGetBitu32 (GET_ADC_REGISTERS(AdcConfReg,0x40038014),15);

	 ch0SR =  ((ch0En ) ? ((ch0Ds ) ? 0 : 1):0);
	 ch1SR =  ((ch1En ) ? ((ch1Ds ) ? 0 : 1):0);
	 ch2SR =  ((ch2En ) ? ((ch2Ds ) ? 0 : 1):0);
	 ch3SR =  ((ch3En ) ? ((ch3Ds ) ? 0 : 1):0);
	 ch4SR =  ((ch4En ) ? ((ch4Ds ) ? 0 : 1):0);
	 ch5SR =  ((ch5En ) ? ((ch5Ds ) ? 0 : 1):0);
	 ch6SR =  ((ch6En ) ? ((ch6Ds ) ? 0 : 1):0);
	 ch7SR =  ((ch7En ) ? ((ch7Ds ) ? 0 : 1):0);
	 ch8SR =  ((ch8En ) ? ((ch8Ds ) ? 0 : 1):0);
	 ch9SR =  ((ch9En ) ? ((ch9Ds ) ? 0 : 1):0);
	ch10SR =  ((ch10En) ? ((ch10Ds) ? 0 : 1):0);
	ch11SR =  ((ch11En) ? ((ch11Ds) ? 0 : 1):0);
	ch12SR =  ((ch12En) ? ((ch12Ds) ? 0 : 1):0);
	ch13SR =  ((ch13En) ? ((ch13Ds) ? 0 : 1):0);
	ch14SR =  ((ch14En) ? ((ch14Ds) ? 0 : 1):0);
	ch15SR =  ((ch15En) ? ((ch15Ds) ? 0 : 1):0);

	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),0 ) | (  ch0SR << 0  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),1 ) | (  ch1SR << 1  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),2 ) | (  ch2SR << 2  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),3 ) | (  ch3SR << 3  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),4 ) | (  ch4SR << 4  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),5 ) | (  ch5SR << 5  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),6 ) | (  ch6SR << 6  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),7 ) | (  ch7SR << 7  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),8 ) | (  ch8SR << 8  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),9 ) | (  ch9SR << 9  )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),10) | ( ch10SR << 10 )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),11) | ( ch11SR << 11 )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),12) | ( ch12SR << 12 )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),13) | ( ch13SR << 13 )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),14) | ( ch14SR << 14 )));
	SET_ADC_REGISTERS(AdcConfReg,0x40038018,((GET_ADC_REGISTERS(AdcConfReg,0x40038018),15) | ( ch15SR << 15 )));


	bypReg0 = in0.read();
	bypReg1 = in1.read();
	bypReg2 = in2.read();
	bypReg3 = in3.read();
	bypReg4 = in4.read();
	bypReg5 = in5.read();
	bypReg6 = in6.read();
	bypReg7 = in7.read();
	bypReg8 = in8.read();
	bypReg9 = in9.read();
	bypReg10 = in10.read();
	bypReg11 = in11.read();
	bypReg12 = in12.read();
	bypReg13 = in13.read();
	bypReg14 = in14.read();
	bypReg15 = in15.read();

	/* SWRST - Write to 0 to all output channels if there is a software reset */
	if ((LibGetBitu32(GET_ADC_REGISTERS(AdcConfReg,0x40038000),0)==true)){/* No software reset : Read all ports */
		bypReg0=0;
		bypReg1=0;
		bypReg2=0;
		bypReg3=0;
		bypReg4=0;
		bypReg5=0;
		bypReg6=0;
		bypReg7=0;
		bypReg8=0;
		bypReg9=0;
		bypReg10=0;
		bypReg11=0;
		bypReg12=0;
		bypReg13=0;
		bypReg14=0;
		bypReg15=0;
	}
	/* START - Do not write the converted output until START is HIGH*/
	if(LibGetBitu32(GET_ADC_REGISTERS(AdcConfReg,0x40038000),1)){
		out0.write (( ch0SR )? (bypReg0 ) : 0 );
		out1.write (( ch1SR )? (bypReg1 ) : 0 );
		out2.write (( ch2SR )? (bypReg2 ) : 0 );
		out3.write (( ch3SR )? (bypReg3 ) : 0 );
		out4.write (( ch4SR )? (bypReg4 ) : 0 );
		out5.write (( ch5SR )? (bypReg5 ) : 0 );
		out6.write (( ch6SR )? (bypReg6 ) : 0 );
		out7.write (( ch7SR )? (bypReg7 ) : 0 );
		out8.write (( ch8SR )? (bypReg8 ) : 0 );
		out9.write (( ch9SR )? (bypReg9 ) : 0 );
		out10.write((ch10SR )? (bypReg10) : 0 );
		out11.write((ch11SR )? (bypReg11) : 0 );
		out12.write((ch12SR )? (bypReg12) : 0 );
		out13.write((ch13SR )? (bypReg13) : 0 );
		out14.write((ch14SR )? (bypReg14) : 0 );
		out14.write((ch15SR )? (bypReg15) : 0 );
	}
}
