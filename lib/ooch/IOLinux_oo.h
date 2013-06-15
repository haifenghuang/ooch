/*
 * IOLinux_oo.h
 *
 *  Created on: Jun 15, 2013
 *      Author: brett
 */

#ifndef IOLINUX_OO_H_
#define IOLINUX_OO_H_

typedef struct ClassIOLinux
{

#include "inc/IOLinux_oocv.h"

} ClassIOLinux;

typedef struct InstanceIOLinux
{

#include "inc/IOLinux_ooiv.h"

} InstanceIOLinux;

typedef struct InstanceMethodsIOLinux
{

#include "inc/IOLinux_ooimp.h"

} InstanceMethodsIOLinux;

typedef struct ClassMethodsIOLinux
{

#include "inc/IOLinux_oocmp.h"

} ClassMethodsIOLinux;

extern ClassMethodsIOLinux     *io_linux_class_method_ptrs;

void ClassIOLinux_Initialize();

void ClassIOLinux_OverrideClassRun( int (*ptr_to_run_func)(ClassIOLinux *) );

#endif /* IOLINUX_OO_H_ */
