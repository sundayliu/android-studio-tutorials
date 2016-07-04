#include "jasper.h"

namespace jasper
{
    jstring getString(JNIEnv* env, jclass clz)
    {
        return env->NewStringUTF("Hello, Jasper!!!");
    }
}