#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long


// In this we can buy and sell stocks multiple times, but as in previous We Can only buy and sell stock only one time, and the condition is like this :
// buy -> sell -> buy -> sell
// we cant do like this : buy-> buy-> sell-> sell



long f(int ind,int buy,long* values,int n,vector<vector<int>>& dp){
    if(ind == n){
        return 0;
    }

    long profit = 0;

    if(buy){
        profit = max(-values[ind]+f(ind+1,0,values,n,dp), 0+f(ind+1,0,values,n,dp));
    }else{
        profit = max(values[ind]+f(ind+1, 1,values,n,dp),0+f(ind+1,0,values,n,dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values,int n){
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,values,n,dp);
}
 
int main(){
    
    return 0;
}