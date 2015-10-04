/*
 * GLOBAL_SHARED_CONSTS.h
 *
 *  Created on: Sep 18, 2015
 *      Author: kannoth
 *		E-mail: s_kannoth14@informatik.uni-kl.de
 *---------------------------------------------------------------------------------
 * Adjust all the physical parameters and units of ADC in this file
 *---------------------------------------------------------------------------------
 */


#ifndef GLOBAL_SHARED_CONSTS_H_
#define GLOBAL_SHARED_CONSTS_H_


#define DISABLE_ADC 0

/*User typedefs*/
#include "commontypedefs.h"


const double T_SAMPLE_GLB =  10.0;
//////////////////////////////////////////////////////////////////////////////////////////////
/* Source part                                                                              */
const double SIN_TS_NS = 10.0;	/* Adjust the sine function port sampling here 		(ns)	*/
const double COS_TS_NS = 10.0;	/* Adjust the cosine function port sampling here 	(ns)	*/
const double SAW_TS_NS = 10.0;	/* Adjust the saw function port sampling here 		(Hz)	*/
const double SIN_FREQ = 10000;	/* Adjust the sine function frequency here 			(Hz)	*/
const double COS_FREQ = 30000;	/* Adjust the cosine function frequency here 		(Hz)	*/
const double SAW_FREQ = 19500;	/* Adjust the saw function frequency here 			(Hz)	*/
const double SIN_AMPL = 2.0;	/* Adjust the sine function amplitude here 			(V)		*/
const double COS_AMPL = 2.5;	/* Adjust the cosine function amplitude here 		(V)		*/
const double SAW_AMPL = 2.5;	/* Adjust the saw function amplitude here	 		(V)		*/
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
/* ADC Part                                                                                 */
const double ADCVREF  = 3.3;	/* Adjust the ADC reference voltage here			(V)		*/
/*..........................................................................................*/
/*The ADC conversion bit vector width is coded as macro. This will be written to ADC_MR.4   */
/*This cannot be configured at runtime, since the Vector width is passed as template        */
/* argument for ADC TDF modules.So the Project has to re-build once the ADC_BV_LEN is       */
/* changed                                                                                  */
#define ADC_BV_LEN		 10		/* Adjust the ADC Bit vector length here	( no.of bits)	*/

#define MCK 2e7					/*20 Mhz as Host Microcontroller clock	which drives the ADC*/
/*                             The ADC clock is determined by the  PRESCAL reg configuration*/
//////////////////////////////////////////////////////////////////////////////////////////////
/* ADC Configuration																		*/
/* The below register configurations will be set by the ADC_Configutation method in start   */
/* the system																				*/
//////////////////////////////////////////////////////////////////////////////////////////////
#define 	ADC_CR_VAL_U32		(0x00000000)
#define 	ADC_MR_VAL_U32		(0x00000000)
#define		ADC_CHER_VAL_U32	(0x00000000)
#define		ADC_CHDR_VAL_U32	(0x00000000)
#define		ADC_CHSR_VAL_U32	(0x00000000)
#define		ADC_CGR_rVAL_U32	(0x00000000)
#define		ADC_COR_VAL_U32		(0x00000000)
#define 	ADC_CDR_0_VAL_U32	(0x00000000)
#define 	ADC_CDR_1_VAL_U32	(0x00000000)
#define 	ADC_CDR_2_VAL_U32	(0x00000000)
#define 	ADC_CDR_3_VAL_U32	(0x00000000)
#define 	ADC_CDR_4_VAL_U32	(0x00000000)
#define 	ADC_CDR_5_VAL_U32	(0x00000000)
#define 	ADC_CDR_6_VAL_U32	(0x00000000)
#define 	ADC_CDR_7_VAL_U32	(0x00000000)
#define 	ADC_CDR_8_VAL_U32	(0x00000000)
#define 	ADC_CDR_9_VAL_U32	(0x00000000)
#define 	ADC_CDR_10_VAL_U32	(0x00000000)
#define 	ADC_CDR_11_VAL_U32	(0x00000000)
#define 	ADC_CDR_12_VAL_U32	(0x00000000)
#define 	ADC_CDR_13_VAL_U32	(0x00000000)
#define 	ADC_CDR_14_VAL_U32	(0x00000000)
#define 	ADC_CDR_15_VAL_U32	(0x00000000)
#define  	ADC_WPMR_VAL_U32	(0x00000000)

#endif /* GLOBAL_SHARED_CONSTS_H_ */
