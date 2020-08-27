#ifndef _IRIS_HPP_
#define _IRIS_HPP_

#include <iostream>
#include <vector>

using namespace std;

namespace iris {
    class Neuron {
    private:
        string id;
        
        double rawValue;
        double activatedValue;
        double derivedValue;

        void activate();
        void derive();
    public:
        Neuron(double value);
        
        string getId();
 
        double getRawValue();
        double getActivatedValue();
        double getDerivedValue();

        void setValue(double value);    
    
        void describe(int level = 0);
    };
    
    class Matrix {
    private:
        string id; 
        
        int rows;
        int cols;
        bool isRandom;
        
        vector<vector<double>> values;
    public:
        Matrix(int rows, int cols, bool isRandom);
        
        string getId();
 
        Matrix multiply(Matrix m);
        Matrix transpose();
       
        vector<double> vectorize();

        double getCols();
        double getRows(); 
        double getValue(int row, int col);
        
        void setValue(int row, int col, double value);     
        
        void describe(int level = 0);
    };

    class Layer {
    private:
        string id;
        
        int size;
        
        vector<Neuron> neurons;
    public:
        Layer(int size);
    
        string getId();
        
        int getSize();
        
        vector<Neuron> getNeurons();
    
        Matrix getNeuronMatrix();
        Matrix getActivatedNeuronMatrix();
        Matrix getDerivedNeuronMatrix();
    
        void setValues(vector<double> values);
     
        void describe(int level = 0);
    };

    class Network {
    private:
        string id; 
       
        int depth; 
        
        vector<int> topology;
        vector<double> input;
        vector<Layer> layers; 
        vector<Matrix> weights; 
    public:
        Network(vector<int> topology);
    
        string getId();

        int getDepth();
        
        vector<int> getTopology();
        vector<Layer> getLayers();
        vector<Matrix> getWeights();

        void setInput(vector<double> input);
       
        void feedForward();        

        void describe(int level = 0);
    };

    class Utils {
    private:
    public:
        static string generateId();
        static double generateRandomNumber();
    };
}

#endif
