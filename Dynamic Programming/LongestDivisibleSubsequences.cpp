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

vector<int> longestIncreasingSubsequence(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  
    vector<int> hash(n, -1);  

    int maxLength = 1;  
    int endIndex = 0; 
    sort(arr.begin(),arr.end());  

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((arr[i] % arr[j]==0) && dp[i] < dp[j] + 1) {
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
 
int main(){
    
    return 0;
}