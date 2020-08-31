#include <math.h>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

Neuron::Neuron(double value, bool isBiasNode)
{
    this->id = Utils::generateId();
    this->rawValue = value;
    this->isBiasNode = isBiasNode;

    if (this->isBiasNode)
    {
        this->activatedValue = value;
        this->derivedValue = value;
    }
    else
    {
        this->rawValue = value;

        this->activate();
        this->derive();
    }
}

void Neuron::activate()
{
    this->activatedValue = this->rawValue / (1 + fabs(this->rawValue));
}

void Neuron::derive()
{
    this->derivedValue = this->activatedValue * (1 - this->activatedValue);
}

string Neuron::getId()
{
    return this->id;
}

double Neuron::getRawValue()
{
    return this->rawValue;
}

double Neuron::getActivatedValue()
{
    return this->activatedValue;
}

double Neuron::getDerivedValue()
{
    return this->derivedValue;
}

void Neuron::setValue(double value)
{
    this->rawValue = value;

    this->activate();
    this->derive();
}

void Neuron::describe(int level)
{
    string tabs = Utils::generateIndentation(level);

    cout << tabs << (this->isBiasNode ? "\033[1;36m(Bias) \033[0m" : "");
    cout << "Neuron [\033[1;34m" << this->id << "\033[0m]" << endl;
    cout << tabs << "---" << endl;
    cout << tabs << "Raw value:       \033[35m" << this->rawValue << "\033[0m" << endl;
    cout << tabs << "Activated value: \033[35m" << this->activatedValue << "\033[0m" << endl;
    cout << tabs << "Derived value:   \033[35m" << this->derivedValue << "\033[0m" << endl;
    cout << endl;
}
