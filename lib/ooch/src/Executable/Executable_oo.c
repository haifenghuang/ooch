/*
 * Executable_oo.c
 *
 *  Created on: Mar 30, 2013
 *      Author: brett
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../types_oo.h"

#include "../../Executable_oo.h"

static ClassExecutable            *executable_class_vars;
static InstanceMethodsExecutable  *executable_instance_method_ptrs;
static ClassMethodsExecutable     *executable_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

void ClassExecutable_AssignInstanceMethodPointers(InstanceMethodsExecutable *instance_method_pointers)
{
    //instance_method_pointers->Quack      = &ExecutableInstance_Quack;
    //instance_method_pointers->Sing       = &ExecutableInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &ExecutableInstance_Initialize;
}

void ClassExecutable_AssignClassMethodPointers(ClassMethodsExecutable *class_method_pointers)
{
    executable_class_method_ptrs->Run      = NULL;  // force overriding
}

void ClassExecutable_Initialize()
{
    if ( class_is_uninitialized )
    {

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing Executable Class\n");
#endif
        executable_class_vars  = calloc( sizeof(InstanceExecutable), 1 );

        executable_instance_method_ptrs          = calloc( sizeof(InstanceMethodsExecutable), 1 );
        //ClassBird_AssignInstanceMethodPointers( executable_instance_method_ptrs);
        ClassExecutable_AssignInstanceMethodPointers( executable_instance_method_ptrs);

        executable_class_method_ptrs             = calloc( sizeof(ClassMethodsExecutable), 1 );
        ClassExecutable_AssignClassMethodPointers(executable_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

void ClassExecutable_OverrideClassRun( int (*ptr_to_run_func)(ClassExecutable *) )
{
    executable_class_method_ptrs->Run = ptr_to_run_func;
}

void initialize_main();  //Force overriding of this initialization function

#ifndef ANDROID_VERSION
int main()
{
    initialize_main();
    if ( NULL == executable_class_method_ptrs->Run )
    {
        fprintf( stdout, "The descendent of Executable must override the class Run method.");
        return EXIT_FAILURE;
    }
    else
    {
        return executable_class_method_ptrs->Run(executable_class_vars);
    }
}
#endif

int alt_main()
{
    initialize_main();
    if ( NULL == executable_class_method_ptrs->Run )
    {
        fprintf( stdout, "The descendent of Executable must override the class Run method.");
        return EXIT_FAILURE;
    }
    else
    {
        return executable_class_method_ptrs->Run(executable_class_vars);
    }
}

