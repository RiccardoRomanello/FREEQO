#pragma once

// #include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <complex>
// using namespace std;

//nodes are supposed to be just integers

class Multigraph {
    using NodeLabel = int;
    using AdjList = std::vector<std::vector<NodeLabel>>;
    struct Edge {
        NodeLabel source, target;
    };


    public:
        Multigraph(size_t n=0) 
        : nodesCount(n), adjacency(n), in_degree(n,0), out_degree(n,0) { }


        size_t Indegree(const NodeLabel u) const { return in_degree[u]; }
        size_t Outdegree(const NodeLabel u) const { return out_degree[u]; }
        size_t Balance(const NodeLabel u) const { return Outdegree(u) - Indegree(u); }
        size_t Multiplicity(const Edge & uv) const { return multiplicity.contains(uv) ? multiplicity.at(uv) : 0; }

        size_t NodesCount() const { return nodesCount; }
        size_t EdgesCount() const { return edgesCount; }



        std::map<Edge, size_t> Balance() {}



        void AddEdge(NodeLabel, NodeLabel);
        // vector<vector<complex<double> > > getLineGraph();

    private: 
        
        size_t nodesCount;
        size_t edgesCount;

        AdjList adjacency;                              // adj list
        std::map<Edge,size_t> multiplicity;             // from (u, v) to multiplicity
        std::vector<size_t> in_degree;                  // in_degree of a node
        std::vector<size_t> out_degree;                 // out_degree of a node
};