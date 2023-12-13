#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isIdenticals(Node* r1,Node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if(r1 == NULL && r2 != NULL){
        return false;
    }

    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdenticals(r1->right,r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    return 0;
}