#include <random>
#include <sstream>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

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

string Utils::generateIndentation(int level) {
    stringstream tabStream;

    for (int i = 0; i < level; i++) {
        tabStream << "\t";
    }

    return tabStream.str();
}

double Utils::generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    return dis(gen);
}
