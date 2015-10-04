/*
 * ADC_USER_CONFIG.h
 *
 *  Created on: Sep 19, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef ADC_USER_CONFIG_H_
#define ADC_USER_CONFIG_H_

#include <systemc-ams>
#include "GLOBAL_SHARED_CONSTS.h"
#include "ADC_REGISTERS_MAP.h"


class adcUsrConf{
	private:
	public :
	uint32 ADCClock;
	ADC_CONTROL_REGISTERS_t* adcReg;
	adcUsrConf(ADC_CONTROL_REGISTERS_t*);
};
#endif
