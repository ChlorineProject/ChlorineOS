#pragma once

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

namespace Chlorine
{
    namespace Screen
    {
        namespace Text
        {
            void WriteCharacter(int Color, char Character);
            void WriteString(int Color, const char *String);
            void EnableCursor(unsigned char cursor_start, unsigned char cursor_end);
            void DisableCursor();
            void UpdateCursor(int x, int y);
            unsigned short int GetCursorPosition();
        }
        namespace Gui
        {
        }
    }
}