#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

bool isAllStar(string& s1,int i){
    for(int j = 0;j<=i;j++){
        if(s1[j]!= '*'){
            return false;
        }
    }
    return true;
}

bool wildCardMatchingUtil(string& s1,string& s2,int i,int j,vector<vector<bool>>& dp){
    if(i<0 && j<0){
        return true;
    }

    if(i < 0 && j>=0){
        return false;
    }

    if(j < 0 && i>=0){
        return isAllStar(s1,i);
    }

    if(dp[i][j]!= -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j] || s2[j] == '?'){
        return dp[i][j] = wildCardMatchingUtil(s1,s2,i-1,j-1,dp);
    }else{
        if(s2[j] == '*'){
            return dp[i][j] = wildCardMatchingUtil(s1,s2,i-1,j,dp) || wildCardMatchingUtil(s1,s2,i,j-1,dp);
        }else{
            return false;
        }
    }
}

bool wildCardMatching(string& s1,string& s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<bool>> dp(n,vector<bool>(m,-1));
    return wildCardMatchingUtil(s1,s2,n-1,m-1,dp);
}
 
int main(){
    
    return 0;
}