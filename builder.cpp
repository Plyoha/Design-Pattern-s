#include <iostream>
#include <string>

class Product {
public:
    std::string partA;
    std::string partB;
    std::string partC;

    void show() {
        std::cout << "Product parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }
};

class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getResult() = 0;
    virtual ~Builder() = default;
};

class ConcreteBuilder : public Builder {
private:
    Product* product;
    
public:
    ConcreteBuilder() {
        product = new Product();
    }

    void buildPartA() override {
        product->partA = "Part A";
    }

    void buildPartB() override {
        product->partB = "Part B";
    }

    void buildPartC() override {
        product->partC = "Part C";
    }

    Product* getResult() override {
        return product;
    }
};

class Director {
public:
    void construct(Builder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;
    Builder* builder = new ConcreteBuilder();
    
    director.construct(builder);
    Product* product = builder->getResult();
    product->show();
    
    delete product;
    delete builder;
    return 0;
}
