#include "Multigraph.hh"

#include <math.h>
#include <assert.h>
#include <bitset>
#include <complex>
#include <cmath> 

Multigraph::Multigraph(const int n) : adjacency(n, vector<vector<int> >(n, vector<int>(0))),
degree(n, 0) {
    nodesCount = n;
    edgesCount = 0;
}

void Multigraph::addEdge(int source, int dest) {
    if(source < nodesCount && dest < nodesCount){
        adjacency[source][dest].push_back(edgesCount);
        edgesCount++;
        degree[source] += 1;
        degree[dest] += 1;
    }
}

vector<vector<complex<double> > > Multigraph::getLineGraph() {
    vector<vector<complex<double> > > lineGraphAdjacency(edgesCount, vector<complex<double> >(edgesCount, complex<double>(0, 0)));

    vector<vector<int> > rowsEquals(nodesCount, vector<int>(0)); //indexes of all rows of lineGraphAdjacency which are equals because they are all about edge inciding in j.

    for(int j = 0; j < nodesCount; j++){ // fixed a j as 'middle node', I will handle all equal rows (since all edges will be incident in j)
                                         // until I change to j+1.
        for(int i = 0; i < nodesCount; i++){
            vector<int> edgesFromItoJ = adjacency[i][j]; //edges ENTERING in j from i 

            for(int k = 0; k < edgesFromItoJ.size(); k++){ // for each edge entering in j from i 
                rowsEquals[j].push_back(edgesFromItoJ[k]);
                for(int w = 0; w < nodesCount; w++){
                    vector<int> edgesFromJtoW = adjacency[j][w]; //edges EXITING from j going to w
                    for(int m = 0; m < edgesFromJtoW.size(); m++){
                        lineGraphAdjacency[edgesFromItoJ[k]][edgesFromJtoW[m]] = complex<double>(1,0);
                    }
                }
            }
        }
        sort(rowsEquals[j].begin(), rowsEquals[j].end());
    }

    for(int i = 0; i < nodesCount; i++){
        vector<int> sameRowsInducedByI = rowsEquals[i];
        int size = sameRowsInducedByI.size();
        int hadamardColumn = 0; 
        for(int j = 0; j < size; j++){ // for each edge inside sameRowsInducedByI
            int currentEdge = sameRowsInducedByI[j];
            for(int k = 0; k < edgesCount; k++){
                if(lineGraphAdjacency[currentEdge][k] == complex<double>(1, 0)){
                    lineGraphAdjacency[currentEdge][k] = dftCoefficient(size, j, hadamardColumn);
                    hadamardColumn++;
                }
            }
        }
    }


    return lineGraphAdjacency;
}

float Multigraph::hadamardCoefficient (int size, int row, int column){
    
    bitset<8> rowBiset(row);
    bitset<8> columnBiset(column); 

    int result = 0;

    for(int i = 0; i < 8; i++){
        int currentDigit = ((int)rowBiset[i]) * ((int)columnBiset[i]);
        result += currentDigit;
    }
    
    return 1/pow(2,(log2(size)/2)) * pow(-1, result);
}

complex<double> Multigraph::dftCoefficient (int size, int row, int column){
    
    complex<double> omega(cos((2 * M_PI * row*column)/size), sin((2 * M_PI * row*column)/size));
    return 1/pow(2,(log2(size)/2)) * omega;
}