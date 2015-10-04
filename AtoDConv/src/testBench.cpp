/*
 * testBench.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: kannoth
 *      Email : s_kannoth14@informatik.uni-kl.de
 */

#include "testBench.h"
#define TEST_1 1 // With Gain =0 and offset =0
#define TEST_2 2 // With Gain =2 and offset = Vref/2


#define TEST_CASE TEST_2

TestBench::TestBench				(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time){

	this->ADC_Configuration(adcReg,time);
	this->ADC_GetStatus(adcReg,time);
	this->ADC_GetData(adcReg,time);
}
void TestBench::ADC_Configuration	(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time){

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<" Executing : ADC_Configuration : Register data of ADC data Registers @ :"<<time<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"INFO : Setting ADC Registers with the below configuration "<<endl
    		<<endl;
    cout<<"ADC_MR.SETTLING\t= 0 (3 ADC Cycles lag )"<<endl;
    cout<<"ADC_MR.STARTUP\t= 2 (8 ADC Cycles lag )"<<endl;
	cout<<"ADC_CR.START\t= 1"<<endl<<"ADC_CR.SWRST\t= 0"<<endl<<
    		"ADC_MR.PRESCAL\t= "<<(uint32)((9 & 0x0000000F))<<endl;
	SET_ADC_REGISTERS(adcReg,0x40038000, 0x00000002);
	/* Setting ADC.MR(19-16) = 3 : Settling time */
	SET_ADC_REGISTERS(adcReg,0x40038004,0x00010000);
	SET_ADC_REGISTERS(adcReg,0x40038004,((GET_ADC_REGISTERS(adcReg,0x40038004)))|((9 & 0x0000000F) << 8));
	cout<<"ADC_CHER.3\t= 1"<<endl<<"ADC_CHER.5\t= 1"<<endl<<"ADC_CHER.7\t= 1"<<endl;
	/*CHER : Enable 3,5 and 7 the channels*/
	SET_ADC_REGISTERS(adcReg,0x40038010,0x000000A8);
	SET_ADC_REGISTERS(adcReg,0x40038014,0x00000000);
#if (TEST_CASE == TEST_1)
	/* Channel gain and offset */
	SET_ADC_REGISTERS(adcReg,0x40038048,0x00000000);
	SET_ADC_REGISTERS(adcReg,0x4003804C,0x00000000);
#endif
#if (TEST_CASE == TEST_2)
	/* Channel gain and offset */
	SET_ADC_REGISTERS(adcReg,0x40038048,0x00008880);
	SET_ADC_REGISTERS(adcReg,0x4003804C,0x000000A8);
#endif

}
void TestBench::ADC_GetData		(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time){

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<" Executing : ADC_GetData : Register data of ADC data Registers @ :"<<time<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

	cout<<"REGISTER . CDR_0  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038050))<<endl;
	cout<<"REGISTER . CDR_1  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038054))<<endl;
	cout<<"REGISTER . CDR_2  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038058))<<endl;
	cout<<"REGISTER . CDR_3  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x4003805C))<<endl;
	cout<<"REGISTER . CDR_4  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038060))<<endl;
	cout<<"REGISTER . CDR_5  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038064))<<endl;
	cout<<"REGISTER . CDR_6  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038068))<<endl;
	cout<<"REGISTER . CDR_7  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x4003806C))<<endl;
	cout<<"REGISTER . CDR_8  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038070))<<endl;
	cout<<"REGISTER . CDR_9  : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038074))<<endl;
	cout<<"REGISTER . CDR_10 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038078))<<endl;
	cout<<"REGISTER . CDR_11 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x4003807C))<<endl;
	cout<<"REGISTER . CDR_12 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038080))<<endl;
	cout<<"REGISTER . CDR_13 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038084))<<endl;
	cout<<"REGISTER . CDR_14 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x40038088))<<endl;
	cout<<"REGISTER . CDR_15 : "<< std::bitset<32> (GET_ADC_REGISTERS(adcReg,0x4003808C))<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void TestBench::ADC_GetStatus		(ADC_CONTROL_REGISTERS_t* adcReg,sc_core::sc_time time){
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<" Executing : ADC_GetStatus : Register data of ADC control Registers @ :"<<time<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

	cout<<"REGISTER . CR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038000))<<endl;
	cout<<"REGISTER . MR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038004))<<endl;
	cout<<"REGISTER . CHER	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038010))<<endl;
	cout<<"REGISTER . CHDR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038014))<<endl;
	cout<<"REGISTER . CHSR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038018))<<endl;
	cout<<"REGISTER . CGR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x40038048))<<endl;
	cout<<"REGISTER . COR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x4003804C))<<endl;
	cout<<"REGISTER . WPMR	 : "<< std::bitset<32>  (GET_ADC_REGISTERS(adcReg,0x400380E4))<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
TestBench::~TestBench(){

}
