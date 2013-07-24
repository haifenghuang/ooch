/*
 * Object_oo.c
 *
 *  Created on: July 24th, 2013
 *      Author: Brett J. Nelson
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../../config/project_settings.h"
#include "../../types_oo.h"
#include "../../Object_oo.h"

static        ClassObject            *object_class_vars;
static        InstanceMethodsObject  *object_instance_method_ptrs;
//static ClassMethodsObject     *object_class_method_ptrs;
static struct ClassMethodsObject      object_class_method_ptrs = { &ClassObject_New };

InstanceObject* ClassObject_New()  // new initializes object
{
	return Object();
}

InstanceObject* Object()  // new initializes object
{
	return NULL;
}

//static BOOL class_is_uninitialized = TRUE;

//void ClassObject_AssignInstanceMethodPointers(InstanceMethodsObject *instance_method_pointers)
//{
    //instance_method_pointers->Quack      = &ObjectInstance_Quack;
    //instance_method_pointers->Sing       = &ObjectInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &ObjectInstance_Initialize;
//}

//void ClassObject_AssignClassMethodPointers(ClassMethodsObject *class_method_ptrs)
//{
//    class_method_ptrs->Run      = NULL;  // force overriding
//}

/*
void ClassObject_Initialize()
{
    if ( class_is_uninitialized )
    {

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing Object Class\n");
#endif
        object_class_vars  = calloc( sizeof(InstanceObject), 1 );

        object_instance_method_ptrs          = calloc( sizeof(InstanceMethodsObject), 1 );
        //ClassObject_AssignInstanceMethodPointers( object_instance_method_ptrs);

        object_class_method_ptrs             = calloc( sizeof(ClassMethodsObject), 1 );
        ClassObject_AssignClassMethodPointers(object_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}
*/

//void ClassObject_OverrideClassRun( int (*ptr_to_run_func)(ClassObject *) )
//{
//    object_class_method_ptrs->Run = ptr_to_run_func;
//}

/*
void initialize_main();  //Force overriding of this initialization function

#ifndef ANDROID_VERSION
int main()
{
    initialize_main();
    if ( NULL == object_class_method_ptrs->Run )
    {
        fprintf( stdout, "The descendent of Object must override the class Run method.");
        return EXIT_FAILURE;
    }
    else
    {
        return object_class_method_ptrs->Run(object_class_vars);
    }
}
#endif

int alt_main()
{
    initialize_main();
    if ( NULL == object_class_method_ptrs->Run )
    {
        fprintf( stdout, "The descendent of Object must override the class Run method.");
        return EXIT_FAILURE;
    }
    else
    {
        return object_class_method_ptrs->Run(object_class_vars);
    }
}
*/
