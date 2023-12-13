//Time Complexity : O(n2^n);
//Time Complexity: O(1);

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printPowerSet(char* set,int set_size){
    unsigned int pow_set_size = pow(2,set_size);
    int counter, j;

    for(counter = 0;counter<pow_set_size;counter++){
        for(j = 0;j < set_size;j++){
            if(counter & (1<<j)){
                cout<<set[j];
            }
        }
    }
}

int main(){
    char set[] = {'a','b','c'};
    printPowerSet(set,3);
    return 0;
}