#pragma once

/*
 *	Regarding pointers, we will just not use the C/C++ pointers, and
 *	and instead use basic int variables that store the address of
 *	other variables.
 */

/*
 *	I thought about making a struct about this but I'm just going to make a class
 *	instead.
 *
 *	typedef struct {
 *		unsigned int StartPosition;
 *		unsigned int EndPosition;
 *	} memory_flag_t;
 */

namespace Chlorine
{
	namespace MemoryManagement
	{
		unsigned int UsedMemoryAddress;
		void *CopyMemory(void *dst, const void *src, unsigned int cnt);
		void *AllocateMemory(unsigned int Amount);
		class MemoryFlag
		{
		public:
			unsigned int StartPosition;
			unsigned int EndPosition;
		};
	}
}