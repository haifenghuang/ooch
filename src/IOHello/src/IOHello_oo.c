#include "../../../lib/ooch/ooc.h"

#include "../../../config/project_settings.h"

#include "../../../lib/ooch/types_oo.h"

#include "../IOHello_oo.h"

static ClassIOHello            *io_hello_class_vars;
static InstanceMethodsIOHello  *io_hello_instance_method_ptrs;
static ClassMethodsIOHello     *io_hello_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

InstanceIOHello *IOHello()
{
    InstanceIOHello* newObj = calloc( sizeof(InstanceIOHello), 1 );
    return newObj;
}

InstanceIOHello *IOHelloInstance_Initialize(InstanceIOHello *self)
{
    if ( NULL == self )
    {
        fprintf( stderr, "UNABLE TO INITIALIZE NULL OBJECT");
        exit(EXIT_FAILURE);
    }

    return self;
}

void ClassIOHello_AssignInstanceMethodPointers(InstanceMethodsIOHello *instance_method_pointers)
{
    //instance_method_pointers->Quack      = &IOHelloInstance_Quack;
    //instance_method_pointers->Sing       = &IOHelloInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &IOHelloInstance_Initialize;
}

int IOHelloClass_Run()
{
	io_linux_class_method_ptrs->Stdout("%s"," HELLO WORLD CALLED IN RUN()!!!\n");
    return EXIT_SUCCESS;
}

void ClassIOHello_AssignClassMethodPointers(ClassMethodsIOHello *class_method_pointers)
{
    ClassExecutable_OverrideClassRun( &IOHelloClass_Run );
}

void ClassIOHello_Initialize()
{
    if ( class_is_uninitialized )
    {
        ClassExecutable_Initialize();
        ClassIOLinux_Initialize();

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing IOHello Class\n");
#endif
        io_hello_class_vars  = calloc( sizeof(InstanceIOHello), 1 );

        io_hello_instance_method_ptrs          = calloc( sizeof(InstanceMethodsIOHello), 1 );
        //ClassBird_AssignInstanceMethodPointers( io_hello_instance_method_ptrs);
        ClassIOHello_AssignInstanceMethodPointers( io_hello_instance_method_ptrs);

        io_hello_class_method_ptrs             = calloc( sizeof(ClassMethodsIOHello), 1 );
        ClassIOHello_AssignClassMethodPointers(io_hello_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

void initialize_main()
{
    ClassIOHello_Initialize();
}

#undef M
