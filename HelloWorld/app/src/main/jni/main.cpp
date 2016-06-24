#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

#include <string>

jstring stringFromJNI(JNIEnv* env, jclass* clz)
{
    __android_log_print(ANDROID_LOG_DEBUG, "debug", "Hello, NDKDemo!!!");
    return env->NewStringUTF("Hello, C++ STL!!!");
}

const char* JNIREG_CLASS_NAME = "com/sundayliu/helloworld/MainActivity";
static JNINativeMethod g_native_methonds[] =
        {
                {"test", "()Ljava/lang/String;", (void*)stringFromJNI}
        };


jint JNI_OnLoad(JavaVM* jvm, void* reserved)
{
    jint result = JNI_ERR;
    JNIEnv* env = NULL;
    if (jvm->GetEnv((void**)&env, JNI_VERSION_1_4) == JNI_OK)
    {
        jclass clz = env->FindClass(JNIREG_CLASS_NAME);
        if (clz != NULL)
        {
            if (env->RegisterNatives(clz, g_native_methonds, sizeof(g_native_methonds) / sizeof(g_native_methonds[0])) >= 0)
            {
                result = JNI_VERSION_1_4;
            }
        }
    }
    return result;
}

// test
namespace test
{
    void test_stl()
    {
        std::string hello = "Hello, C++ STL!";
        __android_log_print(ANDROID_LOG_DEBUG, "debug", hello.c_str());
    }
}