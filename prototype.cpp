#include <iostream>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void operation() const = 0;
    virtual ~Prototype() = default;
};

class ConcretePrototypeA : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }
    
    void operation() const override {
        std::cout << "ConcretePrototypeA operation" << std::endl;
    }
};

class ConcretePrototypeB : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeB(*this);
    }
    
    void operation() const override {
        std::cout << "ConcretePrototypeB operation" << std::endl;
    }
};

int main() {
    Prototype* prototypeA = new ConcretePrototypeA();
    Prototype* prototypeB = prototypeA->clone();
    
    prototypeA->operation();
    prototypeB->operation();
    
    delete prototypeA;
    delete prototypeB;
    return 0;
}
