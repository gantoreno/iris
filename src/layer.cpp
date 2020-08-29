#include <math.h>
#include <vector>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

Layer::Layer(int size) {
    this->id = Utils::generateId();
    this->size = size;

    for (int i = 0; i < this->size; i++) {
        this->neurons.push_back(Neuron(0.0));
    }
}

string Layer::getId() {
    return this->id;
}

int Layer::getSize() {
    return this->size;
}

vector<Neuron> Layer::getNeurons() {
    return this->neurons;
}

Matrix Layer::getNeuronMatrix() {
    Matrix neuronMatrix = Matrix(1, this->size, false);

    for (int i = 0; i < this->size; i++) {
        Neuron currentNeuron = this->neurons.at(i);

        neuronMatrix.setValue(0, i, currentNeuron.getRawValue());
    }

    return neuronMatrix;
}

Matrix Layer::getActivatedNeuronMatrix() {
    Matrix activatedNeuronMatrix = Matrix(1, this->size, false);

    for (int i = 0; i < this->size; i++) {
        Neuron currentNeuron = this->neurons.at(i);

        activatedNeuronMatrix.setValue(0, i, currentNeuron.getActivatedValue());
    }

    return activatedNeuronMatrix;
}

Matrix Layer::getDerivedNeuronMatrix() {
    Matrix derivedNeuronMatrix = Matrix(1, this->size, false);

    for (int i = 0; i < this->size; i++) {
        Neuron currentNeuron = this->neurons.at(i);

        derivedNeuronMatrix.setValue(0, i, currentNeuron.getDerivedValue());
    }

    return derivedNeuronMatrix;
}

void Layer::setValues(vector<double> values) {
    for (int i = 0; i < values.size(); i++) {
        Neuron &currentNeuron = this->neurons.at(i);

        currentNeuron.setValue(values.at(i));
    }
}

void Layer::describe(int level) {
    string tabs = Utils::generateIndentation(level);
    
    cout << tabs << "Layer [\033[1;33m" << this->id << "\033[0m]" << endl;
    cout << tabs << "---" << endl;
    cout << tabs << "Size: \033[35m" << this->neurons.size() << "\033[0m" << endl;
    cout << tabs << "Neurons: [" << endl;
    
    for (Neuron neuron : this->neurons) {
        neuron.describe(level + 1);
    }

    cout << tabs << "]" << endl;    
    cout << endl;
}
