/*
 *  We'll need the serial driver here, because we will initialize the serial module.
 */
#include "./drivers/serial.h"
/*
 *  Let's include `common.h` for the `printf` function!
 */
#include "./modules/common.h"
/*
 *  Let's include `fs.h` to create the root of our filesystem...
 */
#include "./modules/fs.h"
/*
 *  Let's now include all of the i386-compatible code, if we will even compile for i386 or i386-related architectures.
 */
#if ARCHITECTURE == 1
#include "./arch/i386/dt.h"
#endif

/*
 *  Let's define the basic values so that we can later run the init.sys file!
 */
#define INITEXE_START 0x00000000
#define INITEXE_SIZE 0x00000000

/*
 *  This is the function that is called by `entry.asm`. The file `entry.asm` gets loaded by the GRUB bootloader, and
 *  that's how ChlorineOS gets loaded...
 */
void main()
{
    /*
     *  Let's define some pointers that will map out the heap for ChlorineOS's kernel...
     */
    void *heap_start = 0x00E00000;
    void *heap_end = heap_start + 0x00100000;
    /*
     *  Let's initialize the serial driver (`drivers/serial.c` & `drivers/serial.h`)
     */
    printf("Initializing the serial module...\n");
    init_serial();
    /*
     *  If we're using a i386-compatible operating system, then we shall initialize descriptor tables...
     */
    #if ARCHITECTURE == 1
    printf("Initializing descriptor tables...\n");
    init_descriptor_tables();
    #endif
    printf("Initializing the heap...\n");
    /*
     *  Let's initialize the heap!
     */
    init_heap(heap_start, heap_end);
    /*
     *  Now that the heap is initialized, we can allocate memory, free it, etc. This allows us to create a memory-efficient
     *  kernel:
     *      | void *ptr = kmalloc(1024);
     *      | printf("Let's allocate 1024 bytes...\nThis is the pointer to the allocated memory: %d\n", ptr);
     *      | void *ptr2 = kmalloc(1024);
     *      | printf("Let's allocate 1024 more bytes...\nThis is the pointer to the allocated memory: %d\n", ptr2);
     */
    /*
     *  Let's setup the 8259 PIC (Programmable Interrupt Controller)
     */
    #if ARCHITECTURE == 1
    printf("Initializing 8259 PIC...\n");
    init_8259pic();
    #endif
    /*
     *  Let's create our filesystem, by initializing the root directory...
     */
    fs_node_t root;
    root->file_content_ptr = 0;
    root->file_size = 0;
    root->device = -1;
    root->path = "/";
    /*
     *  Let's now create a file that is just an executable which sets up the rest of the operating system, i.e it creates
     *  the bin/, etc/, home/, sys/, etc.
     */
    fs_node_t init;
    root->file_content_ptr = INITEXE_START;
    root->file_size = INITEXE_SIZE;
    root->device = -1;
    root->path = "/init.sys";
}