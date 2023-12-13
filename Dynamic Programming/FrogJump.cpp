#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

// Time Complexity: O(n)
// Space Complexity: O(n)

int f(int ind,vector<int> &heights,vector<int>& dp){
    if(ind == 0){
        return 0;
    }

    if(dp[ind] = -1){
        return dp[ind];
    }

    int left = f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);

    int right = INT_MAX;

    if(ind > 1){
        right = f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    }

    return min(left,right);
}

int frogJump(int n,vector<int>& heights){
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}
 
int main(){
    
    return 0;
}