#include <math.h>
#include <random>
#include <sstream>
#include <iomanip>
#include <vector>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

/**
 * +-------+
 * | Utils |
 * +-------+
 */

string Utils::generateId() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    uniform_int_distribution<> dis2(8, 11);

    stringstream ss;
    
    ss << hex;
    
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

double Utils::generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    return dis(gen);
}

/**
 * +--------+
 * | Neuron |
 * +--------+
 */

Neuron::Neuron(double value) {
    this->id = Utils::generateId();
    this->rawValue = value;

    this->activate();
    this->derive();
}

void Neuron::activate() {
    this->activatedValue = this->rawValue / (1 + fabs(this->rawValue));
}

void Neuron::derive() {
    this->derivedValue = 1  / pow(1 - fabs(this->activatedValue), 2);
}

string Neuron::getId() {
    return this->id;
}

double Neuron::getRawValue() {
    return this->rawValue;
}

double Neuron::getActivatedValue() {
    return this->activatedValue;
}

double Neuron::getDerivedValue() {
    return this->derivedValue;
}

void Neuron::setValue(double value) {
    this->rawValue = value;
    
    this->activate();
    this->derive();
}

void Neuron::describe(int level) {
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
 * +--------+
 * | Matrix |
 * +--------+
 */

Matrix::Matrix(int rows, int cols, bool isRandom) {
    this->id = Utils::generateId();
    this->rows = rows;
    this->cols = cols;
    this->isRandom = isRandom;

    for (int i = 0; i < rows; i++) {
        vector<double> row;
        
        for (int j = 0; j < cols; j++) {
            if (isRandom) {
                row.push_back(Utils::generateRandomNumber());
            } else {
                row.push_back(0.0);
            }
        }

        this->values.push_back(row);
    }
}

string Matrix::getId() {
    return this->id;
}

Matrix Matrix::multiply(Matrix m) {
    Matrix result = Matrix(this->rows, m.getCols(), false);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < m.getCols(); j++) {
            for (int k = 0; k < m.getRows(); k++) {
                double value = this->getValue(i, k) * m.getValue(k, j);
                
                result.setValue(i, j, result.getValue(i, j) + value);
            }
        }
    }

    return result;
}

Matrix Matrix::transpose() {
    Matrix m = Matrix(this->cols, this->rows, false);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            m.setValue(j, i, this->getValue(i, j));
        }
    }

    return m;
}

vector<double> Matrix::vectorize() {
    vector<double> result;

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.push_back(this->getValue(i, j));
        }
    }

    return result;
}

double Matrix::getCols() {
    return this->cols;
}
double Matrix::getRows() {
    return this->rows;
}

void Matrix::setValue(int row, int col, double value) {
    this->values.at(row).at(col) = value;
}

double Matrix::getValue(int row, int col) {
    return this->values.at(row).at(col);
}

void Matrix::describe(int level) { 
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
    
    cout << "Rows:    \033[35m" << this->rows << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Columns: \033[35m" << this->cols << "\033[0m" << endl;
    
    for (int i = 0; i <  this->rows; i++) {  
        for (int i = 0; i < level; i++) {
            cout << "\t";
        }
    
        cout << "[ ";
        
        for (int j = 0; j < this->cols; j++) {
            cout << "\033[33m" 
                 << fixed 
                 << right 
                 << setw(5) 
                 << setprecision(4) 
                 << this->getValue(i, j) 
                 << defaultfloat 
                 << " ";    
        }

        cout << "\033[0m]" << endl;
    } 

    cout << endl;    
}

/**
 * +-------+
 * | Layer |
 * +-------+
 */

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
    
    cout << "Size: \033[35m" << this->neurons.size() << "\033[0m" << endl;
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    
    cout << "Neurons: [" << endl;
    
    for (Neuron n : this->neurons) {
        n.describe(level + 1);
    }
    
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
     
    cout << "]" << endl;    
    cout << endl;
}

/**
 * +---------+
 * | Network |
 * +---------+
 */

Network::Network(vector<int> topology) {
    this->id = Utils::generateId();
    this->depth = topology.size();
    this->topology = topology;

    for (int size : this->topology) {
        this->layers.push_back(Layer(size));
    }    
    
    for (int i = 0; i < this->topology.size() - 1; i++) {
        int currentTopology = this->topology.at(i);
        int nextTopology = this->topology.at(i + 1);

        this->weights.push_back(Matrix(currentTopology, nextTopology, true));
        this->gradients.push_back(Matrix(1, nextTopology, false));
        this->deltas.push_back(Matrix(currentTopology, nextTopology, false));
    }
}

string Network::getId() {
    return this->id;
}

int Network::getDepth() {
    return this->depth;
}

vector<int> Network::getTopology() {
    return this->topology;
}

vector<Layer> Network::getLayers() {
    return this->layers;
}

vector<Matrix> Network::getWeights() {
    return this->weights;
}

vector<Matrix> Network::getGradients() {
    return this->gradients;
}

vector<Matrix> Network::getDeltas() {
    return this->deltas;
}

void Network::setInput(vector<double> input) {
    this->input = input;
    this->layers.at(0).setValues(this->input);
}


void Network::setTarget(vector<double> target) {
    this->target = target;
}

void Network::feedForward() {
    for (int i = 0; i < this->depth - 1; i++) {
        Layer currentLayer = this->layers.at(i);

        Matrix input = i != 0
            ? currentLayer.getActivatedNeuronMatrix()
            : currentLayer.getNeuronMatrix();
        Matrix weights = this->weights.at(i);
        Matrix result = input.multiply(weights);

        Layer &nextLayer = this->layers.at(i + 1);
    
        nextLayer.setValues(result.vectorize());
    }

    this->calculateError();
    this->propagateBackwards();
}

void Network::propagateBackwards() {
    Layer outputLayer = this->layers.at(this->layers.size() - 1);
    Layer lastHiddenLayer = this->layers.at(this->layers.size() - 2); 

    Matrix derivedOutputValues = outputLayer.getDerivedNeuronMatrix();

    Matrix &lastWeights = this->weights.at(this->weights.size() - 1);
    Matrix &lastGradients = this->gradients.at(this->gradients.size() - 1);
    Matrix &lastDeltas = this->deltas.at(this->deltas.size() - 1);

    for (int i = 0; i < outputLayer.getSize(); i++) {
        double derivedOutputValue = derivedOutputValues.getValue(0, i);
        double outputError = this->errors.at(i); 

        double gradientValue = derivedOutputValue * outputError;

        lastGradients.setValue(0, i, gradientValue);
    }

    lastDeltas = lastGradients
        .transpose()
        .multiply(lastHiddenLayer.getActivatedNeuronMatrix())
        .transpose();

    for (int i = 0; i < lastWeights.getRows(); i++) {
        for (int j = 0; j < lastWeights.getCols(); j++) {
            double previousWeight = lastWeights.getValue(i, j);
            double deltaWeight = lastDeltas.getValue(i, j);

            lastWeights.setValue(i, j, previousWeight - deltaWeight);
        }
    }
}

void Network::calculateError() {
    this->errors.clear();
    this->globalError = 0;

    Layer outputLayer = this->layers.at(this->layers.size() - 1);

    for (int i = 0; i < outputLayer.getSize(); i++) {
        Neuron outputNeuron = outputLayer.getNeurons().at(i);

        double outputValue = outputNeuron.getActivatedValue();
        double expectedValue = this->target.at(i);

        double error = outputValue - expectedValue;

        this->errors.push_back(error);
        this->globalError += error;
    }

    this->historicalErrors.push_back(this->errors);
}

void Network::describe(int level) {
    cout << "Network [\033[1;32m" << this->getId() << "\033[0m]" << endl;
    cout << "---" << endl;
    cout << "Topology: [ ";

    for (int size : this->topology) {
        cout << "\033[35m" << size << "\033[0m ";
    }    
  
    cout << "]" << endl;
    cout << "Input:    [ ";

    for (int value : this->input) {
        cout << "\033[35m" << value << "\033[0m ";
    }    
  
    cout << "]" << endl;
    cout << "Target:   [ ";

    for (int value : this->target) {
        cout << "\033[35m" << value << "\033[0m ";
    }    
  
    cout << "]" << endl;
    cout << "Layers: [" << endl;

    for (int i = 0; i < this->depth; i++) {
        this->layers.at(i).describe(level + 1);

        if (i < this->depth - 1) {
            this->weights.at(i).describe(level + 1);
            this->gradients.at(i).describe(level + 1);
            this->deltas.at(i).describe(level + 1);
        }
    }
    
    cout << "]" << endl;
    cout << "Global error:  \033[35m" << this->globalError << "\033[0m" << endl;
    cout << "Output errors: [ ";

    for (double error : this->errors) {
        cout << "\033[35m" << error << "\033[0m ";
    }    
  
    cout << "]" << endl;
    cout << endl;
}
