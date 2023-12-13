#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int solve(int ind,int N,vector<int>& price,vector<vector<int>>& dp){
    if(ind == 0){
        return N*price[0];
    }

    if(dp[ind][N] != -1){
        return dp[ind][N];
    }

    int notTake = 0+solve(ind-1,N,price,dp);
    int take = INT_MIN;

    int rodLength = ind+1;

    if(rodLength <= N){
        take = price[ind]+solve(ind,N-rodLength,price,dp);
    }

    return dp[ind][N] = max(take,notTake);

}

int cutRod(vector<int>& price,int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(n-1,n,price,dp);
}
 
int main(){
    
    return 0;
}