/*
 * IOLinux_oo.c
 *
 *  Created on: Jun 15, 2013
 *      Author: brett
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../types_oo.h"

#include "../../IOLinux_oo.h"

static ClassIOLinux            *io_linux_class_vars;
static InstanceMethodsIOLinux  *io_linux_instance_method_ptrs;
       ClassMethodsIOLinux     *io_linux_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

void ClassIOLinux_AssignInstanceMethodPointers(InstanceMethodsIOLinux *instance_method_pointers)
{
    //instance_method_pointers->Quack      = &IOLinuxInstance_Quack;
    //instance_method_pointers->Sing       = &IOLinuxInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &IOLinuxInstance_Initialize;
}

#define MAX_FMT_SIZE 100000

int IOLinuxClass_Stdout( char * fmt, ... )
{
	va_list argptr;
	va_start(argptr,fmt);
	vfprintf(stdout, fmt, argptr );
	va_end(argptr);
	return 0;
}

int IOLinuxClass_Stderr( char * fmt, ... )
{
	va_list argptr;
	va_start(argptr,fmt);
	vfprintf(stderr, fmt, argptr );
	va_end(argptr);
	return 0;
}

void ClassIOLinux_AssignClassMethodPointers(ClassMethodsIOLinux *class_method_pointers)
{
    io_linux_class_method_ptrs->Stdout = IOLinuxClass_Stdout;
    io_linux_class_method_ptrs->Stderr = IOLinuxClass_Stderr;
}

void ClassIOLinux_Initialize()
{
    if ( class_is_uninitialized )
    {

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing IOLinux Class\n");
#endif
        io_linux_class_vars  = calloc( sizeof(InstanceIOLinux), 1 );

        io_linux_instance_method_ptrs          = calloc( sizeof(InstanceMethodsIOLinux), 1 );
        //ClassBird_AssignInstanceMethodPointers( io_linux_instance_method_ptrs);
        ClassIOLinux_AssignInstanceMethodPointers( io_linux_instance_method_ptrs);

        io_linux_class_method_ptrs             = calloc( sizeof(ClassMethodsIOLinux), 1 );
        ClassIOLinux_AssignClassMethodPointers(io_linux_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

//void ClassIOLinux_OverrideClassRun( int (*ptr_to_run_func)(ClassIOLinux *) )
//{
//    io_linux_class_method_ptrs->Run = ptr_to_run_func;
//}

//void initialize_main();  //Force overriding of this initialization function
