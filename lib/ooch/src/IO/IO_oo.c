/*
 * IO_oo.c
 *
 *  Created on: Jun 16, 2013
 *      Author: brett
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../../../config/project_settings.h"
#include "../../types_oo.h"
#include "../../IO_oo.h"

static ClassIO            *io_class_vars;
static InstanceMethodsIO  *io_instance_method_ptrs;
       ClassMethodsIO     *io_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

//void ClassIO_AssignInstanceMethodPointers(InstanceMethodsIO *instance_method_pointers)
//{
    //instance_method_pointers->Quack      = &IOInstance_Quack;
    //instance_method_pointers->Sing       = &IOInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &IOInstance_Initialize;
//}

void ClassIO_AssignClassMethodPointers(ClassMethodsIO *class_method_ptrs)
{
    class_method_ptrs->Stdout = NULL;
    class_method_ptrs->Stderr = NULL;
}

void ClassIO_Initialize()
{
    if ( class_is_uninitialized )
    {

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing IO Class\n");
#endif
        io_class_vars  = calloc( sizeof(InstanceIO), 1 );

        io_instance_method_ptrs          = calloc( sizeof(InstanceMethodsIO), 1 );
        //ClassIO_AssignInstanceMethodPointers( io_instance_method_ptrs);

        io_class_method_ptrs             = calloc( sizeof(ClassMethodsIO), 1 );
        ClassIO_AssignClassMethodPointers(io_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

void ClassIO_OverrideClassStdout( int (*ptr_to_run_func)(char *fmt, ...) )
{
    io_class_method_ptrs->Stdout = ptr_to_run_func;
}

void ClassIO_OverrideClassStderr( int (*ptr_to_run_func)(char *fmt, ...) )
{
    io_class_method_ptrs->Stderr = ptr_to_run_func;
}

//void initialize_main();  //Force overriding of this initialization function
