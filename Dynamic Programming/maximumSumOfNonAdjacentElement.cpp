#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

// Time complexity: O(n)
// Space Complexity: O(n)

int f(int ind,vector<int>& nums,vector<int>& dp){
    if(ind == 0){
        return nums[ind];
    }
    if(ind < 0){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    int pick = nums[ind]+f(ind-2,nums,dp);
    int nonPick = 0+f(ind-1,nums,dp);

    return dp[ind] = max(pick,nonPick);
}

int maximumNonAdjacent(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    return f(n-1,nums,dp);
}
 
int main(){
    
    return 0;
}