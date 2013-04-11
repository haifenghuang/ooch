/*
 * Executable_oo.h
 *
 *  Created on: Mar 30, 2013
 *      Author: brett
 */

#ifndef EXECUTABLE_OO_H_
#define EXECUTABLE_OO_H_

typedef struct ClassExecutable
{

#include "inc/Executable_oocv.h"

} ClassExecutable;

typedef struct InstanceExecutable
{

#include "inc/Executable_ooiv.h"

} InstanceExecutable;

typedef struct InstanceMethodsExecutable
{

#include "inc/Executable_ooimp.h"

} InstanceMethodsExecutable;

typedef struct ClassMethodsExecutable
{

#include "inc/Executable_oocmp.h"

} ClassMethodsExecutable;

void ClassExecutable_Initialize();

void ClassExecutable_OverrideClassRun( int (*ptr_to_run_func)(ClassExecutable *) );

#endif /* EXECUTABLE_OO_H_ */
