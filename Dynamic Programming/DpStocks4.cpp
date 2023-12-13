#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int solve(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>& dp){
    if(ind == n || cap == 0){
        return 0;
    }

    if(dp[ind][buy][cap] != -1){
        return dp[ind][buy][cap];
    }

    int profit;

    if(buy == 1){
        profit = max(-prices[ind] + solve(ind+1,0,cap-1,prices,n,dp),solve(ind+1,0,cap,prices,n,dp));
    }

    profit = max(prices[ind]+solve(ind+1,1,cap,prices,n,dp),solve(ind+1,0,cap,prices,n,dp));

    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices,int k){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return solve(0,1,k,prices,n,dp);
}
 
int main(){
    
    return 0;
}