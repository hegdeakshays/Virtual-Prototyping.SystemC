/*
 * TLM_COMMON_HDR.h
 *
 *  Created on: Sep 20, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef TLM_COMMON_HDR_H_
#define TLM_COMMON_HDR_H_



#include "tlm"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include <math.h>

#define CMD_ADC_CONFIGURATION	(0x00)
#define CMD_ADC_GET_STATUS		(0x01)
#define CMD_ADC_GET_DATA		(0x02)

#define TLM_MEMORY_SIZE (16)
#define TLM_FORBIDDEN_PATTERN (0x0)
#endif /* TLM_COMMON_HDR_H_ */
