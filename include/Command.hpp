#pragma once

#include <iostream>
#include <memory>

class Receiver
{
public:
    explicit Receiver(std::ostream& out = std::cout);
    void action();

private:
    std::ostream& out_;
};

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class ConcreteCommand : public Command
{
public:
    explicit ConcreteCommand(std::unique_ptr<Receiver> receiver);
    void execute() override;

private:
    std::unique_ptr<Receiver> receiver_;
};

class Invoker
{
public:
    void set(Command* command);
    void confirm();

private:
    Command* command_ = nullptr;
};

int run_command_demo(std::ostream& out = std::cout);
