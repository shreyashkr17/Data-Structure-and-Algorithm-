#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

bool f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }

    if(ind == 0){
        return (arr[0] == target);
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    bool notTake = f(ind-1,target,arr,dp);
    bool take = false;

    if(arr[ind] <= target){
        take = f(ind-1,target-arr[ind],arr,dp);
    }

    return dp[ind][target] = take|notTake;
}

bool subsetSumToK(int n,int k,vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

bool canPartition(vector<int> &arr,int n){
    int totSum = 0;
    for(int i =0;i<n;i++){
        totSum+=arr[i];
    }

    if(totSum%2){
        return false;
    }

    int target = totSum/2;

    return subsetSumToK(n,target,arr);
}
 
int main(){
    
    return 0;
}