#include "./issues.hpp"
#include "./terminal.hpp"

/*
 *  Issues can also be seen as a logger.
 */

/*
 *  For use with logging errors onto a terminal. For the first argument, the error message is
 *  to be passed. For the second message, you must pass the terminal instance (an instance of the
 *  class named `Terminal`). After that, it will send the error to the specified terminal. Note that
 *  issues.cpp & issues.hpp are still a work-in-progress.
 */
void Chlorine::Issues::Error(const char* ErrorMessage, Terminal TerminalInstance)
{
    TerminalInstance.OutputToTerminal(4, ErrorMessage);
}