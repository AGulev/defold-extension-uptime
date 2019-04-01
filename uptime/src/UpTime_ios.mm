#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX)
#include <AVFoundation/AVFoundation.h>

uint32_t UpTime_get()
{
  return [[NSProcessInfo processInfo] systemUptime];
}

#endif
