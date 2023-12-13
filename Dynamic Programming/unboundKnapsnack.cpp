#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int solve(vector<vector<int>>& dp,int ind,int n,int w,vector<int>& val,vector<int>& wt){
    if(ind == 0){
        return ((int)(w/wt[0]))*val[0];
    }

    if(dp[ind][w] != -1){
        return dp[ind][w];
    }

    int notTake = 0+solve(dp,ind-1,n,w,val,wt);
    int take = 0;

    if(wt[ind] <= w){
        take = val[ind]+solve(dp,ind,n,w,val,wt);
    }
    return dp[ind][w] = max(take,notTake);
}

int unboundKnapsnack(int n,int w,vector<int>& val,vector<int>& wt){
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return solve(dp,n-1,n,w,val,wt); 
}
 
int main(){
    
    return 0;
}