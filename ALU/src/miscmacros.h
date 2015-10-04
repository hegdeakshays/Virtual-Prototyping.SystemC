/*
 * miscmacros.h
 *
 *  Created on: Jun 27, 2015
 *      Author: kannoth
 */

#ifndef MISCMACROS_H_
#define MISCMACROS_H_

#define MAX_COUNT 8191
#define MIN_COUNT 0
#define DOT

typedef unsigned int uint32;
typedef signed int sint32;

#define AND 0
#define OR  1
#define XOR 2
#define ROR 3
#define ROL 4
#define ADD 5
#define MUL 6
#define DIV 7
#define DATAWIDTH  16
#define NEG SC_LOGIC_1
#define POS SC_LOGIC_0

#define INTR_OVERFLOW(cnt , p_cnt, p_UC , p_RESET)  (((cnt == MIN_COUNT) & ( p_cnt == MAX_COUNT )) & \
											        ( p_UC == SC_LOGIC_1 ) & ( p_RESET == SC_LOGIC_0))
#define INTR_UNDERFLOW(cnt , p_cnt, p_UC)           (((cnt == MAX_COUNT) & ( p_cnt == MIN_COUNT )))

#define WAIT_FOR_A_CLOCK_MS(clk) {\
									clk = (SC_LOGIC_0);	\
									wait(1,SC_MS);		\
									clk = (SC_LOGIC_1);	\
									wait(1,SC_MS);		\
								 }

#define WAIT_FOR_A_CLOCK_NS(clk) {\
									clk = (SC_LOGIC_0);	\
									wait(1,SC_NS);		\
									clk = (SC_LOGIC_1);	\
									wait(1,SC_NS);		\
								 }




#endif /* MISCMACROS_H_ */
