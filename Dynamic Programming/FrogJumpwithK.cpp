#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

// Time Complexity: O(n*k)
// Space Complexity: O(n)

int solveUtil(int ind,vector<int>& heights,vector<int>& dp,int k){
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }

    int mmSteps = INT_MAX;

    for(int j = 1;j<=k;j++){
        if(ind-j>=0){
            int jump = solveUtil(ind-j,heights,dp,k)+abs(heights[ind]-heights[ind-j]);
            mmSteps = min(jump,mmSteps);
        }
        return dp[ind] = mmSteps;
    }
}

int solve(int n,vector<int>& heights,int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1,heights,dp,k);
}