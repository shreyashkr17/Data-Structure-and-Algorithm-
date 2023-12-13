#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int ind,int prevInd,vector<int>& arr,int n,vector<vector<int>>& dp){
    if(ind == n){
        return 0;
    }

    if(dp[ind][prevInd+1]!=-1){
        dp[ind][prevInd+1];
    }

    int len = 0+f(ind+1,prevInd,arr,n,dp);
    if(prevInd == -1 || arr[ind] > arr[prevInd]){
        len = max(len,1+f(ind+1,ind,arr,n,dp));
    }
    return len;
}

int longestIncreasingSubsequences(vector<int>& arr, int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}



// Tabulation Method
// TIme Complexity: O(n^2)
vector<int> longestIncreasingSubsequence(const vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  
    vector<int> hash(n, -1);  

    int maxLength = 1;  
    int endIndex = 0;   

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }

        if (dp[i] > maxLength) {
            maxLength = dp[i];
            endIndex = i;
        }
    }

    
    vector<int> result;
    while (endIndex != -1) {
        result.push_back(arr[endIndex]);
        endIndex = hash[endIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}



// Using BinarySearch  (Not generating the LIS, just for generating the length of LIS)
// Time Complexity: O(nlogn)
int longestIncreasingSubsequences(vector<int>& arr, int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int ind = 1;ind<n;ind++){
        if(arr[ind] > temp.back()){
            temp.push_back(arr[ind]);
            len++;
        }else{
            int lowInd = lower_bound(temp.begin(),temp.end(),arr[ind])-temp.begin();
            temp[lowInd] = arr[ind];
        }
    }
    return len;
}


int main(){
    
    return 0;
}