#include <jni.h>
#include <string>
#include <android/log.h>
#include <math.h>

#define LOG_TAG  "C_TAG"
// define
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

//LOGD("hello.length=%d",helloLen);

//java->Native
extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaBooleanToNative(JNIEnv *env, jclass clazz, jboolean value) {
    LOGD("Java Boolean: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaByteToNative(JNIEnv *env, jclass clazz, jbyte value) {
    LOGD("Java Byte: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaCharToNative(JNIEnv *env, jclass clazz, jchar value) {
    LOGD("Java Char: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaShortToNative(JNIEnv *env, jclass clazz, jshort value) {
    LOGD("Java Short: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaIntToNative(JNIEnv *env, jclass clazz, jint value) {
    LOGD("Java Int: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaLongToNative(JNIEnv *env, jclass clazz, jlong value) {
    LOGD("Java Long: %lld", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaFloatToNative(JNIEnv *env, jclass clazz, jfloat value) {
    LOGD("Java Float: %f", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaDoubleToNative(JNIEnv *env, jclass clazz, jdouble value) {
    LOGD("Java Double: %lf", value);
}


// natice -> java
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaBooleanFromNative(JNIEnv *env, jclass clazz) {
    return JNI_TRUE;
}

extern "C"
JNIEXPORT jbyte JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaByteFromNative(JNIEnv *env, jclass clazz) {
    return 123;
}

extern "C"
JNIEXPORT jchar JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaCharFromNative(JNIEnv *env, jclass clazz) {
    return 'A';
}

extern "C"
JNIEXPORT jshort JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaShortFromNative(JNIEnv *env, jclass clazz) {
    return 999;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaIntFromNative(JNIEnv *env, jclass clazz) {
    return 999999;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaLongFromNative(JNIEnv *env, jclass clazz) {
    return 999999999;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaFloatFromNative(JNIEnv *env, jclass clazz) {
    return 999999.8;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaDoubleFromNative(JNIEnv *env, jclass clazz) {
    return 999999999.8;
}



//  互相传递数据
extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_charConcatTest(JNIEnv *env, jclass clazz, jchar a, jchar b,
                                                 jchar c) {
    char charArray[4];
    charArray[0] = a;
    charArray[1] = b;
    charArray[2] = c;
    charArray[3] = '\0';
//  JNIEnv 表示 Java 调用 native 语言的环境，是一个封装了几乎全部 JNI 方法的指针。   [浅谈 JNIEnv 和 JavaVM_阿飞的博客-CSDN博客](https://blog.csdn.net/afei__/article/details/80986203)

/*// 创建字符串
    通过调用 NewStringUTF 函数，会构建一个新的 java.lang.String 字符串对象。
     这个新创建的字符串会自动转换成 Java 支持的 Unicode 编码。
     如果 JVM 不能为构造 java.lang.String 分配足够的内存，NewStringUTF 会抛出一个 OutOfMemoryError 异常，
     并返回 NULL。在这个例子中我们不必检查它的返回值，如果NewStringUTF 创建 java.lang.String 失败，
     OutOfMemoryError 这个异常会被在 Sample.main 方法中抛出。如果 NewStringUTF 创建 java.lang.String
     成功，则返回一个 JNI 引用，这个引用指向新创建的java.lang.String 对象。

     [NewStringUTF - Google 搜索](https://www.google.com/search?q=NewStringUTF&newwindow=1&safe=strict&rlz=1C5CHFA_enUS928US928&sxsrf=ALeKk00MkgYOuRGB0KyOg80kdVtG5jP03w:1612866966581&source=lnt&tbs=lr:lang_1zh-CN&lr=lang_zh-CN&sa=X&ved=2ahUKEwiDjPPUzdzuAhVoB50JHYtXBuwQpwV6BAgOECE&biw=1420&bih=693)[NewStringUTF - Google 搜索](https://www.google.com/search?q=NewStringUTF&newwindow=1&safe=strict&rlz=1C5CHFA_enUS928US928&sxsrf=ALeKk00MkgYOuRGB0KyOg80kdVtG5jP03w:1612866966581&source=lnt&tbs=lr:lang_1zh-CN&lr=lang_zh-CN&sa=X&ved=2ahUKEwiDjPPUzdzuAhVoB50JHYtXBuwQpwV6BAgOECE&biw=1420&bih=693)
     [JNI 字符串处理 - JNI/NDK 开发指南 - 极客学院Wiki](https://wiki.jikexueyuan.com/project/jni-ndk-developer-guide/string.html)
     [Android Native 开发之 NewString 与 NewStringUtf 解析_Shawn_Dut的专栏-CSDN博客](https://blog.csdn.net/self_study/article/details/78886686)
     [jni中的NewStringUTF这个函数调用后需要释放内存吗？_宇宙精英-CSDN博客_newstringutf 释放](https://blog.csdn.net/qhs1573/article/details/87704431)
     */

   return env->NewStringUTF(charArray);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_sumText(JNIEnv *env, jclass clazz, jint i, jint j) {
    return i + j;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_twoExpTest(JNIEnv *env, jclass clazz, jint exp) {
    return pow(2, exp);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_calcMoneyTest(JNIEnv *env, jclass clazz, jdouble v, jdouble v1,
                                                jdouble v2) {
    double totalMoney = v + v1 + v2;
    char *resultStr = new char();
    sprintf(resultStr, "总计：%f", totalMoney);
    return env->NewStringUTF(resultStr);
}