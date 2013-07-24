/*
 * Object_oo.h
 *
 *  Created on: July 24th, 2013
 *      Author: Brett J. Nelson
 */

#ifndef OBJECT_OO_H_
#define OBJECT_OO_H_

typedef struct ClassObject
{

#include "inc/Object_oocv.h"

} ClassObject;

typedef struct InstanceObject
{

#include "inc/Object_ooiv.h"

} InstanceObject;

typedef struct InstanceMethodsObject
{

#include "inc/Object_ooimp.h"

} InstanceMethodsObject;

typedef struct ClassMethodsObject
{

#include "inc/Object_oocmp.h"

} ClassMethodsObject;

//void ClassObject_Initialize();
//void ClassObject_OverrideClassRun( int (*ptr_to_run_func)(ClassObject *) );

InstanceObject* ClassObject_New();  // new initializes object
InstanceObject* Object();           // allocates only

#endif /* OBJECT_OO_H_ */
