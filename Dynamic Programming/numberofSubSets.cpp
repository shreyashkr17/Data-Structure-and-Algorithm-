#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int ind,int sum, vector<int> &num,vector<vector<int>> &dp){
    if(sum == 0){
        return 1;
    }
    if(ind == 0){
        return num[0] == sum;
    }

    // if(ind == 0){
    //     if(sum == 0 && num[0] == 0){
    //         return 2;
    //     }
    //     if(sum == 0 || sum == num[0]){
    //         return 1;
    //     }
    //     return 0;
    // }

    if(dp[ind][sum] != -1){
        return dp[ind][sum];
    }

    int notTake = f(ind-1,sum,num,dp);

    int take = 0;
    if(num[ind] <= sum){
        take = f(ind-1,sum-num[ind],num,dp);
    }

    return dp[ind][sum] = take+notTake;
}

int findWays(vector<int>& num,int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));

    return f(n-1,tar,num,dp);
}
 
int main(){
    
    return 0;
}