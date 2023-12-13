#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int editDistanceUtils(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
    if( i < 0){
        return j+1;
    }

    if(j<0){
        return i+1;
    }

    if(dp[i][j]!= -1){
        return dp[i][j];
    } 

    if(s1[i] == s2[j]){
        return dp[i][j] = 0+editDistanceUtils(s1,s2,i-1,j-1,dp);
    }else{
        return dp[i][j] = 1+min(editDistanceUtils(s1,s2,i-1,j-1,dp),min(editDistanceUtils(s1,s2,i-1,j,dp),editDistanceUtils(s1,s2,i,j-1,dp)));
    }
}

int editDistance(string& s1, string& s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));

    return editDistanceUtils(s1,s2,n-1,m-1,dp);
}
 
int main(){
    
    return 0;
}