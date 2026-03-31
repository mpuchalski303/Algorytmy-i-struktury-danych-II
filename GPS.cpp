#include<iostream>
#include<vector>
/*
Po rozmowie z księciem okazało się, że jego ukochana bardzo dużo czasu spędza w kuchni,
nadzorując gotowanie owsianki dla wygłodniałych brodaczy. Ilość potrzebnej owsianki zwiększa się, gdy krasnoludki muszą pokonać większą odległość z domu do pracy (można przyjąć,
że jest to jedyny czynnik). Książę, chcąc ulżyć swojej wybrance, zmierzył i spisał odległości,
pomiędzy każdym z wyrobisk i domkiem każdego z krasnoludków. Prosi, abyś uwzględnił te
informacje. Przy podziale pracy chciałby, aby sumaryczna odległość, którą każdego dnia muszą pokonać krasnoludki była możliwie jak najmniejsza, przy czym nie możemy pozwolić, żeby
spadła wartość produkowanych dóbr.
*/

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
    vector<vector<int>> odleglosci(6, vector<int>(6,0));

    int wynik;
    int glebia =0;
    int suma;
    int poczatek = 0;
    int koniec = 5;
    int min = 9999;
    

    tablica_sasiedztwa[0] = {1};
    tablica_sasiedztwa[1] = {2,3};
    tablica_sasiedztwa[2] = {4};
    tablica_sasiedztwa[3] = {4};
    tablica_sasiedztwa[4] = {5};
    tablica_sasiedztwa[5] = {};
    
    odleglosci[0][1] = 200;
    odleglosci[1][2] = 60;
    odleglosci[2][4] = 200;
    odleglosci[1][3] = 100;
    odleglosci[3][4] = 100;
    odleglosci[4][5] = 500;

    
    dfs(poczatek,glebia, tablica_sasiedztwa, odwiedzone, sciezki, odp, koniec);
    
    for(int i = 0;i<odp.size();i++){
        suma = 0;
        for(int j= 0;j<odp[i].size();j++){
            if(j + 1 != odp[i].size()){
                suma += odleglosci[odp[i][j]][odp[i][j+1]];
                
            }
            
        }
        if(suma < min){
            min = suma;
            wynik = i;
        }
        
    }
    
    cout<<"Najkrotsza droga to: ";
    
    for(int i= 0;i<odp[wynik].size();i++){
        cout<<odp[wynik][i]<<" ";
    }
    cout<<endl;
    cout<<"Odleglosc to: "<<min;
    
    
    return 0;
}