////////////////////////////////////////////////////////////////////////////////
//
// file: main.cpp
// brief: jni onload
// date: 2016.07.01
// author:sundayliu
//
////////////////////////////////////////////////////////////////////////////////
#include "hello.h"

#include <jni.h>


const char* JNI_REGCLASS_NAME = "com/sundayliu/libhello/Native";

static void test(JNIEnv* env, jclass clz)
{
    // DEBUG_LOG("[main]function test is native method");
}

static JNINativeMethod g_native_method[] = {
        {"getStringFromJNI", "()Ljava/lang/String;", (void*)hello::getStringFromJNI}
        //{"test", "()V", (void*)test},
        //{"crashNullPointer", "()V", (void*)NS_TENCENT::NS_BUGREPORT::nativeCrashNullPointer},
        //{"crashNullPointerFromJava", "()V", (void*)NS_TENCENT::NS_BUGREPORT::nativeCrashNullPointerFromJava},
        //{"init", "(Ljava/lang/String;Z)V", (void*)NS_TENCENT::NS_BUGREPORT::installBugReport},
        //{"setKeyValue", "(Ljava/lang/String;Ljava/lang/String;)V", (void*)NS_TENCENT::NS_BUGREPORT::setKeyValue},
        //{"sendCrashStack", "(ILjava/lang/String;Ljava/lang/String;)V", (void*)NS_TENCENT::NS_BUGREPORT::sendCrashStack},
        //{"setEnableLog", "(Z)V", (void*)NS_TENCENT::NS_BUGREPORT::setEnableLog}
};

jint JNI_OnLoad(JavaVM* jvm, void* reserved)
{
    //NS_TENCENT::NS_BUGREPORT::g_jvm = jvm;
    //DEBUG_LOG("[main]JNI_OnLoad enter...");
    jint result = JNI_ERR;

    JNIEnv* env = nullptr;
    if (jvm->GetEnv((void**)&env, JNI_VERSION_1_4) == JNI_OK)
    {
        jclass clz = env->FindClass(JNI_REGCLASS_NAME);
        if (clz != nullptr)
        {
            if (env->RegisterNatives(clz, g_native_method, sizeof(g_native_method)/sizeof(g_native_method[0])) >= 0)
            {
                //DEBUG_LOG("[main]register native method success!");
                result = JNI_VERSION_1_4;
            }
        }
    }

    return result;
}