#ifndef _IRIS_HPP_
#define _IRIS_HPP_

#include <iostream>
#include <vector>

using namespace std;

namespace iris {
    string generateId();
    
    class Neuron {
    private:
        string id; 
        
        double rawValue;
        double activatedValue;
        double derivedValue;
    public:
        Neuron(double value);

        void activate();
        void derive();
        
        string getId();
 
        double getRawValue();
        double getActivatedValue();
        double getDerivedValue();

        void setValue(double value);    
    
        void describe();
    };
    
    class Layer {
    private:
        string id;

        int size;
        vector<Neuron *> neurons;
    public:
        Layer(int size);
    
        string getId();

        vector<Neuron *> getNeurons();
        
        void describe();
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
 
        double getCols();
        double getRows(); 
        double getValue(int row, int col);
        
        void setValue(int row, int col, double value);     
        
        void transpose();
        
        void describe();
    };
        

    class Network {
    private:
        string id; 
        
        vector<int> topology;
        vector<double> input;
        vector<Layer *> layers; 
        vector<Matrix *> weights; 
    public:
        Network(vector<int> topology);
    
        string getId();
 
        vector<Layer *> getLayers();
        
        void setInput(vector<double> input);
        
        void describe();
    };
}

#endif
