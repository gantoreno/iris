#include <random>
#include <iomanip>
#include <vector>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

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
    Matrix transposed = Matrix(this->cols, this->rows, false);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            transposed.setValue(j, i, this->getValue(i, j));
        }
    }

    return transposed;
}

Matrix Matrix::fromVector(vector<double> v) {
    Matrix m = Matrix(1, v.size(), false);

    for (int i = 0; i < v.size(); i++) {
        m.setValue(0, i, v.at(i));
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

vector<double> iris::Matrix::getRow(int row) {
    return this->values.at(row);
}

void Matrix::describe(int level) { 
    string tabs = Utils::generateIndentation(level);
    
    cout << tabs << "Matrix [\033[1;32m" << this->id << "\033[0m]" << endl;
    cout << tabs << "---" << endl;
    cout << tabs << "Rows:    \033[35m" << this->rows << "\033[0m" << endl;
    cout << tabs << "Columns: \033[35m" << this->cols << "\033[0m" << endl;
    
    for (int i = 0; i <  this->rows; i++) {  
        cout << tabs << "[ ";
        
        for (int j = 0; j < this->cols; j++) {
            cout << "\033[33m" 
                 << fixed 
                 << right 
                 << setw(5) 
                 << setprecision(4) 
                 << this->values.at(i).at(j) 
                 << defaultfloat 
                 << " ";    
        }

        cout << "\033[0m]" << endl;
    } 

    cout << endl;    
}
