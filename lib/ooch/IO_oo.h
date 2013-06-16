/*
 * IO_oo.h
 *
 *  Created on: Jun 16, 2013
 *      Author: brett
 */

#ifndef IO_OO_H_
#define IO_OO_H_

typedef struct ClassIO
{

#include "inc/IO_oocv.h"

} ClassIO;

typedef struct InstanceIO
{

#include "inc/IO_ooiv.h"

} InstanceIO;

typedef struct InstanceMethodsIO
{

#include "inc/IO_ooimp.h"

} InstanceMethodsIO;

typedef struct ClassMethodsIO
{

#include "inc/IO_oocmp.h"

} ClassMethodsIO;

extern ClassMethodsIO     *io_class_method_ptrs;

void ClassIO_Initialize();

void ClassIO_OverrideClassStdout( int (*ptr_to_stdout_func)(char *fmt, ...) );
void ClassIO_OverrideClassStderr( int (*ptr_to_stderr_func)(char *fmt, ...) );

#endif /* IO_OO_H_ */
