#include <iostream>

class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() = default;
};

class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA operation" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB operation" << std::endl;
    }
};

class Abstraction {
protected:
    Implementor* implementor;
public:
    Abstraction(Implementor* impl) : implementor(impl) {}
    
    virtual void operation() const {
        implementor->operationImpl();
    }
    virtual ~Abstraction() = default;
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() const override {
        std::cout << "RefinedAbstraction delegates to: ";
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Abstraction* abstraction = new RefinedAbstraction(implA);
    abstraction->operation();
    
    delete abstraction;
    delete implA;

    return 0;
}
