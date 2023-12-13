#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int solve(vector<int>& arr,int ind,int buy,int n,int fee,vector<vector<int>>& dp){
    if(ind == n){
        return 0;
    }

    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }

    int profit;

    if(buy == 0){
        profit = max(0+solve(arr,ind+1,0,n,fee,dp),-arr[ind]+solve(arr,ind+1,1,n,fee,dp));
    }

    if(buy == 1){
        profit =  max(0+solve(arr,ind+1,1,n,fee,dp),arr[ind]-fee+solve(arr,ind+1,0,n,fee,dp));
    }

    return dp[ind][buy] = profit;   
}

int maximumProfit(int n,int fee,vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(2,-1));

    if(n == 0){
        return 0;
    }

    int ans = solve(arr,0,0,n,fee,dp);
    return ans;
}
 
int main(){
    
    return 0;
}