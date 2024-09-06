# Round-Trip-Time-with-Dijkstra

This repository contains the implementation of **Trabalho 2** from the **Técnicas de Busca e Ordenação** course. The project's objective was to develop a system to solve problems related to *Round Trip Time (RTT)*, using the C programming language and graph concepts.

## Project Description

This assignment simplifies the process of monitoring internet traffic status. The goal of this monitoring is to estimate the time a data packet needs to leave a server, reach the client’s access network (or the client itself), and confirm its arrival back to the server. This time is called *Round Trip Time (RTT)*. In this simplified version, it is assumed that the network of computers/devices is a graph containing nodes:

- *S* (servers);
- *C* (clients);
- *M* (monitors).

Given *a* and *b* as graph nodes and *δ(a, b)* as the cost of the shortest path from node *a* to node *b*, *RTT(a,b)* is defined as *δ(a, b) + δ(b, a)*.

Now, considering the subsets *S, C and M* of graph vertices, the estimated *RTT\** is defined as *RTT\**(a, b) = min(RTT(m, b) + RTT(m, b)), where m ∈ M.

The project was developed using the C programming language and the Dijkstra algorithm to calculate the Shortest Paths between graph nodes.



## Features

- Use Dijkstra's algorithm to calculate the shortest paths from all nodes in 𝑆  to all nodes in 𝐶 and from all nodes in 𝐶 to all nodes in 𝑆. With this, the actual RTTs between all servers and clients can be calculated.

- Use Dijkstra's algorithm to calculate the shortest paths from all nodes in 𝑆 to all nodes in 𝑀 (and vice versa) and from all nodes in 𝑀 to all nodes in 𝐶 (and vice versa). With these values, the approximate RTT values (i.e., *RTT\**) can be calculated for all nodes in S to all nodes in C.

- For each pair 𝑎, 𝑏 with  𝑎 ∈ 𝑆 and 𝑏 ∈ 𝐶, calculate the inflation of the RTT when replacing 𝑅𝑇𝑇(𝑎,𝑏) with  𝑅𝑇𝑇∗(𝑎,𝑏), which is given by (𝑅𝑇𝑇∗(𝑎,𝑏) / 𝑅𝑇𝑇(𝑎,𝑏)).


## How to Run

### Compilation

To compile the project, use the following command:

```bash
make
```

### Execution
To run the program with an input file and generate a solution, use the following command:
```bash
make run
```

## Dependencies

- GCC (GNU Compiler Collection)
