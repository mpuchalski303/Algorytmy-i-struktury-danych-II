#include<iostream>
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

int main(){

    galaz* root = nullptr;
    root = InsertBST(root, 5);
    
    InsertBST(root, 2);
    InsertBST(root, 8);
    InsertBST(root, 1);
    InsertBST(root, 4);
    InsertBST(root, 6);
    InsertBST(root, 9);
    wyswielt(root);
    return 0;
}