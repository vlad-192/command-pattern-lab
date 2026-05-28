#include "Command.hpp"

Receiver::Receiver(std::ostream& out)
    : out_(out)
{
}

void Receiver::action()
{
    out_ << "Receiver: execute action" << std::endl;
}

ConcreteCommand::ConcreteCommand(std::unique_ptr<Receiver> receiver)
    : receiver_(std::move(receiver))
{
}

void ConcreteCommand::execute()
{
    receiver_->action();
}

void Invoker::set(Command* command)
{
    command_ = command;
}

void Invoker::confirm()
{
    if (command_)
    {
        command_->execute();
    }
}

int run_command_demo(std::ostream& out)
{
    ConcreteCommand command(std::make_unique<Receiver>(out));

    Invoker invoker;
    invoker.set(&command);
    invoker.confirm();

    return 0;
}
