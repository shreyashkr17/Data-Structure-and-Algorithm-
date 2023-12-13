#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int f(int i,int j,string &s,string &t, vector<vector<int>> &dp){
    if(i < 0 || j<0 ){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == t[j]){
        f(i-1,j-1,s,t,dp)+1;
    }

    return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}

int lcs(string s,string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));

    return f(n,m,s,t,dp);
}
 
int main(){
    
    return 0;
}