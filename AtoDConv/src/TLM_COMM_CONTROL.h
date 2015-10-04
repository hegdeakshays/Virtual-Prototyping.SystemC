/*
 * TLM_COMM_CONTROL.h
 *
 *  Created on: Sep 20, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef TLM_COMM_CONTROL_H_
#define TLM_COMM_CONTROL_H_

#include <systemc>
#include "TLM_COMMON_HDR.h"
#include "TLM_MASTER_INITIATER.h"
#include "TLM_SLAVE_TARGET.h"

SC_MODULE(CommControl){
	Initiater* initiater;
	Memory* memory;

	SC_CTOR(CommControl){

		initiater	= new Initiater("initiater");
		memory		= new Memory("memory");
		initiater->socket.bind(memory->socket);
	}
};


#endif /* TLM_COMM_CONTROL_H_ */
