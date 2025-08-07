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

// Incompatible Class
class LegacyComponent
{
public:
    void go()
    {
        cout << "Executing LegacyComponent::go()" << endl;
    }
};
/**
 * Example of Object Adapter
 * 
 * Inherits from the modern components and contains an instance of legacy component
 */
class LegacyAdapter: public Component
{
    private:
        unique_ptr<LegacyComponent> m_adaptee;

        public:
            LegacyAdapter() {
                m_adaptee = make_unique<LegacyComponent>();
            }

            virtual void run() override {
                m_adaptee->go();
            }
};

class LegacyClassAdapter: public Component, private LegacyComponent
{
    public:
        virtual void run() override
        {
            cout << "LegacyClassAdapter::run() -> calling LegacyComponent::go()" << endl;
            go();
        }
};

int main() 
{
    const unique_ptr<Component> components[] {
        make_unique<ConcreteComponentA>(),
        make_unique<ConcreteComponentB>(),
        make_unique<LegacyAdapter>(),
        make_unique<LegacyClassAdapter>()
    };

    for (const auto& component : components)
    {
        component->run();
    }
    return 0;
}