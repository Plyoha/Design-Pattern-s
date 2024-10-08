#include <iostream>
#include <string>
#include <vector>

class Mediator {
public:
    virtual void send(const std::string& message, class Colleague* colleague) const = 0;
    virtual ~Mediator() = default;
};

class Colleague {
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* med) : mediator(med) {}
    virtual void receive(const std::string& message) const = 0;
};

class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator* med) : Colleague(med) {}
    
    void send(const std::string& message) const {
        mediator->send(message, this);
    }

    void receive(const std::string& message) const override {
        std::cout << "Colleague1 received: " << message << std::endl;
    }
};

class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator* med) : Colleague(med) {}

    void send(const std::string& message) const {
        mediator->send(message, this);
    }

    void receive(const std::string& message) const override {
        std::cout << "Colleague2 received: " << message << std::endl;
    }
};

class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;
public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void send(const std::string& message, Colleague* sender) const override {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->receive(message);
            }
        }
    }
};

int main() {
    ConcreteMediator* mediator = new ConcreteMediator();

    Colleague* colleague1 = new ConcreteColleague1(mediator);
    Colleague* colleague2 = new ConcreteColleague2(mediator);
    
    mediator->addColleague(colleague1);
    mediator->addColleague(colleague2);

    colleague1->send("Hello from Colleague1!");
    colleague2->send("Hello from Colleague2!");

    delete colleague1;
    delete colleague2;
    delete mediator;
    
    return 0;
}
