#pragma once

namespace Chlorine
{
    namespace Screen
    {
        namespace Text
        {
            volatile char *Video;
            void WriteString(int color, const char *string);
        }
        namespace Gui
        {
            unsigned char *VGA;
            unsigned char *DblBuffer;
            int Width;
            int Height;
            void UpdateScreen();
        }
    }
}