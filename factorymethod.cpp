#include <iostream>

class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    void operation() override {
        std::cout << "Product A operation" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void operation() override {
        std::cout << "Product B operation" << std::endl;
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
    void someOperation() {
        Product* product = this->factoryMethod();
        product->operation();
        delete product;
    }
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creator = new ConcreteCreatorA();
    creator->someOperation();
    
    delete creator;
    creator = new ConcreteCreatorB();
    creator->someOperation();
    
    delete creator;
    return 0;
}
