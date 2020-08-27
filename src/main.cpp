#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network *inet = new iris::Network({3, 2, 3});

    inet->setInput({3, 4, 2});
    inet->feedForward();
    inet->describe();

    return 0;
}
