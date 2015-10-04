/*
 * ADC_CH_GAIN_OFFSET.cpp
 *
 *  Created on: Sep 28, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#include "ADC_CH_GAIN_OFFSET.h"

AdcGainOffSet::AdcGainOffSet(ADC_CONTROL_REGISTERS_t* adcReg, double vrefin){
	go_t go;
	//this->VrefIn = ADCVREF;
	for(int i = 0; i <= ADC_CHANNEL_NUMS; i++){
		go = loadChannelGainOffset( adcReg,i,vrefin);
		this->adcGain[i] = go.gain;
		this->adcOffset[i] = go.offset;
	}

}
AdcGainOffSet::~AdcGainOffSet(void){

}

go_t loadChannelGainOffset(ADC_CONTROL_REGISTERS_t* adcReg,uint32 index, double vrefin){
	go_t go;
	uint16 chGain,chGainCoeff;
	bool adcOfst_b;
	uint32 adcCGR = GET_ADC_REGISTERS(adcReg,0x40038048);
	uint32 adcOfst= GET_ADC_REGISTERS(adcReg,0x4003804C);
	/* Calculate gain */
	switch(index){
			case(0):{
				chGain =(uint16)(adcCGR & 0x00000003);
				break;
			}
			case(1):{
				chGain =(uint16)((adcCGR >> 2) & 0x00000003);
				break;
			}
			case(2):{
				chGain =(uint16)((adcCGR >> 4) & 0x00000003);
				break;
			}
			case(3):{
				chGain =(uint16)((adcCGR >> 6) & 0x00000003);
				break;
			}
			case(4):{
				chGain =(uint16)((adcCGR >> 8) & 0x00000003);
				break;
			}
			case(5):{
				chGain =(uint16)((adcCGR >> 10) & 0x00000003);
				break;
			}
			case(6):{
				chGain =(uint16)((adcCGR >> 12) & 0x00000003);
				break;
			}
			case(7):{
				chGain =(uint16)((adcCGR >> 14) & 0x00000003);
				break;
			}
			case(8):{
				chGain =(uint16)((adcCGR >> 16) & 0x00000003);
				break;
			}
			case(9):{
				chGain =(uint16)((adcCGR >> 18) & 0x00000003);
				break;
			}
			case(10):{
				chGain =(uint16)((adcCGR >> 20) & 0x00000003);
				break;
			}
			case(11):{
				chGain =(uint16)((adcCGR >> 22) & 0x00000003);
				break;
			}
			case(12):{
				chGain =(uint16)((adcCGR >> 24) & 0x00000003);;
				break;
			}
			case(13):{
				chGain =(uint16)((adcCGR >> 26) & 0x00000003);;
				break;
			}
			case(14):{
				chGain =(uint16)((adcCGR >> 28) & 0x00000003);
				break;
			}
			case(15):{
				chGain =(uint16)((adcCGR >> 30) & 0x00000003);
				break;
			}
			default:{break;}
		}

		switch (chGain){
		case(0):{
			chGainCoeff = 1;
			break;
		}
		case(1):{
			chGainCoeff = 1;
			break;
		}
		case(2):{
			chGainCoeff = 2;
			break;
		}
		case(3):{
			chGainCoeff = 4;
			break;
		}
		}
		go.gain   =(chGainCoeff);

		/* Calculate offset */
		switch(index){
			case(0):{
				adcOfst_b =(bool)(adcOfst & 0x00000001);
				break;
			}
			case(1):{
				adcOfst_b =(bool)((adcOfst >> 1) & 0x00000001);
				break;
			}
			case(2):{
				adcOfst_b =(bool)((adcOfst >> 2) & 0x00000001);
				break;
			}
			case(3):{
				adcOfst_b =(bool)((adcOfst >> 3) & 0x00000001);
				break;
			}
			case(4):{
				adcOfst_b =(bool)((adcOfst >> 4) & 0x00000001);
				break;
			}
			case(5):{
				adcOfst_b =(bool)((adcOfst >> 5) & 0x00000001);
				break;
			}
			case(6):{
				adcOfst_b =(bool)((adcOfst >> 6) & 0x00000001);
				break;
			}
			case(7):{
				adcOfst_b =(bool)((adcOfst >> 7) & 0x00000001);
				break;
			}
			case(8):{
				adcOfst_b =(bool)((adcOfst >> 8) & 0x00000001);
				break;
			}
			case(9):{
				adcOfst_b =(bool)((adcOfst >> 9) & 0x00000001);
				break;
			}
			case(10):{
				adcOfst_b =(bool)((adcOfst >> 10) & 0x00000001);
				break;
			}
			case(11):{
				adcOfst_b =(bool)((adcOfst >> 11) & 0x00000001);
				break;
			}
			case(12):{
				adcOfst_b =(bool)((adcOfst >> 12) & 0x00000001);;
				break;
			}
			case(13):{
				adcOfst_b =(bool)((adcOfst >> 13) & 0x00000001);;
				break;
			}
			case(14):{
				adcOfst_b =(bool)((adcOfst >> 14) & 0x00000001);
				break;
			}
			case(15):{
				adcOfst_b =(bool)((adcOfst >> 15) & 0x00000001);
				break;
			}
			default:{break;}
		}
		/* (G-1) Vrefin / 2*/
		go.offset = (adcOfst_b) ? ((((go.gain) - 1) * (vrefin))/2) : 0 ;

	return go;
}
