# Developer Notes
This page is important for seeing important notes left by the developer. These notes may show you how code works, or may just teach you something.
## How is archtecture organized in ChlorineOS's code?
The first architectures that will be supported will be the x86 architecture. If there is code in `i386`, this code can be used by `i486`, `i586`, `i686`, `i786`, `x86_64`. If you have code in the architecture section of `x86_64`, it cannot run in `i386` computers.