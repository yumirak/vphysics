#include <memory.h>

inline void* hk_Memory::memcpy(void* dest, const void* src, int size)
{
#ifdef _WIN32
	return ::memcpy(dest,src,size);
#else
	return memcpy(dest,src,size);
#endif
}

inline void* hk_Memory::memset(void* dest, hk_uchar val, hk_int32 size)
{
#ifdef _WIN32
	return ::memset(dest, val, size);
#else
	return memset(dest, val, size);
#endif
}

