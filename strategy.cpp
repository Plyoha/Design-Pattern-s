#include <iostream>

class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "ConcreteStrategyA: Executing strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "ConcreteStrategyB: Executing strategy B" << std::endl;
    }
};

class Context {
private:
    Strategy* strategy;
public:
    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    Context* context = new Context();

    Strategy* strategyA = new ConcreteStrategyA();
    Strategy* strategyB = new ConcreteStrategyB();

    context->setStrategy(strategyA);
    context->executeStrategy();

    context->setStrategy(strategyB);
    context->executeStrategy();

    delete strategyA;
    delete strategyB;
    delete context;

    return 0;
}
