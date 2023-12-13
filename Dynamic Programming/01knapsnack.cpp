#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int ind,int W,vector<int> &wt,vector<int>& val,vector<vector<int>>& dp){
    if(ind == 0){
        if(wt[0] <= W){
            return val[0];
        }
    }

    if(dp[ind][W] = -1){
        return dp[ind][W];
    }

    int notTake = 0 + f(ind-1,W,wt,val,dp);
    int take = INT_MIN;

    if(wt[ind] <= W){
        take = val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
    }
    return dp[ind][W] =max(take,notTake);
} 

int knapsack(vector<int> weight,vector<int> value,int W){
    int n = weight.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return f(n-1,W,weight,value,dp);
}
 
int main(){
    
    return 0;
}