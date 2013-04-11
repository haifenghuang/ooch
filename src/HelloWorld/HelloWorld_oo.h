/*
 * HelloWorld_oo.h
 *
 *  Created on: Mar 30, 2013
 *      Author: brett
 */

#ifndef HELLOWORLD_OO_H_
#define HELLOWORLD_OO_H_

#include "../../lib/ooch/Executable_oo.h"  // Parent class

typedef struct ClassHelloWorld
{

#include "src/HelloWorld_oocv.h"

} ClassHelloWorld;

typedef struct InstanceHelloWorld
{

#include "src/HelloWorld_ooiv.h"

} InstanceHelloWorld;

typedef struct InstanceMethodsHelloWorld
{

#include "src/HelloWorld_ooimp.h"

} InstanceMethodsHelloWorld;

typedef struct ClassMethodsHelloWorld
{

#include "../../lib/ooch/inc/Executable_oocmp.h"
#include "src/HelloWorld_oocmp.h"

} ClassMethodsHelloWorld;

void ClassHelloWorld_Initialize();


#endif /* HELLOWORLD_OO_H_ */
