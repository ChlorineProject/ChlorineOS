# ChlorineOS

## What is ChlorineOS?

ChlorineOS is a small operating system that I'm writing for learning purposes, but I also would like to make this operating system as an alternative to Linux-based operating systems and BSD-based operating systems, while having support for some of their programs.

Currently, I am trying to implement some basic stuff, like some fundamental drivers, modules, and utilities. While I add these, the operating system will just serve as a CLI that allows you to perform calculations, and test different functions.

## Progress checklist

- [x] Does the OS boot up?
- [x] Does the OS have the kernel atleast working?
- [x] Does the OS have an I/O port driver?
- [x] Does the OS have serial driver?
- [ ] Does the OS have a terminal module?
- [ ] Does the OS have a driver for writing to the screen?
- [ ] Does the OS have a driver for drawing to the screen?
- [ ] Does the OS have paging implemented?
- [ ] Does the OS have a multitasking system?
- [x] does the OS have a screen drawing class?

## Any dependencies?

Yup! There are some dependencies that you will need that will help you with building and testing ChlorineOS. A list of them can be found here:

```
grub2
xorriso
binutils
g++
gcc
qemu
```

I believe that these can be installed with debian's/ubuntu's package manager, aswell as Arch linux's package manager. I may soon make a new page exactly describing how to install these packages, but for now I'm busy implementing more functions.
