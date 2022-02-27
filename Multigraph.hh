#ifndef MULTIGRAPH_HH
#define MULTIGRAPH_HH

#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
using namespace std;

//nodes are supposed to be just integers

class Multigraph{
    public: 
        Multigraph(const int n);

        void addEdge(int source, int destination);
        vector<vector<complex<double> > > getLineGraph();


        int getNodesCount() const { return nodesCount; }
        float hadamardCoefficient (int size, int row, int column);
        complex<double> dftCoefficient (int size, int row, int column);

    private: 


        vector<vector<vector<int> > > adjacency; // a matrix nodes x nodes where every element is a list of edges (the edge has just a label)
        vector<int> degree;  //in degree + out degree
        int nodesCount;
        int edgesCount;

         
};

#endif