#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

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

int maximumSumOfNonAdjacentSum(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    return f(n-1,nums,dp);
}

long long int houseRobber(vector<int>& valuesInHouse){
    int n = valuesInHouse.size();
    
    if(n==1){
        return valuesInHouse[0];
    }
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(valuesInHouse[i]);
        }
        if(i!=n-1){
            temp2.push_back(valuesInHouse[i]);
        }
    }

    return max(maximumSumOfNonAdjacentSum(temp1),maximumSumOfNonAdjacentSum(temp2));
}
 
int main(){
    
    return 0;
}