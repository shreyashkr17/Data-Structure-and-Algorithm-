#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int minSubsetSumDifference(vector<int>& arr,int n){
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }

    int k = totSum;

    vector<vector<bool>> dp(n,vector<int>(k+1,0));

    for(int i =0;i<n;i++){
        dp[i][0] = true;
    }

    if(arr[0] <= k){
        dp[0][arr[0]] = true;
    }

    for(int ind = 1;ind < n;ind++){
        for(int target = 1;target<=k;target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target){
                take = dp[ind-1][target-arr[ind]];
            }

            dp[ind][target] = take|notTake;
        }
    }

    int mini = 1e9;
    for(int s1 = 0;s1<=totSum/2;s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini, (totSum-s1)-s1);
        }
    }

    return mini;
}
 
int main(){
    
    return 0;
}