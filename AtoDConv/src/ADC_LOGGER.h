/*
 * ADC_LOGGER.h
 *
 *  Created on: Sep 26, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class AdcFileLogger{
private:
	ofstream logFile;
	ostringstream filebuff;
	char* fileName;
public:
	AdcFileLogger(char* filName,string strHdr);
	~AdcFileLogger(void);
	void log(string s);
};


