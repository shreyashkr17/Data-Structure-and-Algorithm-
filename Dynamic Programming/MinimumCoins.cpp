#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int ind,int T,vector<int> &nums,vector<vector<int>>& dp){
    if(ind == 0){
        if(T%nums[0] == 0){
            return T/nums[0];
        }
    }

    if(dp[ind][T] != -1){
        return dp[ind][T];
    }

    int notTake = 0+f(ind-1,T,nums,dp);
    int take = INT_MAX;
    if(nums[ind] <= T){
        take = 1+f(ind,T-nums[ind],nums,dp);
    }

    return dp[ind][T] = min(take,notTake);
}

int minimumElements(vector<int>& nums,int target){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int nas =  f(n-1,target,nums,dp);
    if(nas >= 1e9){
        return -1;
    } 
    return nas;
}
 
int main(){
    
    return 0;
}