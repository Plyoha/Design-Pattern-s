#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) const = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) const = 0;
    virtual ~Visitor() = default;
};

class Element {
public:
    virtual void accept(Visitor* visitor) const = 0;
    virtual ~Element() = default;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) const override {
        visitor->visitConcreteElementA(this);
    }

    void operationA() const {
        std::cout << "ConcreteElementA operation" << std::endl;
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) const override {
        visitor->visitConcreteElementB(this);
    }

    void operationB() const {
        std::cout << "ConcreteElementB operation" << std::endl;
    }
};

class ConcreteVisitor1 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) const override {
        std::cout << "ConcreteVisitor1 visiting ConcreteElementA" << std::endl;
        element->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* element) const override {
        std::cout << "ConcreteVisitor1 visiting ConcreteElementB" << std::endl;
        element->operationB();
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) const override {
        std::cout << "ConcreteVisitor2 visiting ConcreteElementA" << std::endl;
        element->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* element) const override {
        std::cout << "ConcreteVisitor2 visiting ConcreteElementB" << std::endl;
        element->operationB();
    }
};

int main() {
    std::vector<Element*> elements = { new ConcreteElementA(), new ConcreteElementB() };

    ConcreteVisitor1* visitor1 = new ConcreteVisitor1();
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2();

    for (Element* element : elements) {
        element->accept(visitor1);
        element->accept(visitor2);
    }

    for (Element* element : elements) {
        delete element;
    }

    delete visitor1;
    delete visitor2;

    return 0;
}
