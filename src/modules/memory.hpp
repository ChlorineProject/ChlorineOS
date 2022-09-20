#pragma once

/*
 *	Regarding pointers, we will just not use the C/C++ pointers, and
 *	and instead use basic int variables that store the address of
 *	other variables.
 */

namespace Chlorine
{
	namespace MemoryManagement
	{
		int MemoryPosition;
		int StartOfMemory;
		int AllocateMemory(int Amount);
		void Initialize();
		void* CopyMemory(void* dst, const void* src, unsigned int cnt);
	}
}