#include <iostream>
#include <vector>

class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual int next() = 0;
    virtual ~Iterator() = default;
};

class ConcreteIterator : public Iterator {
private:
    const std::vector<int>& collection;
    size_t position;
public:
    ConcreteIterator(const std::vector<int>& coll) : collection(coll), position(0) {}

    bool hasNext() const override {
        return position < collection.size();
    }

    int next() override {
        return collection[position++];
    }
};

class Aggregate {
public:
    virtual Iterator* createIterator() const = 0;
    virtual ~Aggregate() = default;
};

class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> collection;
public:
    void addItem(int item) {
        collection.push_back(item);
    }

    Iterator* createIterator() const override {
        return new ConcreteIterator(collection);
    }
};

int main() {
    ConcreteAggregate* aggregate = new ConcreteAggregate();
    aggregate->addItem(1);
    aggregate->addItem(2);
    aggregate->addItem(3);

    Iterator* iterator = aggregate->createIterator();
    while (iterator->hasNext()) {
        std::cout << "Item: " << iterator->next() << std::endl;
    }

    delete iterator;
    delete aggregate;
    return 0;
}
