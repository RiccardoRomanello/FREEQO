#include "Multigraph.hh"

#include <math.h>
#include <assert.h>
#include <bitset>
#include <complex>
#include <cmath>
#include <queue>

namespace farquaad {


void Multigraph::AddEdge(NodeLabel source, NodeLabel target) {
    assert(source < (NodeLabel) nodesCount and target < (NodeLabel) nodesCount);
    
    if(Multiplicity({source, target}) == 0)
        adjacency[source].emplace_back(target);

    ++edgesCount;
    ++in_degree[target];
    ++out_degree[source];
    ++multiplicity[{source, target}];
}



std::map<Multigraph::Edge, size_t> Multigraph::Eulerify() {
    std::queue<NodeLabel> B_plus, B_minus;

    // Retrieve surplus and deficient nodes
    for(NodeLabel u=0; u<(NodeLabel) NodesCount(); ++u) {
        if(Balance(u) > 0)
            B_plus.emplace(u);
        else if(Balance(u) < 0)
            B_minus.emplace(u);
    }

    std::map<Edge, size_t> E_bottom;

    while(not B_minus.empty()) {
        auto u = B_minus.front();
        B_minus.pop();

        assert(not B_plus.empty());

        auto v = B_plus.front();
        assert(Balance(v) > 0);

        while(Balance(u) < 0) {
            assert(Balance(u) < 0 and Balance(v) > 0);
            
            AddEdge(u, v);
            ++E_bottom[{u, v}];

            if(Balance(v) == 0) {
                B_plus.pop();
                if(not B_plus.empty())
                    v = B_plus.front();
            }
        }
    }

    return E_bottom;
}


} // farquaad




// vector<vector<complex<double> > > Multigraph::getLineGraph() {
//     vector<vector<complex<double> > > lineGraphAdjacency(edgesCount, vector<complex<double> >(edgesCount, complex<double>(0, 0)));

//     vector<vector<int> > rowsEquals(nodesCount, vector<int>(0)); //indexes of all rows of lineGraphAdjacency which are equals because they are all about edge inciding in j.

//     for(int j = 0; j < nodesCount; j++){ // fixed a j as 'middle node', I will handle all equal rows (since all edges will be incident in j)
//                                          // until I change to j+1.
//         for(int i = 0; i < nodesCount; i++){
//             vector<int> edgesFromItoJ = adjacency[i][j]; //edges ENTERING in j from i 

//             for(int k = 0; k < edgesFromItoJ.size(); k++){ // for each edge entering in j from i 
//                 rowsEquals[j].push_back(edgesFromItoJ[k]);
//                 for(int w = 0; w < nodesCount; w++){
//                     vector<int> edgesFromJtoW = adjacency[j][w]; //edges EXITING from j going to w
//                     for(int m = 0; m < edgesFromJtoW.size(); m++){
//                         lineGraphAdjacency[edgesFromItoJ[k]][edgesFromJtoW[m]] = complex<double>(1,0);
//                     }
//                 }
//             }
//         }
//         sort(rowsEquals[j].begin(), rowsEquals[j].end());
//     }

//     for(int i = 0; i < nodesCount; i++){
//         vector<int> sameRowsInducedByI = rowsEquals[i];
//         int size = sameRowsInducedByI.size();
//         int hadamardColumn = 0; 
//         for(int j = 0; j < size; j++){ // for each edge inside sameRowsInducedByI
//             int currentEdge = sameRowsInducedByI[j];
//             for(int k = 0; k < edgesCount; k++){
//                 if(lineGraphAdjacency[currentEdge][k] == complex<double>(1, 0)){
//                     lineGraphAdjacency[currentEdge][k] = dftCoefficient(size, j, hadamardColumn);
//                     hadamardColumn++;
//                 }
//             }
//         }
//     }


//     return lineGraphAdjacency;
// }