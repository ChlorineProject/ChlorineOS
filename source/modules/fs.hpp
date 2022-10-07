#pragma once

#define FILE 1
#define DIRECTORY 2

namespace Chlorine
{
    namespace Filesystem
    {
        class FileNode
        {
            char FileName[128];        /* A 128-byte array that stores the name of the FileNode...            */
            unsigned int FileType : 2; /* A 2-bit number to store the type of file that the FileNode is using */
            unsigned int Pointer;      /* An unsigned 32 bit integer that points to the start of the data of
                                          the file in storage...                                              */
            unsigned int StorageDev;   /* Points to the storage device where the file's data is stored at...  */
        };
    }
}