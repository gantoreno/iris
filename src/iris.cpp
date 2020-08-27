#include <math.h>
#include <random>
#include <sstream>
#include <iomanip>
#include <vector>
#include "../include/iris.hpp"

using namespace std;

/**
 * +--------+
 * | Neuron |
 * +--------+
 */

iris::Neuron::Neuron(double value) {
    this->id = iris::generateId();
    this->rawValue = value;

    this->activate();
    this->derive();
}

void iris::Neuron::activate() {
    this->activatedValue = this->rawValue / (1 + fabs(this->rawValue));
}

void iris::Neuron::derive() {
    this->derivedValue = 1  / pow(1 - fabs(this->activatedValue), 2);
}

string iris::Neuron::getId() {
    return this->id;
}

double iris::Neuron::getRawValue() {
    return this->rawValue;
}

double iris::Neuron::getActivatedValue() {
    return this->activatedValue;
}

double iris::Neuron::getDerivedValue() {
    return this->derivedValue;
}

void iris::Neuron::setValue(double value) {
    this->rawValue = value;
    
    this->activate();
    this->derive();
}

void iris::Neuron::describe(int level) {
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Neuron [\033[1;34m" << this->getId() << "\033[0m]" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "---" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Raw value:       \033[35m" << this->getRawValue() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Activated value: \033[35m" << this->getActivatedValue() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Derived value:   \033[35m" << this->getDerivedValue() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << endl;
}

/**
 * +-------+
 * | Layer |
 * +-------+
 */

iris::Layer::Layer(int size) {
    this->id = iris::generateId();
    this->size = size;

    for (int i = 0; i < size; i++) {
        this->neurons.push_back(new Neuron(0.0));
    }

    this->setNeuronMatrix();
    this->setActivatedNeuronMatrix();
    this->setDerivedNeuronMatrix();
}

string iris::Layer::getId() {
    return this->id;
}

int iris::Layer::getSize() {
    return this->size;
}

vector<iris::Neuron *> iris::Layer::getNeurons() {
    return this->neurons;
}

void iris::Layer::setNeuronMatrix() {
    this->neuronMatrix = new iris::Matrix(1, this->getSize(), false);

    for (int i = 0; i < this->getSize(); i++) {
        this->neuronMatrix->setValue(0, i, this->getNeurons().at(i)->getRawValue());
    }
}

void iris::Layer::setActivatedNeuronMatrix() {
    this->activatedNeuronMatrix = new iris::Matrix(1, this->getSize(), false);

    for (int i = 0; i < this->getSize(); i++) {
        this->activatedNeuronMatrix->setValue(0, i, this->getNeurons().at(i)->getActivatedValue());
    }
}
void iris::Layer::setDerivedNeuronMatrix() {
    this->derivedNeuronMatrix = new iris::Matrix(1, this->getSize(), false);

    for (int i = 0; i < this->getSize(); i++) {
        this->derivedNeuronMatrix->setValue(0, i, this->getNeurons().at(i)->getDerivedValue());
    }
}


iris::Matrix *iris::Layer::getNeuronMatrix() {
    return this->neuronMatrix;
}

iris::Matrix *iris::Layer::getActivatedNeuronMatrix() {
    return this->activatedNeuronMatrix;
}

iris::Matrix *iris::Layer::getDerivedNeuronMatrix() {
    return this->derivedNeuronMatrix;
}

void iris::Layer::updateNeuron(int index, double value) {
    this->neurons.at(index)->setValue(value);

    this->setNeuronMatrix();
    this->setActivatedNeuronMatrix();
    this->setDerivedNeuronMatrix();
}

void iris::Layer::describe(int level) {
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Layer [\033[1;33m" << this->getId() << "\033[0m]" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "---" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Size: \033[35m" << this->getNeurons().size() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Neurons: [" << endl;
    
    for (iris::Neuron *n : this->getNeurons()) {
        n->describe(level + 1);
    }
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
     
    cout << "]" << endl;    
    cout << endl;
}

/**
 * +--------+
 * | Matrix |
 * +--------+
 */

iris::Matrix::Matrix(int rows, int cols, bool isRandom) {
    this->id = iris::generateId();
    this->rows = rows;
    this->cols = cols;
    this->isRandom = isRandom;

    this->values = {};
 
    for (int i = 0; i < rows; i++) {
        vector<double> v = {};
        
        for (int j = 0; j < cols; j++) {
            if (isRandom) {
                v.push_back(iris::generateRandomNumber());
            } else {
                v.push_back(0.0);
            }
        }

        this->values.push_back(v);
    }
}

string iris::Matrix::getId() {
    return this->id;
}

iris::Matrix *iris::Matrix::multiply(iris::Matrix *m) {
    iris::Matrix *result = new iris::Matrix(this->getRows(), m->getCols(), false);

    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < m->getCols(); j++) {
            for (int k = 0; k < m->getRows(); k++) {
                double value = this->getValue(i, k) * m->getValue(k, j);
                
                result->setValue(i, j, result->getValue(i, j) + value);
            }
        }
    }

    return result;
}

iris::Matrix *iris::Matrix::transpose() {
    iris::Matrix *m = new iris::Matrix(this->getCols(), this->getRows(), false);

    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            m->setValue(j, i, this->getValue(i, j));
        }
    }

    return m;
}

vector<double> iris::Matrix::vectorize() {
    vector<double> result = {};

    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            result.push_back(this->getValue(i, j));
        }
    }

    return result;
}

double iris::Matrix::getCols() {
    return this->cols;
}
double iris::Matrix::getRows() {
    return this->rows;
}

void iris::Matrix::setValue(int row, int col, double value) {
    this->values.at(row).at(col) = value;
}

double iris::Matrix::getValue(int row, int col) {
    return this->values.at(row).at(col);
}

void iris::Matrix::describe(int level) {
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Matrix [\033[1;32m" << this->getId() << "\033[0m]" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "---" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Rows:    \033[35m" << this->getRows() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Columns: \033[35m" << this->getCols() << "\033[0m" << endl;
    
    for (int i = 0; i <  this->getRows(); i++) { 
        cout << "[ ";
        
        for (int j = 0; j < this->getCols(); j++) {
            cout << "\033[33m" 
                 << std::fixed 
                 << std::right 
                 << std::setw(5) 
                 << std::setprecision(4) 
                 << this->getValue(i, j) 
                 << std::defaultfloat 
                 << " ";    
        }

        cout << "\033[0m]" << endl;
    } 

    cout << endl;    
}

/**
 * +---------+
 * | Network |
 * +---------+
 */

iris::Network::Network(vector<int> topology) {
    this->id = iris::generateId();
    this->depth = topology.size();
    this->topology = topology;
    this->layers = {};
    this->weights = {};

    for (int size : topology) {
        this->layers.push_back(new Layer(size));
    }    
    
    for (int i = 0; i < topology.size() - 1; i++) {
        this->weights.push_back(new Matrix(topology.at(i), topology.at(i + 1), true));
    }
}

string iris::Network::getId() {
    return this->id;
}

int iris::Network::getDepth() {
    return this->depth;
}

vector<int> iris::Network::getTopology() {
    return this->topology;
}

vector<iris::Layer *> iris::Network::getLayers() {
    return this->layers;
}

vector<iris::Matrix *> iris::Network::getWeights() {
    return this->weights;
}

void iris::Network::setInput(vector<double> input) {
    this->input = input;

    for (int i = 0; i < input.size(); i++) {
        this->layers.at(0)->getNeurons().at(i)->setValue(input.at(i));
    }
}

void iris::Network::describe(int level) {
    cout << "Network [\033[1;32m" << this->getId() << "\033[0m]" << endl;
    cout << "---" << endl;
    cout << "Topology: { ";

    for (int size : this->getTopology()) {
        cout << "\033[35m" << size << "\033[0m ";
    }    
  
    cout << "}" << endl;
    cout << "Layers: [" << endl;

    for (Layer *l : this->getLayers()) {
        l->describe(level + 1);
    }
    
    cout << "]" << endl;
    cout << endl;
}

/**
 * +---------+
 * | Methods |
 * +---------+
 */

string iris::generateId() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::stringstream ss;
    
    ss << std::hex;
    
    for (int i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    
    ss << "-";
    
    for (int i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    
    ss << "-4";
    
    for (int i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    
    ss << "-";
    ss << dis2(gen);
    
    for (int i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    
    ss << "-";
    
    for (int i = 0; i < 12; i++) {
        ss << dis(gen);
    };
    
    return ss.str();
}

double iris::generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    return dis(gen);
}
