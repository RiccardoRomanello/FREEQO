#include <iostream>
#include <vector>
#include "Multigraph.hh"

using namespace std;

void printAsMatrix(vector<vector<complex<double> > > M){
    cout << "[";
    for(int i = 0; i < M.size(); i++){
        cout << "[";
        for(int j = 0; j < M[i].size(); j++){
            if(abs(M[i][j].real()) < 1e-16){
                cout << "0.0"; 
            }else{
                cout << M[i][j].real();
            }

            if(abs(M[i][j].imag()) < 1e-15){
                cout << " + 0.0j";
            }else{
                if(M[i][j].imag() >= 0){
                    cout << " + ";
                }
                cout << M[i][j].imag() << "j";
            }
            if(j < M[i].size() - 1){
                cout << ", ";
            }
        }
        cout <<"]";
        if(i < M.size() - 1){
            cout << ", " << endl;
        }
    }
    cout << "]" << endl;
}

int main(){
    Multigraph g(5);
    
    // C4 
    g.addEdge(0, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 0);
    
    
    printAsMatrix(g.getLineGraph());
}
