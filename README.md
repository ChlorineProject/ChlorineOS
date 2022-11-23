<p align="center">
  <img src="./.assets/logo.png" />
</p>

# ChlorineOS

## What is ChlorineOS?

ChlorineOS is a small operating system that I'm writing for learning purposes, but I also would like to make this operating system as an alternative to Linux-based operating systems and BSD-based operating systems, while having support for some of their programs.

ChlorineOS is no longer written in C++, as C++ has given me alot of problems when developing ChlorineOS, so for now the kernel will be written in C.

## Progress checklist

- [x] Does the OS boot up?
- [x] Does the OS have the kernel atleast working?
- [x] Does the OS have an I/O port driver?
- [x] Does the OS have serial driver?
- [X] Does the OS have a driver for writing to the screen?
- [X] Does the OS have a driver for drawing to the screen?
- [ ] Does the OS have paging implemented?
- [ ] Does the OS have a multitasking system?
- [X] Does the OS have a good & efficient memory allocator?
- [X] Does the OS have GDT?
- [X] Does the OS have IDT?

## Any dependencies?

Yup! There are some dependencies that you will need that will help you with building and testing ChlorineOS. A list of them can be found here:

```
grub2
xorriso
binutils
g++
gcc
qemu
mtools
```

I believe that these can be installed with debian's/ubuntu's package manager, aswell as Arch linux's package manager. I may soon make a new page exactly describing how to install these packages, but for now I'm busy implementing more functions.

## Troubleshooting

Here you can read how to fix any issues with ChlorineOS.

### Help! I'm getting this error!
```
/usr/include/c++/11/cstdbool:37:12: fatal error: bits/c++config.h: No such file or directory
   37 | #  include <bits/c++config.h>
```

Just install the packages:
```
gcc-multilib g++-multilib
```

### Help! Make says `Nothing to be done for 'kernel'/'image'`!
This probably shows up because you haven't set what architecture the operating system will compile for. Currently, the only architecture supported is x86, so you'll have to send the following command:
```bash
export ARCHITECTURE=i386
```
Please note that you can compile for the target architecture if your current architecture is the same, although if you want to compile for x86 on a different architecture, you will need a cross compiler that compiles for x86.

### ~~Help! I can't see anything when testing ChlorineOS!~~
~~Remember to switch ChlorineOS's display to `serial0`, since VGA text-mode terminals are still a work-in-progress (on QEMU).~~

### Help! I get the error Fatal error: can't create ./object/*.o: No such file or directory
Make sure to create the directories `object` and `output`:
```bash
mkdir object output
```
