#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network *inet = new iris::Network({3, 2, 1});

    inet->setInput({1, 0, 1});
    inet->feedForward();
    inet->describe();

    return 0;
}
