#include "./memory.hpp"

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

void *Chlorine::MemoryManagement::AllocateMemory(unsigned int Amount)
{

}