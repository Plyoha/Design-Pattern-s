#include <iostream>

class AbstractProductA {
public:
    virtual void operationA() = 0;
    virtual ~AbstractProductA() = default;
};

class AbstractProductB {
public:
    virtual void operationB() = 0;
    virtual ~AbstractProductB() = default;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "Product A1" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "Product B1" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override {
        std::cout << "Product A2" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override {
        std::cout << "Product B2" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }
    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }
    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory = new ConcreteFactory1();
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();
    
    productA->operationA();
    productB->operationB();
    
    delete productA;
    delete productB;
    delete factory;
    
    return 0;
}
