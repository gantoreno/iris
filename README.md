# Iris: C++ Neural Network Engine

Iris is an experimental neural network engine, built with C++.

## Usage

To create a network and view its architecture, use the example code below and place it inside `src/main.cpp`:

- `iris::Network` is the  neural network engine.
- `{3, 2, 3}` is the topology vector, defines each layer for the neural network.
- `describe()` prints every layer and every neuron inside the network, exposing its information.

```cpp
#include "../include/iris/iris.h"

int main(int argc, char **argv) {
    iris::Network inet = iris::Network({3, 2, 3});

    inet.describe();

    return 0;
}
```

To run the project, use CMake:

```sh
$ cmake .
$ make
$ ./out/iris
``` 
