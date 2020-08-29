# Iris: A C++ Neural Network Engine

Iris is an experimental neural network engine, built from scratch with C++.

## Usage

To try the iris engine, create a `main.cpp` file in the root directory, then use the example code below by placing it inside:

```cpp
#include "include/iris.hpp"

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
```

Where:

-   `Network` is the neural network engine, the constructor receives a vector of `iris::Layer`.
-   `iris::Layer` specifies a new layer, where `3`, `2` and `3` are the ammount of neurons inside each layer.
-   `setInput()` adds the input to the network, where `{0, 1, 3}` is the input vector.
-   `setTarget()` sets the expected output, where `{3, 2, 4}` is the output vector.
-   `feedForward()` executes a single feed-forward action to process the input.
-   `describe()` prints every layer and every neuron inside the network, exposing its information, including inputs, topology, outputs, and the errors.

To build and run the project, use CMake:

```sh
$ cmake .
$ make
$ ./out/iris
```
