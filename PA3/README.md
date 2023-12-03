## Author name: Halie Do

1. A Minimum Spanning Tree (MST) is a connected & undirected graph created from a set of edges that connect all the vertices together with minimum total weights and without cycles.

2. A real world aplication for MST is help minimizing the total length of connections when planning the layout of fiber optic cables or constructing computer networks (and ensuring every node/device is connected with the least effort). 
- *Other applications:* robot paths (planning shortest & most efficient robot paths), designing circuits (figuring out the bets and most cost-effective pathways for electricity to flow through the circuit), water supply network (helps figure out the best pipes layout to minimize the cost and ensure every location is accessible through the network).

3. The new graph matrix I hardcorded:
```
    int graph1[N][N] = 
        {      //  0   1   2   3   4   5
            /*0*/ {0, 11, 0, 33, 0, 32},      
            /*1*/ {11, 0, 0, 0, 7, 0},
            /*2*/ {0, 0, 0, 0, 0, 25},
            /*3*/ {33, 0, 0, 0, 24, 0},
            /*4*/ {0, 7, 0, 24, 0, 16},
            /*5*/ {32, 0, 25, 0, 16, 0},
        };

```
4. 
- Yes. It has a unique minimum spanning tree for every start vertex. Start vertex --> minimum edge to next vertex --> find minimum edge between the previous vertex (most recently visited vertex) and the next vertex & compare the edge weights between every other visited vertex and this new vertex & pick the edge with least weight --> repeat the process until all nodes are visited.
- In the context of this program, parameters that point toward a unique MST are ones with no dulicate edge weights (otherwise it can lead to multiple MSTs)

