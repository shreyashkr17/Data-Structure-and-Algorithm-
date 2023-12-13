#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int findwaysUtil(int ind, int target,vector<int>& arr,vector<vector<int>>& dp){
    if(ind == 0){
        if(target == 0 && arr[0] = 0){
            return 2;
        }
        if(target == 0 || target == arr[0]){
            return 1;
        }
        return 0;
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    int notTaken = findwaysUtil(ind-1,target,arr,dp);

    int taken = 0;
    if(arr[ind] <= target){
        taken = findwaysUtil(ind-1,target-arr[ind],arr,dp);
    }

    return dp[ind][target] = notTaken+taken;
}

int findWays(vector<int>& num,int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findwaysUtil(n-1,k,num,dp);
}
 
int main(){
    
    return 0;
}