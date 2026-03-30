#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector <int>> &lisa_sasiedzta,  vector<bool> &odwiedzone){
    
    odwiedzone[v] = true; 

    for(int sasiad : lisa_sasiedzta[v]){
        if(odwiedzone[sasiad] == false){
            cout<<"1 ";
            dfs(sasiad, lisa_sasiedzta, odwiedzone);
        }
    }
    
}

int main(){
    vector<vector <int>> lisa_sasiedzta(6);
    vector<bool> odwiedzone(6, false);
    int krawedzie = 5;
    int wierzcholki = 6;
    lisa_sasiedzta[0] = {1, 2};
    lisa_sasiedzta[1] = {3, 4};
    lisa_sasiedzta[2] = {0, 5};
    lisa_sasiedzta[3] = {};
    lisa_sasiedzta[4] = {};
    lisa_sasiedzta[5] = {};
    dfs(0, lisa_sasiedzta, odwiedzone);
}