#include <iostream>
#include <iomanip>
#include <vector>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

Network::Network(vector<Layer> layers)
{
    this->id = Utils::generateId();
    this->layers = layers;
    this->depth = this->layers.size();

    for (Layer l : this->layers)
    {
        this->topology.push_back(l.getSize());
    }

    for (int i = 0; i < this->topology.size() - 1; i++)
    {
        int currentTopology = this->topology.at(i);
        int nextTopology = this->topology.at(i + 1);

        this->weights.push_back(Matrix(currentTopology, nextTopology, true));
        this->gradients.push_back(Matrix(1, nextTopology, false));
        this->deltas.push_back(Matrix(currentTopology, nextTopology, false));
    }
}

string Network::getId()
{
    return this->id;
}

int Network::getDepth()
{
    return this->depth;
}

vector<int> Network::getTopology()
{
    return this->topology;
}

vector<Layer> Network::getLayers()
{
    return this->layers;
}

vector<Matrix> Network::getWeights()
{
    return this->weights;
}

vector<Matrix> Network::getGradients()
{
    return this->gradients;
}

vector<Matrix> Network::getDeltas()
{
    return this->deltas;
}

void Network::setInput(vector<double> input)
{
    this->input = input;
    this->layers.at(0).setValues(this->input);
}

void Network::setTarget(vector<double> target)
{
    this->target = target;
}

void Network::feedForward()
{
    for (int i = 0; i < this->depth - 1; i++)
    {
        Layer currentLayer = this->layers.at(i);

        Matrix input = i != 0 ? currentLayer.getActivatedNeuronMatrix() : currentLayer.getNeuronMatrix();
        Matrix weights = this->weights.at(i);
        Matrix result = input.multiply(weights);

        Layer& nextLayer = this->layers.at(i + 1);

        nextLayer.setValues(result.vectorize());
    }
}

void Network::propagateBackwards()
{
    for (int l = this->layers.size() - 1; l > 0; l--)
    {
        if (l == this->layers.size() - 1)
        {
            Layer outputLayer = this->layers.at(l);
            Layer lastHiddenLayer = this->layers.at(l - 1);

            Matrix derivedOutputValues = outputLayer.getDerivedNeuronMatrix();

            Matrix& lastWeights = this->weights.at(l - 1);
            Matrix& lastGradients = this->gradients.at(l - 1);
            Matrix& lastDeltas = this->deltas.at(l - 1);

            for (int i = 0; i < outputLayer.getSize(); i++)
            {
                double derivedOutputValue = derivedOutputValues.getValue(0, i);
                double outputError = this->errors.at(i);

                double gradientValue = derivedOutputValue * outputError;

                lastGradients.setValue(0, i, gradientValue);
            }

            lastDeltas = lastGradients
                             .transpose()
                             .multiply(lastHiddenLayer.getActivatedNeuronMatrix())
                             .transpose();

            for (int i = 0; i < lastWeights.getRows(); i++)
            {
                for (int j = 0; j < lastWeights.getCols(); j++)
                {
                    double previousWeight = lastWeights.getValue(i, j);
                    double deltaWeight = lastDeltas.getValue(i, j);

                    lastWeights.setValue(i, j, previousWeight - deltaWeight);
                }
            }
        }
        else
        {
            Matrix& leftWeights = this->weights.at(l - 1);
            Matrix& leftGradients = this->gradients.at(l - 1);
            Matrix& rightWeights = this->weights.at(l);
            Matrix& rightGradients = this->gradients.at(l);

            for (int i = 0; i < leftGradients.getCols(); i++)
            {
                Matrix gradientRow = Matrix::fromVector(rightGradients.getRow(0));
                Matrix weightRow = Matrix::fromVector(rightWeights.getRow(i));

                Matrix product = gradientRow.multiply(weightRow.transpose());

                Neuron currentNeuron = this->layers.at(l).getNeurons().at(i);

                leftGradients.setValue(0, i, product.getValue(0, 0) * currentNeuron.getDerivedValue());
            }

            Matrix& leftDeltas = this->deltas.at(l - 1);

            leftDeltas = leftGradients
                             .transpose()
                             .multiply(l == 1 ? Matrix::fromVector(this->input) : this->layers.at(l).getDerivedNeuronMatrix())
                             .transpose();

            for (int i = 0; i < leftWeights.getRows(); i++)
            {
                for (int j = 0; j < leftWeights.getCols(); j++)
                {
                    double previousWeight = leftWeights.getValue(i, j);
                    double deltaWeight = leftDeltas.getValue(0, j);

                    leftWeights.setValue(i, j, previousWeight - deltaWeight);
                }
            }
        }
    }
}

void Network::calculateError()
{
    this->errors.clear();
    this->globalError = 0;

    Layer outputLayer = this->layers.at(this->layers.size() - 1);

    for (int i = 0; i < outputLayer.getSize(); i++)
    {
        Neuron outputNeuron = outputLayer.getNeurons().at(i);

        double outputValue = outputNeuron.getActivatedValue();
        double expectedValue = this->target.at(i);

        double error = outputValue - expectedValue;

        this->errors.push_back(error);
        this->globalError += error;
    }

    this->historicalErrors.push_back(this->errors);
}

void Network::train(int epochs)
{
    for (int i = 0; i < epochs; i++)
    {
        string epochString = to_string(epochs);

        this->feedForward();
        this->calculateError();
        this->propagateBackwards();

        cout << "[ "
             << "\033[1;33m"
             << setw(epochString.length())
             << i + 1
             << "\033[0m"
             << " ] Global error: \033[31m"
             << this->globalError
             << "\033[0m"
             << endl;
    }

    cout << endl;
}

void Network::describe(int level)
{
    cout << "Network [\033[1;32m" << this->getId() << "\033[0m]" << endl;
    cout << "---" << endl;
    cout << "Topology: [ ";

    for (int size : this->topology)
    {
        cout << "\033[35m" << size << "\033[0m ";
    }

    cout << "]" << endl;
    cout << "Input:    [ ";

    for (int input : this->input)
    {
        cout << "\033[35m" << input << "\033[0m ";
    }

    cout << "]" << endl;
    cout << "Target:   [ ";

    for (int target : this->target)
    {
        cout << "\033[35m" << target << "\033[0m ";
    }

    cout << "]" << endl;
    cout << "Layers: [" << endl;

    for (int i = 0; i < this->depth; i++)
    {
        this->layers.at(i).describe(level + 1);

        if (i < this->depth - 1)
        {
            this->weights.at(i).describe(level + 1);
            this->gradients.at(i).describe(level + 1);
            this->deltas.at(i).describe(level + 1);
        }
    }

    cout << "]" << endl;
    cout << "Global error:  \033[35m" << this->globalError << "\033[0m" << endl;
    cout << "Output errors: [ ";

    for (double error : this->errors)
    {
        cout << "\033[35m" << error << "\033[0m ";
    }

    cout << "]" << endl;
    cout << endl;
}
