/*
 * target.h
 *
 *  Created on: Sep 14, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef TLM_SLAVE_TARGET_H_
#define TLM_SLAVE_TARGET_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc"

using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "TLM_COMMON_HDR.h"
#include "GLOBAL_SHARED_CONSTS.h"
#include "ADC_GLB_CLKCONF.h"

uint16 getSUTPeriod(uint8 index);
uint16 getASTPeriod(uint8 index);
//uint16 getChannelGain(ADC_CONTROL_REGISTERS_t* adcReg,uint32 index);


struct Memory: sc_module{
	/* DE ports for TDF ports from ADC */
	sc_in<sc_bv<ADC_BV_LEN> > prtCh0DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh1DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh2DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh3DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh4DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh5DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh6DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh7DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh8DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh9DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh10DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh11DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh12DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh13DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh14DE;
	sc_in<sc_bv<ADC_BV_LEN> > prtCh15DE;
	tlm_utils::simple_target_socket<Memory> socket;
	ADC_CONTROL_REGISTERS_t* adcReg;

	uint16 SUTASTPeriod ;
	uint8 SUTReg;
	bool SUTflg;
	glbClkTick* glbCktk;
	enum { SIZE = TLM_MEMORY_SIZE};

	SC_CTOR(Memory): socket("socket"){
		socket.register_b_transport(this, &Memory::b_transport);

		for(int i=0; i< SIZE; i++){
			mem[i] = 0;/* Initlialize the memory with 0 */
			SUTflg = false;
		}
	}

	virtual void b_transport(tlm::tlm_generic_payload& transaction, sc_time& delay){
		if (!(SUTflg)){
			glbCktk->clkDly = (getSUTPeriod((((GET_ADC_REGISTERS(adcReg,0x40038004)) >> 16) & 0x0000000F ))) +
					       (getASTPeriod((((GET_ADC_REGISTERS(adcReg,0x40038004)) >> 20) & 0x00000003 )));
			SUTflg = true;
		}

		glbCktk->IsClkElapsed(glbCktk);
		mem[0]  =(glbCktk->clkDlyElapsed == true)? 1 : 0; // SUT period elapsed flag to slave;
		mem[1] 	=(glbCktk->clkDlyElapsed == true)?  prtCh0DE.read().to_int64(): 0;
		mem[2] 	=(glbCktk->clkDlyElapsed == true)?  prtCh1DE.read().to_int64():0;
		mem[3] 	=(glbCktk->clkDlyElapsed == true)?  prtCh2DE.read().to_int64():0;
		mem[4]	=(glbCktk->clkDlyElapsed == true)?  prtCh3DE.read().to_int64():0;// for channel 3
		mem[5] 	=(glbCktk->clkDlyElapsed == true)?  prtCh4DE.read().to_int64():0;
		mem[6] 	=(glbCktk->clkDlyElapsed == true)?  prtCh5DE.read().to_int64():0;// for channel 5
		mem[7] 	=(glbCktk->clkDlyElapsed == true)?  prtCh6DE.read().to_int64():0;
		mem[8] 	=(glbCktk->clkDlyElapsed == true)?  prtCh7DE.read().to_int64():0;// for channel 7
		mem[9] 	=(glbCktk->clkDlyElapsed == true)?  prtCh8DE.read().to_int64():0;
		mem[10] =(glbCktk->clkDlyElapsed == true)?  prtCh9DE.read().to_int64():0;
		mem[11] =(glbCktk->clkDlyElapsed == true)?  prtCh10DE.read().to_int64():0;
		mem[12] =(glbCktk->clkDlyElapsed == true)?  prtCh11DE.read().to_int64():0;
		mem[13] =(glbCktk->clkDlyElapsed == true)?  prtCh12DE.read().to_int64():0;
		mem[14] =(glbCktk->clkDlyElapsed == true)?  prtCh13DE.read().to_int64():0;
		mem[15] =(glbCktk->clkDlyElapsed == true)?  prtCh14DE.read().to_int64():0;
		mem[16] =(glbCktk->clkDlyElapsed == true)?  prtCh15DE.read().to_int64():0;

		tlm::tlm_command cmd	= transaction.get_command();
		sc_dt::uint64  adr		= transaction.get_address();
		unsigned char* ptr		= transaction.get_data_ptr();
		unsigned int len		= transaction.get_data_length();
		unsigned char* byt		= transaction.get_byte_enable_ptr();
		unsigned int wid		= transaction.get_streaming_width();

		/* Update ADC Data Registers : Unused registers are updated with TLM_FORBIDDEN_PATTERN for simplicity */
		SET_ADC_REGISTERS(adcReg,0x40038050,(sint32)mem[1]);
		SET_ADC_REGISTERS(adcReg,0x40038054,(sint32)mem[2]);
		SET_ADC_REGISTERS(adcReg,0x40038058,(sint32)mem[3]);
		SET_ADC_REGISTERS(adcReg,0x4003805C,(sint32)mem[4]); //CDR3
		SET_ADC_REGISTERS(adcReg,0x40038060,(sint32)mem[5]);
		SET_ADC_REGISTERS(adcReg,0x40038064,(sint32)mem[6]); //CDR5
		SET_ADC_REGISTERS(adcReg,0x40038068,(sint32)mem[7]);
		SET_ADC_REGISTERS(adcReg,0x4003806C,(sint32)mem[8]); //CDR7
		SET_ADC_REGISTERS(adcReg,0x40038070,(sint32)mem[9]);
		SET_ADC_REGISTERS(adcReg,0x40038074,(sint32)mem[10]);
		SET_ADC_REGISTERS(adcReg,0x40038078,(sint32)mem[11]);
		SET_ADC_REGISTERS(adcReg,0x4003807C,(sint32)mem[12]);
		SET_ADC_REGISTERS(adcReg,0x40038080,(sint32)mem[13]);
		SET_ADC_REGISTERS(adcReg,0x40038084,(sint32)mem[14]);
		SET_ADC_REGISTERS(adcReg,0x40038088,(sint32)mem[15]);
		SET_ADC_REGISTERS(adcReg,0x4003808C,(sint32)mem[16]);

		if( ( adr > sc_dt::uint64( SIZE ))  || byt != 0 || len > 8 || wid < len ){
			SC_REPORT_ERROR("TLM-2", "Target does not support given generic payload transaction");
		}

		if ( cmd == tlm::TLM_READ_COMMAND) {
				memcpy(ptr, &mem[adr], len);

		}
		else if ( cmd == tlm::TLM_WRITE_COMMAND){
			memcpy(&mem[adr], ptr, len);
		}
		transaction.set_response_status(tlm::TLM_OK_RESPONSE);
	}
	int64_t mem[TLM_MEMORY_SIZE+1];
};

uint16 getSUTPeriod(uint8 index){

	uint16 sutPrd = 0;
	switch(index){
				case(0):{
					sutPrd = SUT0;
					break;
				}
				case(1):{
					sutPrd = SUT8;
					break;
				}
				case(2):{
					sutPrd = SUT16;
					break;
				}
				case(3):{
					sutPrd = SUT24;
					break;
				}
				case(4):{
					sutPrd = SUT64;
					break;
				}
				case(5):{
					sutPrd = SUT80;
					break;
				}
				case(6):{
					sutPrd = SUT96;
					break;
				}
				case(7):{
					sutPrd = SUT112;
					break;
				}
				case(8):{
					sutPrd = SUT512;
					break;
				}
				case(9):{
					sutPrd = SUT576;
					break;
				}
				case(10):{
					sutPrd = SUT640;
					break;
				}
				case(11):{
					sutPrd = SUT704;
					break;
				}
				case(12):{
					sutPrd = SUT768;
					break;
				}
				case(13):{
					sutPrd = SUT832;
					break;
				}
				case(14):{
					sutPrd = SUT896;
					break;
				}
				case(15):{
					sutPrd = SUT960;
					break;
				}
				default:{break;}
	}
	return (sutPrd);
}
uint16 getASTPeriod(uint8 index){

	uint16 astPrd = 0;
	switch(index){
				case(0):{
					astPrd = AST3;
					break;
				}
				case(1):{
					astPrd = AST5;
					break;
				}
				case(2):{
					astPrd = AST9;
					break;
				}
				case(3):{
					astPrd = AST17;
					break;
				}
				default:{break;}
	}
	return (astPrd);
}



#endif /* TLM_SLAVE_TARGET_H_ */
