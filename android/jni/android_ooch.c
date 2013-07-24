#include <jni.h>
#include <string.h>


#include <sys/types.h>
#include <dirent.h>


#include <android/log.h>

#include "../../lib/ooch/ooc.h"
#include "../../config/project_settings.h"

#include "../../lib/ooch/types_oo.h"

#include "android_ooch.h"

#include "sqlite/sqlite3.h"

#define DEBUG_TAG "NDK_AndroidNDK1SampleActivity"

#define ANDROID_VERSION "4"

JavaVM *cached_jvm;

static ClassAndroidOOCH            *android_ooch_class_vars;
static InstanceMethodsAndroidOOCH  *android_ooch_instance_method_ptrs;
static ClassMethodsAndroidOOCH     *android_ooch_class_method_ptrs;

static BOOL class_is_uninitialized = TRUE;

void logit(const char * logtext)
{
	__android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]", logtext);
}

void Java_com_example_androidndk1sample_AndroidNDK1SampleActivity_helloLog(JNIEnv * env, jobject this, jstring logThis)
{
	jboolean isCopy;
	const char * szLogThis = (*env)->GetStringUTFChars(env, logThis, &isCopy);
	__android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]", szLogThis);
	(*env)->ReleaseStringUTFChars(env, logThis, szLogThis);

	jclass clazz = (*env)->FindClass(env,"com/example/androidndk1sample/AndroidNDK1SampleActivity");
    if (clazz == 0) {
        logit("FindClass error");
        return;
    }

    jmethodID javamethod = (*env)->GetMethodID(env, clazz, "test_call", "()V");
    if (javamethod == 0) {
        logit("GetMethodID error");
        return;
    }

    jmethodID java_print_string = (*env)->GetMethodID(env, clazz, "print_string", "(Ljava/lang/String;)V");
    if (javamethod == 0) {
        logit("GetMethodID error");
        return;
    }

    char tblz[6] = "BLIZZ";

    jstring test_str;
    test_str = (*env)->NewStringUTF(env, tblz);

    //(*env)->CallVoidMethod(env, this, javamethod);

    (*env)->CallVoidMethod(env, this, java_print_string, test_str);


    DIR *dp;
    struct dirent *ep;
    dp = opendir ("/sdcard");

    if (dp != NULL)
    {
      while (ep = readdir (dp))
      {
  	    test_str = (*env)->NewStringUTF(env, ep->d_name);
  	    (*env)->CallVoidMethod(env, this, java_print_string, test_str);
      }

      (void) closedir (dp);
    }


	logit("Extra Log Message");
}

void ClassAndroidOOCH_AssignInstanceMethodPointers(InstanceMethodsAndroidOOCH *instance_method_pointers)
{
    //instance_method_pointers->Quack      = &HelloWorldInstance_Quack;
    //instance_method_pointers->Sing       = &HelloWorldInstance_Sing;  // overriding parent class Bird->Sing method
    //instance_method_pointers->Initialize = &HelloWorldInstance_Initialize;
}

int AndroidOOCHClass_Run()
{
    fprintf(stdout, "    HELLO WORLD CALLED IN RUN()!!!\n");

	logit("@#$%&^%&(&)&$$$$$$$$$$$$$    HELLO WORLD CALLED IN RUN()!!!\n" );

    return EXIT_SUCCESS;
}

void ClassAndroidOOCH_AssignClassMethodPointers(ClassMethodsAndroidOOCH *class_method_pointers)
{
    ClassExecutable_OverrideClassRun( &AndroidOOCHClass_Run );
}

void ClassAndroidOOCH_Initialize()
{
    if ( class_is_uninitialized )
    {
        ClassExecutable_Initialize();

        android_ooch_class_vars                    = calloc( sizeof(InstanceAndroidOOCH), 1 );

        android_ooch_instance_method_ptrs          = calloc( sizeof(InstanceMethodsAndroidOOCH), 1 );
        //ClassBird_AssignInstanceMethodPointers( hello_world_instance_method_ptrs);
        ClassAndroidOOCH_AssignInstanceMethodPointers( android_ooch_instance_method_ptrs);

        android_ooch_class_method_ptrs             = calloc( sizeof(ClassMethodsAndroidOOCH), 1 );

        ClassAndroidOOCH_AssignClassMethodPointers(android_ooch_class_method_ptrs);
        class_is_uninitialized = FALSE;
    }

}

void initialize_main()
{
    ClassAndroidOOCH_Initialize();
}

jint JNI_OnLoad(JavaVM *jvm, void *reserved) {
	JNIEnv *env;

	cached_jvm = jvm; /* cache the JavaVM pointer */

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_2)) {
			return JNI_ERR; /* JNI version not supported */
	}

	logit("OBJECT OrIeNtEd!!!!  The JNI_OnLoad is being called ");

	alt_main();

	return JNI_VERSION_1_2;
}
