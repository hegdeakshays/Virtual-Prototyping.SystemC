/*
 * ADC_REGISTERS_MAP.h
 *  Created on: Sep 14, 2015
 *      Author: kannoth
 *      E-mail: s_kannoth14@informatik.uni-kl.de
 */

#ifndef ADC_REGISTERS_MAP_H_
#define ADC_REGISTERS_MAP_H_

#include <iostream>
#include "GLOBAL_SHARED_CONSTS.h"

#define ADC_BASE_ADDRESS 0x40038000
#define ADC_CHANNEL_NUMS 15


	#define ADC_CR 		0
	#define ADC_MR 		1
	#define ADC_CHER 	2
	#define ADC_CHDR	3
	#define ADC_CHSR	4
	#define ADC_CGR		5
	#define ADC_COR		6
	#define ADC_CDR0	7
	#define ADC_CDR1	8
	#define ADC_CDR2	9
	#define ADC_CDR3	10
	#define ADC_CDR4	11
	#define ADC_CDR5	12
	#define ADC_CDR6	13
	#define ADC_CDR7	14
	#define ADC_CDR8	15
	#define ADC_CDR9	16
	#define ADC_CDR10	17
	#define ADC_CDR11	18
	#define ADC_CDR12	19
	#define ADC_CDR13	20
	#define ADC_CDR14	21
	#define ADC_CDR15	22
	#define ADC_WPMR	23

	#define BASE_ADDR_ADC_CR  	0x00
	#define BASE_ADDR_ADC_MR	0x04
	#define BASE_ADDR_ADC_CHER	0x10
	#define BASE_ADDR_ADC_CHDR	0x14
	#define BASE_ADDR_ADC_CHSR	0x18
	#define BASE_ADDR_ADC_CGR	0x48
	#define BASE_ADDR_ADC_COR	0x4C
	#define BASE_ADDR_ADC_CDR0	0x50
	#define BASE_ADDR_ADC_CDR1	0x54
	#define BASE_ADDR_ADC_CDR2	0x58
	#define BASE_ADDR_ADC_CDR3	0x5C
	#define BASE_ADDR_ADC_CDR4	0x60
	#define BASE_ADDR_ADC_CDR5	0x64
	#define BASE_ADDR_ADC_CDR6	0x68
	#define BASE_ADDR_ADC_CDR7	0x6C
	#define BASE_ADDR_ADC_CDR8	0x70
	#define BASE_ADDR_ADC_CDR9	0x74
	#define BASE_ADDR_ADC_CDR10	0x78
	#define BASE_ADDR_ADC_CDR11	0x7C
	#define BASE_ADDR_ADC_CDR12	0x80
	#define BASE_ADDR_ADC_CDR13	0x84
	#define BASE_ADDR_ADC_CDR14	0x88
	#define BASE_ADDR_ADC_CDR15	0x8C
	#define BASE_ADDR_ADC_WPMR	0xE4

/* Startup register handles */
#define SUT0	(0)
#define SUT8	(8)
#define SUT16	(16)
#define SUT24	(24)
#define SUT64	(64)
#define SUT80	(80)
#define SUT96	(96)
#define SUT112	(112)
#define SUT512	(512)
#define SUT576	(576)
#define SUT640	(640)
#define SUT704	(704)
#define SUT768	(768)
#define SUT832	(832)
#define SUT896	(896)
#define SUT960	(960)

#define AST3 (3)
#define AST5 (5)
#define AST9 (9)
#define AST17 (17)


class ADC_CONTROL_REGISTERS{
	private:
			uint32 	ADC_CR_w;
			uint32 	ADC_MR_rw;
			uint32	ADC_CHER_w;
			uint32	ADC_CHDR_w;
			uint32	ADC_CHSR_r;
			uint32	ADC_CGR_rw;
			uint32	ADC_COR_rw;
			sint32 	ADC_CDR_0_rw;
			sint32 	ADC_CDR_1_rw;
			sint32 	ADC_CDR_2_rw;
			sint32 	ADC_CDR_3_rw;
			sint32 	ADC_CDR_4_rw;
			sint32 	ADC_CDR_5_rw;
			sint32 	ADC_CDR_6_rw;
			sint32 	ADC_CDR_7_rw;
			sint32 	ADC_CDR_8_rw;
			sint32 	ADC_CDR_9_rw;
			sint32 	ADC_CDR_10_rw;
			sint32 	ADC_CDR_11_rw;
			sint32 	ADC_CDR_12_rw;
			sint32 	ADC_CDR_13_rw;
			sint32 	ADC_CDR_14_rw;
			sint32 	ADC_CDR_15_rw;
			uint32  ADC_WPMR_rw;
	public:
			void WRITE_ADC_CONTROL_REGISTERS	(uint32 offsetAddr8 ,uint32 value);
			uint32 READ_ADC_CONTROL_REGISTERS	(uint32 offsetAddr8);
			friend uint32 GET_ADC_REGISTERS		(ADC_CONTROL_REGISTERS* adcReg, uint32 actualAddress32u);
			friend void SET_ADC_REGISTERS		(ADC_CONTROL_REGISTERS* adcReg,uint32 actualAddress32u, uint32 value32u);
			uint32 getADCBaseAddress			(uint32 actualAddress);
			ADC_CONTROL_REGISTERS();
	};

	typedef ADC_CONTROL_REGISTERS ADC_CONTROL_REGISTERS_t;

	uint32 getADCBaseAddress(uint32 actualAddress);
	uint32 GET_ADC_REGISTERS(ADC_CONTROL_REGISTERS_t* adcReg, uint32 actualAddress32u);
	void SET_ADC_REGISTERS(ADC_CONTROL_REGISTERS_t* adcReg,uint32 actualAddress32u, uint32 value32u);

#endif /* ADC_REGISTERS_MAP_H_ */
