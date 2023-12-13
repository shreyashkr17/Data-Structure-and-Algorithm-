#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if((j-i) == 0 || (j-i) == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }

        for(int j = 0;j<n;j++){
            for(int i=0;i<n;i++){
                if((j-i) > 1){
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }

        int start = 0;
        int maxi = 1;
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(dp[i][j] == 1){
                    if(maxi <= j-i+1){
                        maxi = j-i+1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start,maxi);
    }
};