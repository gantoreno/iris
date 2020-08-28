#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({
        iris::Layer(3),
        iris::Layer(2),
        iris::Layer(3)
    });

    inet.setInput({1, 0, 1});
    inet.setTarget({1, 0, 1});
    inet.feedForward();
    inet.describe();
    
    return 0;
}
