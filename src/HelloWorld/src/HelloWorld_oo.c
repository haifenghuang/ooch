#include "../../../lib/ooch/ooc.h"

#include "../../../config/project_settings.h"

#ifdef THIS_CLASS_NAME
#undef THIS_CLASS_NAME
#endif

#define THIS_CLASS_NAME "HelloWorld"

#ifdef M
#undef M
#endif


#define Y_TUPLE_SIZE(...) Y_TUPLE_SIZE_II((Y_TUPLE_SIZE_PREFIX_ ## __VA_ARGS__ ## _Y_TUPLE_SIZE_POSTFIX,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0))
#define Y_TUPLE_SIZE_II(__args) Y_TUPLE_SIZE_I __args

#define Y_TUPLE_SIZE_PREFIX__Y_TUPLE_SIZE_POSTFIX ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,0

#define Y_TUPLE_SIZE_I(__p0,__p1,__p2,__p3,__p4,__p5,__p6,__p7,__p8,__p9,__p10,__p11,__p12,__p13,__p14,__p15,__p16,__p17,__p18,__p19,__p20,__p21,__p22,__p23,__p24,__p25,__p26,__p27,__p28,__p29,__p30,__p31,__n,...) __n

#define PICK5(a1,a2,a3,a4,a5,...) a5
#define ZARGX(n,a,...) PICK5(__VA_ARGS__,a,a,a,n,)
//#define M(obj,method,...) ZARGX(obj.method(),obj.method(__VA_ARGS__),__VA_ARGS__)


#ifdef  METHOD_DISPATCH_CHECK
#define M(obj,method,...) ( 0 == hello_world_instance_method_ptrs->method ? fprintf( stderr, "missing method pointer:%s for class:%s\n", #method, THIS_CLASS_NAME ) : (/*fprintf(stdout,"hello_world M called\n"),*/ (*hello_world_instance_method_ptrs->method)(obj,__VA_ARGS__) ) )
#else
#define MN(obj,method,...)     (fprintf(stdout,"hello_world M called\n"), (*hello_world_instance_method_ptrs->method)(obj))
#define MA(obj,method,...) (fprintf(stdout,"hello_world M called\n"), (*hello_world_instance_method_ptrs->method)(obj,__VA_ARGS__))
#define M(obj,...)  ZARGX( MN(obj,__VA_ARGS__) , MA(obj,__VA_ARGS__) , __VA_ARGS__ )
#endif

#include <stdlib.h>
#include <stdio.h>

#include "../../../lib/ooch/types_oo.h"

#include "../HelloWorld_oo.h"

static ClassHelloWorld            *hello_world_class_vars;
static InstanceMethodsHelloWorld  *hello_world_instance_method_ptrs;
static ClassMethodsHelloWorld     *hello_world_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

InstanceHelloWorld *HelloWorld()
{
    InstanceHelloWorld* newObj = calloc( sizeof(InstanceHelloWorld), 1 );
    //InstanceHelloWorld* newObj = NULL;
    //M(newObj,Initialize);  // initialize the newly allocated object
    return newObj;
}

InstanceHelloWorld *HelloWorldInstance_Initialize(InstanceHelloWorld *self)
{
    if ( NULL == self )
    {
        fprintf( stderr, "UNABLE TO INITIALIZE NULL OBJECT");
        exit(EXIT_FAILURE);
    }

    return self;
}

void ClassHelloWorld_AssignInstanceMethodPointers(InstanceMethodsHelloWorld *instance_method_pointers)
{
    //instance_method_pointers->Quack      = &HelloWorldInstance_Quack;
    //instance_method_pointers->Sing       = &HelloWorldInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &HelloWorldInstance_Initialize;
}

int HelloWorldClass_Run()
{
    fprintf(stdout, " HELLO WORLD CALLED IN RUN()!!!\n");
    return EXIT_SUCCESS;
}

void ClassHelloWorld_AssignClassMethodPointers(ClassMethodsHelloWorld *class_method_pointers)
{
    ClassExecutable_OverrideClassRun( &HelloWorldClass_Run );
}

void ClassHelloWorld_Initialize()
{
    if ( class_is_uninitialized )
    {
        ClassExecutable_Initialize();

#ifdef VERBOSE_DEBUG
        fprintf( stdout, "Initializing HelloWorld Class\n");
#endif
        hello_world_class_vars  = calloc( sizeof(InstanceHelloWorld), 1 );

        hello_world_instance_method_ptrs          = calloc( sizeof(InstanceMethodsHelloWorld), 1 );
        //ClassBird_AssignInstanceMethodPointers( hello_world_instance_method_ptrs);
        ClassHelloWorld_AssignInstanceMethodPointers( hello_world_instance_method_ptrs);

        hello_world_class_method_ptrs             = calloc( sizeof(ClassMethodsHelloWorld), 1 );
        ClassHelloWorld_AssignClassMethodPointers(hello_world_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

void initialize_main()
{
    ClassHelloWorld_Initialize();
}

#undef M
