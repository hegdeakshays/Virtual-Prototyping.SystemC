/*
 * ADC_LOGGER.cpp
 *
 *  Created on: Sep 26, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */
#include "ADC_LOGGER.h"


AdcFileLogger::AdcFileLogger(char* filName,string strHdr){
	this->fileName = filName;
	this->logFile.open(filName);
	logFile << strHdr<<endl;
}

AdcFileLogger::~AdcFileLogger(void){
	logFile << filebuff.str();
	this->logFile.close();
	cout<<"INFO : "<<fileName<< " generated "<<endl;

}
void AdcFileLogger::log(string s){
	filebuff << s;
}
