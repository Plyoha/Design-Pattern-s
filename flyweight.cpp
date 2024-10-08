#include <iostream>
#include <unordered_map>

class Flyweight {
private:
    std::string intrinsicState;
public:
    Flyweight(const std::string& state) : intrinsicState(state) {}
    
    void operation(const std::string& extrinsicState) const {
        std::cout << "Flyweight: " << intrinsicState << " with " << extrinsicState << std::endl;
    }
};

class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;
public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new Flyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights) {
            delete pair.second;
        }
    }
};

int main() {
    FlyweightFactory* factory = new FlyweightFactory();
    Flyweight* fw1 = factory->getFlyweight("A");
    Flyweight* fw2 = factory->getFlyweight("B");
    
    fw1->operation("X");
    fw2->operation("Y");
    
    delete factory;
    return 0;
}
