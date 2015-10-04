/*
 * ADC_CH_GAIN_OFFSET.h
 *
 *  Created on: Sep 28, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef ADC_CH_GAIN_OFFSET_H_
#define ADC_CH_GAIN_OFFSET_H_

#include "ADC_CH_GAIN_OFFSET.h"
#include "ADC_REGISTERS_MAP.h"
#include "commontypedefs.h"
using namespace std;

typedef struct GainOffset{

	double gain;
	double offset;
};

typedef GainOffset go_t;

class AdcGainOffSet{

public:
	double adcGain[ADC_CHANNEL_NUMS];
	double adcOffset[ADC_CHANNEL_NUMS];
public:
	AdcGainOffSet(ADC_CONTROL_REGISTERS_t* adcReg,double vrefin);
	~AdcGainOffSet(void);
	friend go_t loadChannelGainOffset(ADC_CONTROL_REGISTERS_t* adcReg,uint32 index,double vrefin);
};

typedef  AdcGainOffSet AdcGainOffSet_t;
go_t loadChannelGainOffset(ADC_CONTROL_REGISTERS_t* adcReg,uint32 index,double vrefin);
#endif /* ADC_CH_GAIN_OFFSET_H_ */
