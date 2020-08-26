# Iris: C++ Neural Network Engine

Iris is an experimental neural network engine, built with C++.

## Usage

To create a network and view its architecture, use the example code below and place it inside `src/main.cpp`:

```cpp
#include <iostream>
#include "../include/iris.h"

int main(int argc, char **argv) {
    iris::Network *n = new iris::Network({3, 2, 3});

    iris.describe();

    return 0;
}
```

To run the project, use CMake:

```sh
$ cmake .
$ make
$ ./out/iris
``` 
