
/*
 * ADC_GLB_CLKCONF.cpp
 *
 *  Created on: Sep 26, 2015
 *      Author: kannoth
 *      Email : s_kannoth14@informatik.uni-kl.de
 */

#ifndef ADC_GLB_CLKCONF_H_
#define ADC_GLB_CLKCONF_H_

class glbClkTick{
public:
	uint64_t clkTck;
	uint64_t clkDly;
	bool clkDlyElapsed;
	void IsClkElapsed(glbClkTick*){
		if (this->clkTck <= this->clkDly){
			this->clkDlyElapsed = false;
		}else if (this->clkTck > this->clkDly){
			this->clkDlyElapsed = true;
		}else{}
	}
};

#endif


