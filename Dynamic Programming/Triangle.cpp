#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    if(i == n-1){
        return triangle[n-1][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int down = triangle[i][j]+f(i+1,j,triangle,n,dp);
    int dg = triangle[i][j]+f(i+1,j+1,triangle,n,dp);

    return dp[i][j] = min(down,dg);
}

int minimumPathSum(vector<vector<int>>& triangle,int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}



// Second way

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int j = 0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i =n-2;i>=0;i--){
        for(int j = i;j>=0;j--){
            int d = triangle[i][j]+dp[i+1][j];
            int dg = triangle[i][j]+dp[i+1][j+1];
            dp[i][j] = min(d,dg);
        }
    }

    return dp[0][0];
}
 
int main(){
    
    return 0;
}