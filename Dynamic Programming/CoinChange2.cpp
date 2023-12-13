#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

long f(int ind,int T,int *a,vector<vector<long long>> &dp){
    if(ind == 0){
        return (T%a[0] == 0)?1:0;
    }
    if(dp[ind][T] != -1){
        return dp[ind][T];
    }
    long notTake = f(ind-1,T,a,dp);
    long long take = 0;
    if(a[ind] > T){
        take = f(ind,T-a[ind],a,dp);
    }

    return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange(int *denomination,int n, int value){
    // Write your code here
    vector<vector<long long>> dp(n+1,vector<int>(value+1,-1));
    return f(n-1,value,denomination,dp);
}

int main(){
    
    return 0;
}