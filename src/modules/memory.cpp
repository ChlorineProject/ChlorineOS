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

void Chlorine::MemoryManagement::Initialize()
{
		/*
		 *	Here we just create a blank variable, and get it's
		 *	position in memory, so that it can be used to know what
		 *	the starting point in memory is for programs.
		 *  This function should be ran last, before any programs are
		 *	are used.
		 */
		int d68be914fb9ab947;
		Chlorine::MemoryManagement::StartOfMemory = (int)&d68be914fb9ab947;
		Chlorine::MemoryManagement::MemoryPosition = (int)&d68be914fb9ab947;
}

int Chlorine::MemoryManagement::AllocateMemory(int Amount)
{
		int d68be914fb9ab946 = Chlorine::MemoryManagement::MemoryPosition;
		Chlorine::MemoryManagement::MemoryPosition += Amount;
		return d68be914fb9ab946;
}