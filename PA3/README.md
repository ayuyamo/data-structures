# Minimum Spanning Tree (MST) Solver

This program finds the Minimum Spanning Tree (MST) of a given graph using Prim's Algorithm.

## Usage

1. Clone this repository to your local machine.
2. Compile the `MST.cpp` file using a C++ compiler. Run the following command in your terminal:
    ```bash
    g++ MST.cpp -o MST
    ```
3. Execute the compiled program by running the following command:
    ```bash
    ./MST
    ```
4. Follow the instructions to provide input for the graph.

## How to Provide Input

1. The program expects the graph in the form of an adjacency matrix.
2. Modify the `graph1` array in the `main.cpp` file to represent your graph.
3. The size of the matrix should be `N x N`, where `N` is the number of vertices.
4. The value `0` represents no edge between vertices.
5. Compile and run the program after providing the input.

## Example

Consider the following graph:

```
    0 - 3
   / \
  3 - 1 - 4
       |
       2
```

The corresponding adjacency matrix in the `main.cpp` file would be:

```cpp
int graph1[N][N] =
    {     // 0   1   2   3   4
      /*0*/ { 0, 3, 65, 0, 0 },
      /*1*/ { 3, 0, 85, 20, 45 },
      /*2*/ { 65, 85, 0, 41, 77 },
      /*3*/ { 0, 20, 41, 0, 51 },
      /*4*/ { 0, 45, 77, 51, 0 },
    };
```

