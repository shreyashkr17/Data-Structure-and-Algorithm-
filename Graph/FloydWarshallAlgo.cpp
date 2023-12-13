#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

// Multisource shortest path algorithm, also helps you in finding negative cycle
void shortestDistance(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i==j){
                matrix[i][j] = 0;
            }
        }
    }

    for(int k = 0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[j][k]);
            }
        }
    }

    for(int i =0;i<n;i++){
        if(matrix[i][i] < 0){
            cout<<"Negative cycle"<<endl;
            return;
        }
    }

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}

 
int main(){
    
    return 0;
}