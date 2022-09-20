#include "./memory.hpp"

/*
 *	This is an extremely simple system for allocating memory
 *	for ChlorineOS. There is an issue though; when the memory
 *	is no longer needed, it can't be reused (well it can be,
 *	but there could be memory issues).
 *
 *	We need to implement a way to have unclaimed memory to be
 *	able to be claimed again.
 */

void *Chlorine::MemoryManagement::CopyMemory(void *dst, const void *src, unsigned int cnt)
{
	char *pszDest = (char *)dst;
	const char *pszSource = (const char *)src;
	if ((pszDest != 0) && (pszSource != 0))
	{
		while (cnt)
		{
			*(pszDest++) = *(pszSource++);
			--cnt;
		}
	}
	return dst;
}