#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector <int>> &lisa_sasiedzta,  vector<bool> &odwiedzone,vector<int> &odp, int glebia){
    glebia+= 1;
    odwiedzone[v] = true; 
    odp[v] = glebia;
    
    for(int sasiad : lisa_sasiedzta[v]){
        
        if(odwiedzone[sasiad] == false){
            
            dfs(sasiad, lisa_sasiedzta, odwiedzone, odp, glebia);
        }
    }
    
}

int main(){
    vector<vector <int>> lisa_sasiedzta(6);
    vector<bool> odwiedzone(6, false);
    vector<int> odp(6,0);

    int glebia =0;
    int maks = 0;
    string wynik="";

    lisa_sasiedzta[0] = {1, 2};
    lisa_sasiedzta[1] = {4};
    lisa_sasiedzta[2] = {3};
    lisa_sasiedzta[3] = {5};
    lisa_sasiedzta[4] = {};
    lisa_sasiedzta[5] = {};

    dfs(0, lisa_sasiedzta, odwiedzone, odp, glebia);
    for(int i = 0;i<6;i++){
        if(odp[i] > maks){
            maks = odp[i];
            wynik = to_string(i) + " Odleglosc: " + to_string(odp[i]- 1);
        }
    }
    cout<<"Najdalszy wierzcholek to: " + wynik;
}