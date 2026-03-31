#include<iostream>
#include<vector>


using namespace std;

void dfs(int v, int glebia,vector<vector<int>> &tablica_sasiedztwa,  vector<bool> &odwiedzone, vector<int> &sciezki,vector<vector<int>> &odp, int koniec){
    odwiedzone[v] = true;
    sciezki.push_back(v);

    if(sciezki[sciezki.size() - 1] == koniec){
        odp.push_back(sciezki);
    }

    for(int sasiad : tablica_sasiedztwa[v]){
        if(odwiedzone[sasiad] == false){

            dfs(sasiad, glebia, tablica_sasiedztwa, odwiedzone, sciezki,odp,koniec);
            
        }
    }
    sciezki.pop_back();
    odwiedzone[v] = false;
}


int main(){

    vector<vector<int>> tablica_sasiedztwa(6);
    vector<bool> odwiedzone(6, false);
    vector<int> sciezki;
    vector<vector<int>> odp;

    int glebia =0;
    tablica_sasiedztwa[0] = {1, 2};
    tablica_sasiedztwa[1] = {2, 3};
    tablica_sasiedztwa[2] = {4};
    tablica_sasiedztwa[3] = {4};
    tablica_sasiedztwa[4] = {5};
    tablica_sasiedztwa[5] = {};
    
    int poczatek = 0;
    int koniec = 5;
    dfs(poczatek,glebia, tablica_sasiedztwa, odwiedzone, sciezki, odp, koniec);

    for(int i = 0;i<odp.size();i++){
        for(int j= 0;j<odp[i].size();j++){
            cout<<odp[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}