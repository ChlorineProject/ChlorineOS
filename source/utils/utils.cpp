#include "./utils.hpp"
#include "./../drivers/keyboard.hpp"

/*
 *  Returns the length of a string in characters.
 */
unsigned int Chlorine::Utilities::String::GetLengthOfString(const char *String)
{
    unsigned int Count = 0;
    while (*String != '\0')
    {
        Count++;
        String++;
    }
    return Count;
}

/*
 *  Useful for joining two integers together. For example, if I input the numbers 5 and 4 to this function, I
 *  get the returned value of 54.
 */
int Chlorine::Utilities::String::ConCat(int x, int y)
{
    return 10 * x + y;
}

unsigned int Chlorine::Utilities::Number::DigitCount(int num)
{
    unsigned int count = 0;
    if (num == 0)
        return 1;
    while (num > 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

void Chlorine::Utilities::String::NumberToString(int num, char *number)
{
    int dgcount = Chlorine::Utilities::Number::DigitCount(num);
    int index = dgcount - 1;
    char x;
    if (num == 0 && dgcount == 1)
    {
        number[0] = '0';
        number[1] = '\0';
    }
    else
    {
        while (num != 0)
        {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

/*
 *  Useful for converting keycodes given by the keyboard to characters. If the keys aren't related to characters, this
 *  function will just return nothing.
 */
char Chlorine::Utilities::ASCII::KeysToASCII(unsigned char KeyCode)
{
    switch (KeyCode)
    {
    case KEY_A:
        return 'A';
    case KEY_B:
        return 'B';
    case KEY_C:
        return 'C';
    case KEY_D:
        return 'D';
    case KEY_E:
        return 'E';
    case KEY_F:
        return 'F';
    case KEY_G:
        return 'G';
    case KEY_H:
        return 'H';
    case KEY_I:
        return 'I';
    case KEY_J:
        return 'J';
    case KEY_K:
        return 'K';
    case KEY_L:
        return 'L';
    case KEY_M:
        return 'M';
    case KEY_N:
        return 'N';
    case KEY_O:
        return 'O';
    case KEY_P:
        return 'P';
    case KEY_Q:
        return 'Q';
    case KEY_R:
        return 'R';
    case KEY_S:
        return 'S';
    case KEY_T:
        return 'T';
    case KEY_U:
        return 'U';
    case KEY_V:
        return 'V';
    case KEY_W:
        return 'W';
    case KEY_X:
        return 'X';
    case KEY_Y:
        return 'Y';
    case KEY_Z:
        return 'Z';
    case KEY_1:
        return '1';
    case KEY_2:
        return '2';
    case KEY_3:
        return '3';
    case KEY_4:
        return '4';
    case KEY_5:
        return '5';
    case KEY_6:
        return '6';
    case KEY_7:
        return '7';
    case KEY_8:
        return '8';
    case KEY_9:
        return '9';
    case KEY_0:
        return '0';
    case KEY_MINUS:
        return '-';
    case KEY_EQUAL:
        return '=';
    case KEY_SQUARE_OPEN_BRACKET:
        return '[';
    case KEY_SQUARE_CLOSE_BRACKET:
        return ']';
    case KEY_SEMICOLON:
        return ';';
    case KEY_BACKSLASH:
        return '\\';
    case KEY_COMMA:
        return ',';
    case KEY_DOT:
        return '.';
    case KEY_FORESLHASH:
        return '/';
    case KEY_SPACE:
        return ' ';
    default:
        return 0;
    }
}