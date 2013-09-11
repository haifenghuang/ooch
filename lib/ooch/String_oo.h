/*
 * String_oo.h
 *
 *  Created on: Sep 11, 2013
 *      Author: brett
 */

#ifndef STRING_OO_H_
#define STRING_OO_H_

typedef struct ClassString
{

#include "inc/Object_oocv.h"
#include "inc/String_oocv.h"

} ClassString;

typedef struct InstanceString
{

#include "inc/Object_ooiv.h"
#include "inc/String_ooiv.h"

} InstanceString;

typedef struct InstanceMethodsString
{

#include "inc/Object_ooimp.h"
#include "inc/String_ooimp.h"

} InstanceMethodsString;

typedef struct ClassMethodsString
{

#include "inc/Object_oocmp.h"
#include "inc/String_oocmp.h"

} ClassMethodsString;

void ClassString_Initialize();

#endif /* STRING_OO_H_ */
