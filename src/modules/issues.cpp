#include "./issues.hpp"
#include "./terminal.hpp"

/*
 *  Issues can also be seen as a logger.
 */

void Chlorine::Issues::Error(const char* ErrorMessage, Terminal TerminalInstance)
{
    TerminalInstance.OutputToTerminal(4, ErrorMessage);
}