#include <iostream>
#include <ctime>
#include <cstdlib>
#include "libs/sort.h"

using namespace std;

#define qshow view_show(vet, {C, F, i, j}, "rgby")

void merge(vector<int>& vet, int a, int b, int c){
    int i = a;
    int j = b;
    vector<int> vaux;
    vaux.reserve(c - a);
    while((i < b) && (j < c)){
        if(vet[i] < vet[j])
            vaux.push_back(vet[i++]);
        else
            vaux.push_back(vet[j++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    while(i < b){
        vaux.push_back(vet[i++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    while(j < c){
        vaux.push_back(vet[j++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    for(int i = 0; i < (int) vaux.size(); i++){
        vet[a + i] = vaux[i];
        view_show(vet, {a + i}, "r");
    }
}

void mergesort(vector<int>& vet, int a, int c){
    if(c == a + 1)
        return;
    int b = (a + c)/2;
    mergesort(vet, a, b);
    mergesort(vet, b, c);
    merge(vet, a, b, c);
}

void test_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        if(vet[i] <= vet[i + 1])
            view_show(vet, {i, i + 1}, "gg");
        else{
            view_show(vet, {i, i + 1}, "rr");
            view_lock();
        }
    }
}

int main(){
    srand(time(NULL));

    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

    view_set_dot();
    view_set_faixa(0, qtd - 1);

    mergesort(vet, 0, vet.size());

    test_sort(vet);
    view_lock();
    return 0;
}