////////////////////////////////////////////////////////////////////////////////
//
// file: hello.h
// brief:
// date: 2016.07.01
// author:sundayliu
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __HELLO_HELLO_H__
#define __HELLO_HELLO_H__

#include <jni.h>
namespace hello
{

jstring getStringFromJNI(JNIEnv* env, jclass clz);

}

#endif