# Iris: A C++ Neural Network Engine

Iris is an experimental neural network engine, built from scratch with C++.

## Usage

To try the iris engine, create a `main.cpp` file in the root directory, then use the example code below by placing it inside:

```cpp
#include "include/iris.hpp"

using namespace iris;

int main(int argc, char** argv)
{
    Network inet = Network({ Layer(3),
                             Layer(2),
                             Layer(3) });

    inet.setInput({ 1, 0, 1 });
    inet.setTarget({ 1, 0, 1 });

    inet.train(100);

    inet.describe();

    return 0;
}
```

Where:

-   `Network` is the neural network engine, the constructor receives a vector of `Layer`.
-   `Layer` specifies a new layer, where `3`, `2` and `3` are the amount of neurons inside each layer.
-   `setInput()` adds the input to the network, where `{0, 1, 3}` is the input vector.
-   `setTarget()` sets the expected output, where `{3, 2, 4}` is the output vector.
-   `train()` starts the training process, where `100` are the epochs, information will be displayed over each epoch showing the global error.
-   `describe()` prints every layer and every neuron inside the network, exposing its information, including inputs, topology, outputs, and the errors.

To build and run the project, use CMake:

```sh
$ cmake .
$ make
$ ./out/iris
```

## License

The Iris engine is distributed under the [Apache 2.0 License](https://github.com/hollandsgabe/iris/blob/master/LICENSE.md).
