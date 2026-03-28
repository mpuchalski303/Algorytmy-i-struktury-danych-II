/*

1. Zaimplementuj BST z operacjami insert, find, delete, znajdującymi wartość maksymalną i
minimalną

a. Oblicz sumę k-najmniejszych elementów w drzewie.
b. Połącz dwa drzewa tak, żeby wynikowe drzewo było dalej poprawnym drzewem BST. 

*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


struct galaz{
    int wartosc;
    galaz* lewy;
    galaz* prawy;

};
galaz* StworzBST(int a){
    galaz* nowa_galaz = new galaz();
    nowa_galaz->wartosc = a;
    nowa_galaz->lewy = nullptr;
    nowa_galaz->prawy = nullptr;
    return nowa_galaz;
};
galaz* InsertBST(galaz* root,int a){
    if(root == nullptr){
        return StworzBST(a);
    }
    if(a > root->wartosc){
        root->prawy = InsertBST(root->prawy, a);
    }
    else{
        root->lewy =  InsertBST(root->lewy, a);
    }
    return root;
}
void wyswielt(galaz* root){
    if(root != nullptr){
        wyswielt(root->lewy);
        cout<<root->wartosc<<" ";
        wyswielt(root->prawy);

    }
}
void maks(galaz* root){
    if(root->prawy == nullptr){
        cout<<"MAX: "<<root->wartosc<<endl;
    }
    else{
        maks(root->prawy);
    }
}
void min(galaz* root){
    if(root->lewy == nullptr){
        cout<<"MIN: "<<root->wartosc<<endl;
    }
    else{
        min(root->lewy);
    }
}

void FindBST(galaz* root,int szukana){//zakladamy ze wiemy ze sie znajduje ta wartosc
    int iter = 1;

    while(root->wartosc != szukana){
        if(root->wartosc < szukana){
            root = root->prawy;
            iter++;
        }
        else{
            root = root->lewy;
            iter++;
        }
    }
    cout<<"Glebokosc:"<<iter<<endl;
    

}
galaz* FindBST2(galaz* root,int szukana){
    int iter = 1;

    while(root->wartosc != szukana){
        if(root->wartosc < szukana){
            root = root->prawy;
            iter++;
        }
        else{
            root = root->lewy;
            iter++;
        }
    }
    return root;
    

}
galaz* delateBST(galaz* root, int do_usuniecia){//zakladamy ze usuwamy liscie drzewa

    
        if(root->prawy->wartosc == do_usuniecia){
            root->prawy = nullptr;
            return root;
        }
        if(root->lewy->wartosc == do_usuniecia){
            root->lewy = nullptr;
            return root;
        }
        if(root->wartosc < do_usuniecia){

            delateBST(root->prawy, do_usuniecia);
            
        }
        else{
            delateBST(root->lewy, do_usuniecia);
            
        }
    
    return root;
    
    
}
void stworz_wektor(galaz* root, vector<int> &wektor){
    if(root != nullptr){
        stworz_wektor(root->lewy, wektor);
        wektor.push_back(root->wartosc);
        stworz_wektor(root->prawy, wektor);

    }
}

int SumaNajmniejszychElementow(galaz* root, int k){
    vector<int> wektor;
    int suma=0;
    stworz_wektor(root,wektor);

    
    sort(wektor.begin(), wektor.end());
    for(int i =0; i<k;i++){
        
        suma += wektor[i];
    }
    return suma;
}
galaz* Polacz_2_BST(galaz* root1, galaz* root2){
    vector<int> wektor1;
    vector<int> wektor2;
    
    galaz* root_wynik = new galaz();

    stworz_wektor(root1, wektor1);
    stworz_wektor(root2, wektor2);

    for(int i =0; i<wektor1.size(); i++){
        InsertBST(root_wynik, wektor1[i]);
    }
    for(int i =0; i<wektor2.size(); i++){
        InsertBST(root_wynik, wektor2[i]);
    }
    return root_wynik;
}
int main(){

    galaz* root = nullptr;
    galaz* root2 = nullptr;

    root = InsertBST(root, 5);
    root2 = InsertBST(root2, 2);   

    InsertBST(root2, 4);
    InsertBST(root2, 6);
    InsertBST(root2, 9);
    InsertBST(root, 8);
    InsertBST(root, 1);

    

    wyswielt(root);
    cout<<endl;

    wyswielt(root2);
    cout<<endl;

    //maks(root);
    //min(root);

    //FindBST(root,2);
    //wyswielt(FindBST2(root, 8));

    //wyswielt(delateBST(root, 6));

    //cout<<"Suma: "<< SumaNajmniejszychElementow(root, 3);
    wyswielt(Polacz_2_BST(root, root2));
    return 0;
}