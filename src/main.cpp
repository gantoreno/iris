#include <iostream>
#include "../include/iris.hpp"

using namespace std;
using namespace iris;

int main(int argc, char **argv) {
    Network *n = new Network({3, 2, 3});

    n->setInput({1, 0, 2});
    n->describe();

    return 0;
}
