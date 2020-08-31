#ifndef _IRIS_HPP_
#define _IRIS_HPP_

#include <iostream>
#include <vector>

using namespace std;

namespace iris
{
    class Neuron
    {
    private:
        string id;

        double rawValue;
        double activatedValue;
        double derivedValue;

        bool isBiasNode;

        void activate();
        void derive();

    public:
        Neuron(double value, bool isBiasNode = false);

        string getId();

        double getRawValue();
        double getActivatedValue();
        double getDerivedValue();

        void setValue(double value);

        void describe(int level = 0);
    };

    class Matrix
    {
    private:
        string id;

        int rows;
        int cols;
        bool isRandom;

        vector<vector<double>> values;

    public:
        Matrix(int rows, int cols, bool isRandom);

        string getId();

        static Matrix fromVector(vector<double> v);

        Matrix multiply(Matrix m);
        Matrix transpose();

        vector<double> vectorize();

        double getCols();
        double getRows();
        double getValue(int row, int col);

        vector<double> getRow(int row);

        void setValue(int row, int col, double value);

        void describe(int level = 0);
    };

    class Layer
    {
    private:
        string id;

        int size;
        int biasedSize;

        bool isBiased;

        vector<Neuron> neurons;

    public:
        Layer(int size, bool isBiased = false);

        string getId();

        int getSize();
        int getBiasedSize();

        vector<Neuron> getNeurons();

        Matrix getNeuronMatrix();
        Matrix getActivatedNeuronMatrix();
        Matrix getDerivedNeuronMatrix();

        void setValues(vector<double> values);

        void describe(int level = 0);
    };

    class Network
    {
    private:
        string id;

        int depth;

        vector<int> topology;
        vector<Layer> layers;
        vector<Matrix> weights;
        vector<Matrix> gradients;
        vector<Matrix> deltas;

        vector<double> input;
        vector<double> target;
        vector<double> errors;

        double globalError;

        vector<vector<double>> historicalErrors;

        void calculateError();

        void feedForward();
        void propagateBackwards();

    public:
        Network(vector<Layer> layers);

        string getId();

        int getDepth();

        vector<int> getTopology();
        vector<Layer> getLayers();
        vector<Matrix> getWeights();
        vector<Matrix> getGradients();
        vector<Matrix> getDeltas();

        void setInput(vector<double> input);
        void setTarget(vector<double> target);

        void train(int epochs);

        void describe(int level = 0);
    };

    class Utils
    {
    private:
    public:
        static string generateId();
        static string generateIndentation(int level);
        static double generateRandomNumber();
    };
} // namespace iris

#endif
