#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({3, 2, 3});

    inet.setInput({1, 0, 1});
    inet.setTarget({1, 0, 1});
    inet.feedForward();
    inet.describe();
    
    return 0;
}
