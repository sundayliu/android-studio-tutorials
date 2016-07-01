#include <jni.h>
#include <string>


static const char*  test()
{
    static std::string test1 = "hello jasper";
    return test1.c_str();
}