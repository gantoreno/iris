#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({3, 2, 3});

    inet.setInput({0, 1, 3});
    inet.setTarget({3, 2, 4});
    inet.feedForward();
    inet.describe();
    
    return 0;
}
