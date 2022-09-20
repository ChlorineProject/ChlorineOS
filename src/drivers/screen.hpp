#pragma once

namespace Chlorine
{
    namespace Screen
    {
        namespace Text
        {
            unsigned short int VGA_WIDTH;
            unsigned short int VGA_HEIGHT;
            void WriteString(int Color, const char *String);
            void EnableCursor(unsigned char cursor_start, unsigned char cursor_end);
            void DisableCursor();
            void UpdateCursor(int x, int y);
            unsigned short int GetCursorPosition();
        }
    }
}