#if defined(DM_PLATFORM_ANDROID)
#include <jni.h>
#include <dmsdk/sdk.h>

namespace {
  struct ThreadAttacher {
    JNIEnv *env;
    bool has_attached;
    ThreadAttacher() : env(NULL), has_attached(false) {
      if (dmGraphics::GetNativeAndroidJavaVM()->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        dmGraphics::GetNativeAndroidJavaVM()->AttachCurrentThread(&env, NULL);
        has_attached = true;
      }
    }
    ~ThreadAttacher() {
      if (has_attached) {
        if (env->ExceptionCheck()) {
          env->ExceptionDescribe();
        }
        env->ExceptionClear();
        dmGraphics::GetNativeAndroidJavaVM()->DetachCurrentThread();
      }
    }
  };
}


static jclass GetClass(JNIEnv* env, const char* classname)
{
  jclass activity_class = env->FindClass("android/app/NativeActivity");
  jmethodID get_class_loader = env->GetMethodID(activity_class,"getClassLoader", "()Ljava/lang/ClassLoader;");
  jobject cls = env->CallObjectMethod(dmGraphics::GetNativeAndroidActivity(), get_class_loader);
  jclass class_loader = env->FindClass("java/lang/ClassLoader");
  jmethodID find_class = env->GetMethodID(class_loader, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");

  jstring str_class_name = env->NewStringUTF(classname);
  jclass outcls = (jclass)env->CallObjectMethod(cls, find_class, str_class_name);

  env->DeleteLocalRef(str_class_name);
  env->DeleteLocalRef(activity_class);
  env->DeleteLocalRef(class_loader);
  env->DeleteLocalRef(cls);

  return outcls;
}

uint32_t UpTime_get()
{
  ThreadAttacher attacher;
  JNIEnv *env = attacher.env;
  jclass cls = GetClass(env, "android/os/SystemClock");

  jmethodID method = env->GetStaticMethodID(cls, "elapsedRealtime", "()J");
  jlong upTime = (jlong)env->CallStaticLongMethod(cls, method);

  env->DeleteLocalRef(cls);

  return (uint32_t)(upTime * 0.001f);
}

#endif
