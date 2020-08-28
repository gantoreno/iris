# Iris: A C++ Neural Network Engine

Iris is an experimental neural network engine, built from scratch with C++.

## Usage

To create a network and view its architecture, use the example code below and place it inside `src/main.cpp`:

-   `Network` is the neural network engine.
-   `{3, 2, 3}` is the topology vector, defines each layer for the neural network.
-   `setInput()` adds the input to the network, where `{0, 1, 3}` is the input vector.
-   `setTarget()` sets the expected output, where `{3, 2, 4}` is the output vector.
-   `feedForward()` executes a single feed-forward action to process the input.
-   `describe()` prints every layer and every neuron inside the network, exposing its information, including inputs, topology, outputs, and the errors.

```cpp
#include "../include/iris.hpp"

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({3, 2, 3});

    inet.setInput({0, 1, 3});
    inet.setTarget({3, 2, 4});
    inet.feedForward();
    inet.describe();

    return 0;
}
```

To build and run the project, use CMake:

```sh
$ cmake .
$ make
$ ./out/iris
```
