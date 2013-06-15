/*
 * IOHello_oo.h
 *
 *  Created on: Jun 15, 2013
 *      Author: brett
 */

#ifndef IOHELLO_OO_H_
#define IOHELLO_OO_H_

#include "../../lib/ooch/Executable_oo.h"  // Parent class

#include "../../lib/ooch/IOLinux_oo.h"     // Provides IO functions

typedef struct ClassIOHello
{

#include "src/IOHello_oocv.h"

} ClassIOHello;

typedef struct InstanceIOHello
{

#include "src/IOHello_ooiv.h"

} InstanceIOHello;

typedef struct InstanceMethodsIOHello
{

#include "src/IOHello_ooimp.h"

} InstanceMethodsIOHello;

typedef struct ClassMethodsIOHello
{

#include "../../lib/ooch/inc/Executable_oocmp.h"
#include "src/IOHello_oocmp.h"

} ClassMethodsIOHello;

void ClassIOHello_Initialize();


#endif /* IOHELLO_OO_H_ */
