/**************************************************************
 * All rights reserved. No part of this file may be reproduced
 * in any form by print, photo print, microfilm or any other
 * means without written permission by ONBON.\n
 * (C) 2010-2019 Onbon
 *************************************************************/

/*!@file 	Obasic_types.h
 * @brief 	onbon basic types definition
 * @author 	fantx
 * @version	1.0.0
 * @date	2018-12-13
 * @note	none
 * @bug 	none
 * @todo 	none
 */


#ifndef __obasic_types_h__
#define __obasic_types_h__

/*!@name Legacy types
 * Deprecated legacy types.
 * @{
 */

//#include <stdio.h>

typedef unsigned char			Ouint8;		//!< unsigned 8-bit
typedef char			        Oint8;		//!< signed 8-bit 
typedef unsigned short			Ouint16;	//!< unsigned 16-bit 
typedef short			        Oint16;		//!< signed 16-bit 
typedef unsigned int			Ouint32;	//!< unsigned 32-bit
typedef int			            Oint32;		//!< signed 32-bit
typedef unsigned long long      Ouint64;        //!< unsigned 64-bit
typedef long long               Oint64;         //!< singed 64-bit
typedef float		            Ofloat32;	//!< 32-bit floating point
typedef double                  Ofloat64;	//!< 64-bit double precision FP
typedef bool                    Obool;
#ifndef TRUE
#  define TRUE		1				//!< true
#endif

#ifndef FALSE
#  define FALSE		0				//!< false
#endif

/*@}*/

#endif //__obasic_types_h__
