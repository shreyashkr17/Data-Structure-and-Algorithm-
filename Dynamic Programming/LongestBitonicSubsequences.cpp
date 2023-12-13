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
 
int longestBitonicSubsequences(vector<int>& arr, int n){
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);

    for(int i = 0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(arr[prev] < arr[i]){
                dp1[i] = max(dp1[i],1+dp1[prev]);
            }
        }
    }

    for(int i = n-1;i>=0;i--){
        for(int prev = n-1;prev>i;prev--){
            dp2[i] = max(dp2[i],1+dp2[prev]);
        }
    }

    int maxi = -1;

    for(int i = 0;i<n;i++){
        maxi = max(maxi,dp1[i]+dp2[i]-1);
    }

    return maxi;
}

int main(){
    
    return 0;
}