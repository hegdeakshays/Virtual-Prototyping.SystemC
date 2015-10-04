/*
 * ADC_USER_CONFIG.cpp
 *
 *  Created on: Sep 19, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#include "ADC_USER_CONFIG.h"
#include <bitset>
using namespace std;

adcUsrConf::adcUsrConf(ADC_CONTROL_REGISTERS_t* adcReg){
	/* Set the ADC clock frequency based on MCK and PRESCAL : Read the ADC_MR.PRESCAL			*/
	this->ADCClock = (MCK / (( (((GET_ADC_REGISTERS(adcReg,0x40038004)) & 0x0000FF00 )>> 8) + 1)*2));
}
