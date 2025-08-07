#include <iostream>
#include <memory>

using namespace std;

class Component
{

public:
    virtual void run() = 0;
    virtual ~Component() = default;
};

class ConcreteComponentA : public Component
{
public:
    virtual void run() override
    {
        cout << "Executing ComponentA::run()" << endl;
    }
};

class ConcreteComponentB : public Component
{
public:
    virtual void run() override
    {
        cout << "Executing ComponentB::run()" << endl;
    }
};

class LegacyComponent
{
public:
    void go()
    {
        cout << "Executing LegacyComponent::go()" << endl;
    }
};

int main() 
{
    const unique_ptr<Component> components[] {
        make_unique<ConcreteComponentA>(),
        make_unique<ConcreteComponentB>()
    };

    for (const auto& component : components)
    {
        component->run();
    }
    return 0;
}