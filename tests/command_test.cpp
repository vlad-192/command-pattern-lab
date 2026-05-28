#include "Command.hpp"

#include <sstream>
#include <string>

int main()
{
    std::ostringstream output;
    run_command_demo(output);

    const std::string expected = "Receiver: execute action\n";

    if (output.str() != expected)
        return 1;

    return 0;
}
