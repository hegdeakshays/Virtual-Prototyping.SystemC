/*
 * ADC_REGISTERS_MAP_H.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */


#include <iostream>
#include "ADC_REGISTERS_MAP.h"


//////////////////////////////////////////////////////////////////////////////////////////
// Set the init values of registers here												//
//////////////////////////////////////////////////////////////////////////////////////////
ADC_CONTROL_REGISTERS::ADC_CONTROL_REGISTERS(void){
		this->ADC_CR_w 		=0;
		this->ADC_MR_rw		=0;
		this->ADC_CHER_w	=0;
		this->ADC_CHDR_w	=0;
		this->ADC_CHSR_r	=0;
		this->ADC_CGR_rw	=0;
		this->ADC_COR_rw	=0;
		this->ADC_CDR_0_rw	=0;
		this->ADC_CDR_1_rw	=0;
		this->ADC_CDR_2_rw	=0;
		this->ADC_CDR_3_rw	=0;
		this->ADC_CDR_4_rw	=0;
		this->ADC_CDR_5_rw	=0;
		this->ADC_CDR_6_rw	=0;
		this->ADC_CDR_7_rw	=0;
		this->ADC_CDR_8_rw	=0;
		this->ADC_CDR_9_rw	=0;
		this->ADC_CDR_10_rw	=0;
		this->ADC_CDR_11_rw	=0;
		this->ADC_CDR_12_rw	=0;
		this->ADC_CDR_13_rw	=0;
		this->ADC_CDR_14_rw	=0;
		this->ADC_CDR_15_rw	=0;
		this->ADC_WPMR_rw	=0;
		std::cout<<"INFO : "<<"Initialized the ADC Registers with default configuration"<<std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void ADC_CONTROL_REGISTERS::WRITE_ADC_CONTROL_REGISTERS(uint32 offsetAddr8, uint32 value){

		switch(offsetAddr8){
			case(BASE_ADDR_ADC_CR):{
				ADC_CR_w = value;
				break;
			}
			case(BASE_ADDR_ADC_MR):{
				ADC_MR_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CHER):{
				ADC_CHER_w = value;
				break;
			}
			case(BASE_ADDR_ADC_CHDR):{
				ADC_CHDR_w = value;
				break;
			}
			case(BASE_ADDR_ADC_CHSR):{
				ADC_CHSR_r = value;
				break;
			}
			case(BASE_ADDR_ADC_CGR):{
				ADC_CGR_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_COR):{
				ADC_COR_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR0):{
				ADC_CDR_0_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR1):{
				ADC_CDR_1_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR2):{
				ADC_CDR_2_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR3):{
				ADC_CDR_3_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR4):{
				ADC_CDR_4_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR5):{
				ADC_CDR_5_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR6):{
				ADC_CDR_6_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR7):{
				ADC_CDR_7_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR8):{
				ADC_CDR_8_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR9):{
				ADC_CDR_9_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR10):{
				ADC_CDR_10_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR11):{
				ADC_CDR_11_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR12):{
				ADC_CDR_12_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR13):{
				ADC_CDR_13_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR14):{
				ADC_CDR_14_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_CDR15):{
				ADC_CDR_15_rw = value;
				break;
			}
			case(BASE_ADDR_ADC_WPMR):{
				ADC_WPMR_rw = value;
				break;
			}
			default:break;
		}
	}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
uint32 ADC_CONTROL_REGISTERS::READ_ADC_CONTROL_REGISTERS(uint32 offsetAddr8){
		uint32 retVal;
		switch(offsetAddr8){
			case(BASE_ADDR_ADC_CR):{
				retVal=(ADC_CR_w);
				break;
			}
			case(BASE_ADDR_ADC_MR):{
				retVal=(ADC_MR_rw);
				break;
			}
			case(BASE_ADDR_ADC_CHER):{
				retVal=(ADC_CHER_w);
				break;
			}
			case(BASE_ADDR_ADC_CHDR):{
				retVal=(ADC_CHDR_w);
				break;
			}
			case(BASE_ADDR_ADC_CHSR):{
				retVal=(ADC_CHSR_r);
				break;
			}
			case(BASE_ADDR_ADC_CGR):{
				retVal=(ADC_CGR_rw);
				break;
			}
			case(BASE_ADDR_ADC_COR):{
				retVal=(ADC_COR_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR0):{
				retVal=(ADC_CDR_0_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR1):{
				retVal=(ADC_CDR_1_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR2):{
				retVal=(ADC_CDR_2_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR3):{
				retVal=(ADC_CDR_3_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR4):{
				retVal=(ADC_CDR_4_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR5):{
				retVal=(ADC_CDR_5_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR6):{
				retVal=(ADC_CDR_6_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR7):{
				retVal=(ADC_CDR_7_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR8):{
				retVal=(ADC_CDR_8_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR9):{
				retVal=(ADC_CDR_9_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR10):{
				retVal=(ADC_CDR_10_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR11):{
				retVal=(ADC_CDR_11_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR12):{
				retVal=(ADC_CDR_12_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR13):{
				retVal=(ADC_CDR_13_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR14):{
				retVal=(ADC_CDR_14_rw);
				break;
			}
			case(BASE_ADDR_ADC_CDR15):{
				retVal=(ADC_CDR_15_rw);
				break;
			}
			case(BASE_ADDR_ADC_WPMR):{
				retVal=(ADC_WPMR_rw);
				break;
			}
			default:break;
		}
		return(retVal);
	}

//Get ADC_REGISTERs
uint32 GET_ADC_REGISTERS(ADC_CONTROL_REGISTERS_t* adcReg, uint32 actualAddress32u){
	return (adcReg->READ_ADC_CONTROL_REGISTERS(getADCBaseAddress(actualAddress32u)));
}

// Set ADC Registers
void SET_ADC_REGISTERS(ADC_CONTROL_REGISTERS_t* adcReg, uint32 actualAddress32u, uint32 value32u){
	adcReg->WRITE_ADC_CONTROL_REGISTERS(getADCBaseAddress(actualAddress32u),value32u);
}


uint32 getADCBaseAddress(uint32 actualAddress){
	return (uint32) (actualAddress - ADC_BASE_ADDRESS);
}
