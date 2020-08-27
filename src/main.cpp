#include <iostream>
#include "../include/iris/iris.hpp"

using namespace std;

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({3, 2, 3});
    
    inet.describe();

    return 0;
}
