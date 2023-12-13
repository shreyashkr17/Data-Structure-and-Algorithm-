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

// Time Complexity: O(nlogn + n^2*l) l is the average length of the string

bool checkPossible(string& s1, string& s2){
    if(s1.size() != s2.size()+1){
        return false;
    }
    int first = 0;
    int second = 0;

    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first++;
            second++;
        }else{
            first++;
        }
    }

    if(first == s1.size() && second == s2.size()){
        return true;
    }
    return false;
}

int longestChainStr(vector<string>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end(),[](string& s1, string& s2){
        return s1.size() < s2.size();
    });
    vector<int> dp(n,1),hash(n);
    int maxi = 1;
    for(int i =0;i<n;i++){
        hash[i] = i;
        for(int prev = 0;prev<i;prev++){
            // hash[i] = i;
            for(int prev = 0;prev<i;prev++){
                if(checkPossible(arr[i],arr[i+1]) && 1+dp[prev] >  dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] >  maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
}

int main(){
    
    return 0;
}