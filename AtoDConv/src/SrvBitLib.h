/*
################################################################################
File   : SrvBitLib.h

Description:

Bit manipulation library
################################################################################
*/
#ifndef _SRV_BIT_LIB_H
#define _SRV_BIT_LIB_H

#include "commontypedefs.h"

#define _TRUE (0x01)
#define _FALSE (0x00)
#define SET (_TRUE)
#define CLR (_FALSE)

inline void LibSetClrBitu8(uint8* msgRef,boolean msgVal,uint8 msgPos);
inline void LibSetClrBitu16(uint16* msgRef,boolean msgVal,uint8 msgPos);
inline void LibSetClrBitu32(uint32* msgRef,boolean msgVal,uint8 msgPos);
inline boolean LibGetBitu8(uint8 msgRef,uint8 msgPos);
inline boolean LibGetBitu16(uint16 msgRef,uint8 msgPos);
inline boolean LibGetBitu32(uint32 msgRef,uint8 msgPos);
/*////////////////////////////////////////////////////////////////////////////*/
/* LibSetBitu8                                                                */
/*                                                                            */
/* Sets the bit of a signed 8 bit integer message                             */
/*////////////////////////////////////////////////////////////////////////////*/
inline void LibSetClrBitu8(uint8* msgRef,boolean msgVal,uint8 msgPos)
{
	*msgRef = ((msgVal == SET)?
	/*Setting the nth bit*/     (*msgRef|(((uint8)MINUINT8 + 1)<< msgPos)):
    /*Clearing the nth bit*/    (*msgRef&(~(((uint8)MINUINT32 + 1)<< msgPos))));
}
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/* LibSetBitu16                                                               */
/*                                                                            */
/* Sets the bit of a unsigned 16 bit integer message                          */
/*////////////////////////////////////////////////////////////////////////////*/

inline void LibSetClrBitu16(uint16* msgRef,boolean msgVal,uint8 msgPos)
{
	*msgRef = ((msgVal == SET)?
	/*Setting the nth bit*/     (*msgRef|(((uint16)MINUINT16 + 1)<< msgPos)):
    /*Clearing the nth bit*/    (*msgRef&(~(((uint32)MINUINT16 + 1)<< msgPos))));
}
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/* LibSetBitu32                                                               */
/*                                                                            */
/* Sets the bit of a unsigned 32 bit integer message                          */
/*////////////////////////////////////////////////////////////////////////////*/

inline void LibSetClrBitu32(uint32* msgRef,boolean msgVal,uint8 msgPos)
{
	*msgRef = ((msgVal == SET)?
    /*Setting the nth bit*/     (*msgRef|(((uint32)MINUINT32 + 1)<< msgPos)):
    /*Clearing the nth bit*/    (*msgRef&(~(((uint32)MINUINT32 + 1)<< msgPos))));
}
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/* LibGetBitu8                                                                */
/*                                                                            */
/* Gets the bit of a unsigned 8 bit integer message                           */
/*////////////////////////////////////////////////////////////////////////////*/

inline boolean LibGetBitu8(uint8 msgRef,uint8 msgPos)
{
	return((((msgRef>>msgPos) & 0x01) != _FALSE ) ?  _TRUE : _FALSE );
}
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/* LibGetBitu16                                                               */
/*                                                                            */
/* Gets the bit of a unsigned 8 bit integer message                           */
/*////////////////////////////////////////////////////////////////////////////*/

inline boolean LibGetBitu16(uint16 msgRef,uint8 msgPos)
{
	return((((msgRef>>msgPos) & 0x01) != _FALSE ) ?  _TRUE : _FALSE );
}
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/* LibGetBitu32                                                               */
/*                                                                            */
/* Gets the bit of a unsigned 8 bit integer message                           */
/*////////////////////////////////////////////////////////////////////////////*/

inline boolean LibGetBitu32(uint32 msgRef,uint8 msgPos)
{
   return((msgRef>>msgPos)& 0x01);
}
/*////////////////////////////////////////////////////////////////////////////*/

#endif
