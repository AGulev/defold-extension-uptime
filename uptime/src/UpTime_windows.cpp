#if defined(DM_PLATFORM_WINDOWS)
#include "UpTime.h"

uint32_t UpTime_get()
{
  return (uint32_t)(timeGetTime() * 0.001f);
}
#endif
