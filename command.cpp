#include <iostream>

class Command {
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

class Receiver {
public:
    void action() const {
        std::cout << "Receiver action executed" << std::endl;
    }
};

class ConcreteCommand : public Command {
private:
    Receiver* receiver;
public:
    ConcreteCommand(Receiver* r) : receiver(r) {}

    void execute() const override {
        receiver->action();
    }
};

class Invoker {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void invoke() const {
        if (command) {
            command->execute();
        }
    }
};

int main() {
    Receiver* receiver = new Receiver();
    Command* command = new ConcreteCommand(receiver);
    Invoker* invoker = new Invoker();

    invoker->setCommand(command);
    invoker->invoke();

    delete invoker;
    delete command;
    delete receiver;
    
    return 0;
}
