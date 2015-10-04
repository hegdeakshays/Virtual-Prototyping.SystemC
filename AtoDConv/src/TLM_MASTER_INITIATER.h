/*
 * Initiater.h
 *
 *  Created on: Sep 14, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef TLM_MASTER_INITIATER_H_
#define TLM_MASTER_INITIATER_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include "ADC_LOGGER.h"

using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "TLM_COMMON_HDR.h"
#include <stdint.h>
#include "ADC_GLB_CLKCONF.h"

void replaceAll(std::string& str, const std::string& from, const std::string& to);

struct Initiater: sc_module{
	tlm_utils::simple_initiator_socket<Initiater> socket;
	unsigned char PVCmd;
	ADC_CONTROL_REGISTERS_t* adcReg;
	sc_in<bool> clk;
	glbClkTick* glbCktk;
	AdcFileLogger* logg;
	SC_CTOR(Initiater) : socket("socket"){
		SC_METHOD(thread_process);
		sensitive << clk.neg();
		dont_initialize();
	}

	void thread_process(){

		/* Increment the global heart beat */
		glbCktk->clkTck++;
		if (PVCmd == CMD_ADC_CONFIGURATION){
			write_process();

		}
		else if((PVCmd == CMD_ADC_GET_STATUS) || (PVCmd == CMD_ADC_GET_DATA)){
			read_process();
		}
		else{}
	}

	void write_process(){

		tlm::tlm_generic_payload* transaction = new tlm::tlm_generic_payload;
		sc_time delay = sc_time(100, SC_NS);


		for (int i = 0; i < 1/*TLM_MEMORY_SIZE-1*/; i++){
			//tlm::tlm_command cmd= static_cast<tlm::tlm_command>(rand() % 2);
			tlm::tlm_command cmd = static_cast<tlm::tlm_command>(true);

			if (cmd == tlm::TLM_WRITE_COMMAND) data = /*0xFF000000 |*/ ((i));

			transaction->set_command( cmd);
			transaction->set_address(i);
			transaction->set_data_ptr(reinterpret_cast<unsigned char*>(&data));
			transaction->set_data_length(8);
			transaction->set_streaming_width(8);
			transaction->set_byte_enable_ptr(0);
			transaction->set_dmi_allowed(false);
			transaction->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

			socket->b_transport(*transaction, delay);

			if( transaction->is_response_error()){
				SC_REPORT_ERROR("TLM-2", "Response error from b_transport");
			}
		}
	}
	void read_process(){
			tlm::tlm_generic_payload* transaction = new tlm::tlm_generic_payload;
			sc_time delay = sc_time(100, SC_NS);
			bool SUTFlag;
			ostringstream lineBuff;
			string tmpStr;

			for (int i = 0; i < TLM_MEMORY_SIZE; i+= 1){
				tlm::tlm_command cmd = static_cast<tlm::tlm_command>(false);

				if (cmd == tlm::TLM_WRITE_COMMAND) data = /*0xFF000000 |*/ ((i));

				transaction->set_command( cmd);
				transaction->set_address(i);
				transaction->set_data_ptr(reinterpret_cast<unsigned char*>(&data));
				transaction->set_data_length(8);
				transaction->set_streaming_width(8);
				transaction->set_byte_enable_ptr(0);
				transaction->set_dmi_allowed(false);
				transaction->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

				socket->b_transport(*transaction, delay);

				if( transaction->is_response_error()){
					SC_REPORT_ERROR("TLM-2", "Response error from b_transport");
				}
				if (i ==0){
					SUTFlag = data;
				}
				if (i == 4){
					lineBuff << sc_time_stamp();
					lineBuff << "\t\t";
					lineBuff << (sint32)GET_ADC_REGISTERS(adcReg,0x4003805C);
					lineBuff << "\t\t";
					lineBuff << (sint32)GET_ADC_REGISTERS(adcReg,0x40038064);
					lineBuff << "\t\t";
					lineBuff << (sint32)GET_ADC_REGISTERS(adcReg,0x4003806C);
					lineBuff << "\t\t";
					lineBuff << (SUTFlag);
					lineBuff << endl;
					tmpStr = lineBuff.str();
					replaceAll(tmpStr," ns","");
					logg->log(tmpStr);
					lineBuff.clear();
				}

			}
		}
	int64_t data;
};

/* The function to replace a substing in a given string*/
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}


#endif /* TLM_MASTER_INITIATER_H_ */
