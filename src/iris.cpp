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

void iris::Neuron::describe() {
    cout << "\t\tNeuron [\033[31m" << this->getId() << "\033[0m]" << endl;
    cout << "\t\t---" << endl;
    cout << "\t\tRaw value:       \033[35m" << this->getRawValue() << "\033[0m" << endl;
    cout << "\t\tActivated value: \033[35m" << this->getActivatedValue() << "\033[0m" << endl;
    cout << "\t\tDerived value:   \033[35m" << this->getDerivedValue() << "\033[0m" << endl;
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
}

string iris::Layer::getId() {
    return this->id;
}

vector<iris::Neuron *> iris::Layer::getNeurons() {
    return this->neurons;
}

void iris::Layer::describe() {
    cout << "\tLayer [\033[31m" << this->getId() << "\033[0m]" << endl;
    cout << "\t---" << endl;
    cout << "\tSize: \033[35m" << this->getNeurons().size() << "\033[0m" << endl;
    cout << "\tNeurons: [" << endl;
    
    for (iris::Neuron *n : this->getNeurons()) {
        n->describe();
    }
    
    cout << "\t]" << endl;    
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

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < rows; i++) {
        vector<double> v = {};
        
        for (int j = 0; j < cols; j++) {
            if (isRandom) {
                v.push_back(dis(gen));
            } else {
                v.push_back(0.0);
            }
        }

        this->values.push_back(v);
    }
}

void iris::Matrix::transpose() {
    vector<vector<double>> values = {};
    
    for (int i = 0; i < this->cols; i++) {
        vector<double> v = {};
    
        for (int j = 0; j < this->rows; j++) {
            v.push_back(this->getValue(j, i));
        }

        values.push_back(v);
    }    
    
    this->values = values;
    this->cols = this->cols + this->rows;
    this->rows = this->cols - this->rows;
    this->cols = this->cols - this->rows;
}

string iris::Matrix::getId() {
    return this->id;
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

void iris::Matrix::describe() {
    cout << "Matrix [\033[31m" << this->getId() << "\033[0m]" << endl;
    cout << "---" << endl;
    cout << "Rows:    \033[33m" << this->getRows() << "\033[0m" << endl;
    cout << "Columns: \033[33m" << this->getCols() << "\033[0m" << endl;
    
    for (int i = 0; i <  this->getRows(); i++) {
        cout << "[ ";
        
        for (int j = 0; j < this->getCols(); j++) {
            cout << "\033[33m" 
                 << std::fixed 
                 << std::right 
                 << std::setw(5) 
                 << std::setprecision(4) 
                 << this->getValue(i, j) 
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

void iris::Network::setInput(vector<double> input) {
    this->input = input;

    for (int i = 0; i < input.size(); i++) {
        this->layers.at(0)->getNeurons().at(i)->setValue(input.at(i));
    }
}

vector<iris::Layer *> iris::Network::getLayers() {
    return this->layers;
}

void iris::Network::describe() {
    cout << "Network [\033[31m" << this->getId() << "\033[0m]" << endl;
    cout << "---" << endl;
    cout << "Topology: { ";

    for (int size : this->topology) {
        cout << "\033[35m" << size << "\033[0m ";
    }    
  
    cout << "}" << endl;
    cout << "Layers: [" << endl;

    for (Layer *l : this->getLayers()) {
        l->describe();
    }
    
    cout << "]" << endl;
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
