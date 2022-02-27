#include <iostream>
#include <vector>
#include <assert.h>
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
    g.AddEdge(0, 0);
    g.AddEdge(0, 1);
    g.AddEdge(1, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
    g.AddEdge(3, 0);


    assert(g.Balance().empty());
}
