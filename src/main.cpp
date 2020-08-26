#include "../include/iris.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    iris::Network *n = new iris::Network({3, 2, 3});
    n->setInput({1, 1, 0}); 
    n->describe();

    return 0;
}
